# Gear Icon Maker - GUI for gear_icons.py
# Renders arsenal/inventory pictures for ADFRC gear and weapons from the MLOD models, converts them
# to PAA and points each class at its own icon.
# Author: IsoBones & Contributors
# License: MIT
#
# Needs Python 3 (the "py" launcher or "python" on PATH), Blender 4.x/5.x and Arma 3 Tools (ImageToPAA).
# Launch with GearIcons.bat (double-click). See README.md.

Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing
[System.Windows.Forms.Application]::EnableVisualStyles()

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$coreScript = Join-Path $scriptDir 'gear_icons.py'
$dumpScript = Join-Path $scriptDir 'dump_gear.sqf'
$reqFile = Join-Path $scriptDir 'requirements.txt'
$settingsDir = Join-Path $env:APPDATA 'ADFRC'
$settingsFile = Join-Path $settingsDir 'gear_icons_gui.json'
$categories = @('headgear', 'nvg', 'glasses', 'vest', 'uniform', 'backpack', 'weapon', 'attachment', 'magazine')
$script:proc = $null
$script:cancelled = $false
$script:looks = @{}
$env:PYTHONIOENCODING = 'utf-8'   # child Python writes UTF-8 to the log files

# ============ Find Python ============
$python = $null
$pythonArgs = @()
if (Get-Command py -ErrorAction SilentlyContinue) { $python = 'py'; $pythonArgs = @('-3') }
elseif (Get-Command python -ErrorAction SilentlyContinue) { $python = 'python' }

# ============ Form ============
$form = New-Object System.Windows.Forms.Form
$form.Text = 'Gear Icon Maker'
$form.Size = New-Object System.Drawing.Size(1010, 960)
$form.StartPosition = 'CenterScreen'
$form.FormBorderStyle = 'FixedDialog'
$form.MaximizeBox = $false

$labelFont = New-Object System.Drawing.Font("Segoe UI", 9)
$titleFont = New-Object System.Drawing.Font("Segoe UI", 9, [System.Drawing.FontStyle]::Bold)
$bigFont = New-Object System.Drawing.Font("Segoe UI", 10, [System.Drawing.FontStyle]::Bold)
$grey = [System.Drawing.Color]::DimGray

function New-Ctl {
    param([string]$Type, [int]$X, [int]$Y, [int]$Wd, [int]$Ht, [string]$Text = '', $Font = $labelFont, $Parent = $form)
    $c = New-Object "System.Windows.Forms.$Type"
    $c.Location = New-Object System.Drawing.Point($X, $Y)
    $c.Size = New-Object System.Drawing.Size($Wd, $Ht)
    if ($Text) { $c.Text = $Text }
    $c.Font = $Font
    $Parent.Controls.Add($c)
    return $c
}

$yPos = 10

# ============ Setup ============
$grpSetup = New-Ctl 'GroupBox' 15 $yPos 965 120 'Setup (saved for next time)' $titleFont
New-Ctl 'Label' 12 26 110 20 'Build folder (P:):' -Parent $grpSetup | Out-Null
$txtRoot = New-Ctl 'TextBox' 125 23 600 25 -Parent $grpSetup
$btnRoot = New-Ctl 'Button' 735 22 100 26 'Browse...' -Parent $grpSetup
$btnDetect = New-Ctl 'Button' 845 22 105 87 'Detect tools' $titleFont -Parent $grpSetup
New-Ctl 'Label' 12 56 110 20 'Blender:' -Parent $grpSetup | Out-Null
$txtBlender = New-Ctl 'TextBox' 125 53 600 25 -Parent $grpSetup
$btnBlender = New-Ctl 'Button' 735 52 100 26 'Browse...' -Parent $grpSetup
New-Ctl 'Label' 12 86 110 20 'ImageToPAA:' -Parent $grpSetup | Out-Null
$txtI2P = New-Ctl 'TextBox' 125 83 600 25 -Parent $grpSetup
$btnI2P = New-Ctl 'Button' 735 82 100 26 'Browse...' -Parent $grpSetup
$yPos += 128

# ============ Step 1: dump ============
$grpDump = New-Ctl 'GroupBox' 15 $yPos 965 82 '1. Dump the gear list from the game' $titleFont
$lblDumpHelp = New-Ctl 'Label' 12 22 940 20 'Load the mod, open any mission in Eden, Play (singleplayer), open the debug console, paste the script and press LOCAL EXEC. Then come back here and paste.' -Parent $grpDump
$lblDumpHelp.ForeColor = $grey
$btnCopyDump = New-Ctl 'Button' 12 46 190 27 'Copy dump script' -Parent $grpDump
$btnPasteDump = New-Ctl 'Button' 212 46 230 27 'Paste dump from clipboard' $titleFont -Parent $grpDump
$lblDump = New-Ctl 'Label' 455 51 495 20 'No dump yet.' -Parent $grpDump
$yPos += 90

# ============ Step 2: find ============
$grpFind = New-Ctl 'GroupBox' 15 $yPos 965 82 '2. Find the classes that need an icon' $titleFont
$chkCats = @{}
$x = 12
foreach ($c in $categories) {
    $cb = New-Ctl 'CheckBox' $x 22 98 22 $c -Parent $grpFind
    $cb.Checked = $true
    $chkCats[$c] = $cb
    $x += 103
}
$chkAll = New-Ctl 'CheckBox' 12 50 300 22 'Redo items that already have their own icon' -Parent $grpFind
$chkNoShared = New-Ctl 'CheckBox' 320 50 330 22 'Skip items that share an icon with other classes' -Parent $grpFind
$btnFind = New-Ctl 'Button' 800 47 150 27 'Find classes' $titleFont -Parent $grpFind
$yPos += 90

# ============ List + preview ============
New-Ctl 'Label' 15 $yPos 700 20 '3. Tick what to render. Click a row to see its icon (green = rendered).' $titleFont | Out-Null
$yPos += 22
$lv = New-Ctl 'ListView' 15 $yPos 690 285
$lv.View = 'Details'; $lv.CheckBoxes = $true; $lv.FullRowSelect = $true; $lv.GridLines = $true; $lv.HideSelection = $false
[void]$lv.Columns.Add('Class', 250)
[void]$lv.Columns.Add('Type', 75)
[void]$lv.Columns.Add('Why', 140)
[void]$lv.Columns.Add('Name', 200)

$pic = New-Object System.Windows.Forms.PictureBox
$pic.Location = New-Object System.Drawing.Point(715, $yPos)
$pic.Size = New-Object System.Drawing.Size(265, 200)
$pic.SizeMode = 'Zoom'
$pic.BorderStyle = 'FixedSingle'
$pic.BackColor = [System.Drawing.Color]::FromArgb(70, 72, 76)
$form.Controls.Add($pic)
$lblPic = New-Ctl 'Label' 715 ($yPos + 205) 265 40 'Click a row.'
$lblPic.ForeColor = $grey
$btnSheet = New-Ctl 'Button' 715 ($yPos + 250) 265 30 'Open contact sheet (all renders)'
$yPos += 292

$btnAll = New-Ctl 'Button' 15 $yPos 110 25 'Select all'
$btnNone = New-Ctl 'Button' 135 $yPos 110 25 'Select none'
$btnRendered = New-Ctl 'Button' 255 $yPos 160 25 'Select rendered only'
$lblCount = New-Ctl 'Label' 425 ($yPos + 4) 280 20 ''
$lblCount.TextAlign = 'TopRight'
$yPos += 35

# ============ Actions ============
$btnRender = New-Ctl 'Button' 15 $yPos 380 38 '4. Render ticked' $bigFont
$btnRender.BackColor = [System.Drawing.Color]::FromArgb(0, 120, 215)
$btnRender.ForeColor = [System.Drawing.Color]::White
$btnRender.FlatStyle = 'Flat'
$btnApply = New-Ctl 'Button' 405 $yPos 380 38 '5. Put ticked icons into the mod' $bigFont
$btnApply.BackColor = [System.Drawing.Color]::FromArgb(16, 124, 16)
$btnApply.ForeColor = [System.Drawing.Color]::White
$btnApply.FlatStyle = 'Flat'
$btnCancel = New-Ctl 'Button' 795 $yPos 185 38 'Cancel'
$btnCancel.Enabled = $false
$yPos += 48

# ============ Log ============
New-Ctl 'Label' 15 $yPos 400 20 'Output Log:' $titleFont | Out-Null
$btnWork = New-Ctl 'Button' 830 ($yPos - 3) 150 24 'Open work folder'
$yPos += 22
$txtLog = New-Ctl 'TextBox' 15 $yPos 965 140 '' (New-Object System.Drawing.Font("Consolas", 8))
$txtLog.Multiline = $true; $txtLog.ScrollBars = 'Vertical'; $txtLog.ReadOnly = $true
$txtLog.BackColor = [System.Drawing.Color]::FromArgb(240, 240, 240)

# ============ Helpers ============
function Write-Log {
    param([string]$Message)
    $txtLog.AppendText("$Message`r`n")
    $txtLog.SelectionStart = $txtLog.Text.Length
    $txtLog.ScrollToCaret()
    [System.Windows.Forms.Application]::DoEvents()
}

function Show-Msg {
    param([string]$Text, [string]$Icon = 'Information', [string]$Buttons = 'OK')
    return [System.Windows.Forms.MessageBox]::Show($Text, 'Gear Icon Maker', $Buttons, $Icon)
}

function Get-Root {
    $r = $txtRoot.Text.Trim()
    if ($r.EndsWith('\')) { $r = $r + '.' }      # "P:\" would escape the closing quote on the command line
    return $r
}
function Get-Work { return (Join-Path (Get-Root) 'temp\gear_icons') }

function Quote-Arg {
    param([string]$A)
    if ($A.EndsWith('\')) { $A = $A + '\' }
    return '"' + ($A -replace '"', '\"') + '"'
}

function Save-Settings {
    try {
        if (-not (Test-Path -LiteralPath $settingsDir)) { [void](New-Item -ItemType Directory -Path $settingsDir) }
        @{ root = $txtRoot.Text.Trim(); blender = $txtBlender.Text.Trim(); imagetopaa = $txtI2P.Text.Trim() } |
            ConvertTo-Json | Set-Content -LiteralPath $settingsFile -Encoding UTF8
    } catch { }
}

function Read-NewText {
    # returns text appended to $Path since the last call ($State holds the position)
    param([string]$Path, [hashtable]$State)
    if (-not (Test-Path -LiteralPath $Path)) { return '' }
    $fs = [System.IO.File]::Open($Path, 'Open', 'Read', 'ReadWrite')
    try {
        if ($fs.Length -le $State.Pos) { return '' }
        [void]$fs.Seek($State.Pos, 'Begin')
        $buf = New-Object byte[] ($fs.Length - $State.Pos)
        $n = $fs.Read($buf, 0, $buf.Length)
        $State.Pos += $n
        return [System.Text.Encoding]::UTF8.GetString($buf, 0, $n)
    } finally { $fs.Close() }
}

function Invoke-Core {
    # Runs gear_icons.py without freezing the window. Lines are logged as they arrive, except the
    # machine-readable ones (NEED|, TOOL|), which are returned. Returns @{ Lines; Code }.
    param([string[]]$CoreArgs, [bool]$Quiet = $false)
    $outF = [System.IO.Path]::GetTempFileName()
    $errF = [System.IO.Path]::GetTempFileName()
    $all = @($pythonArgs) + @('-u', $coreScript, '--root', (Get-Root)) + $CoreArgs
    $argLine = ($all | ForEach-Object { Quote-Arg $_ }) -join ' '
    $script:cancelled = $false
    $p = Start-Process -FilePath $python -ArgumentList $argLine -RedirectStandardOutput $outF -RedirectStandardError $errF -WindowStyle Hidden -PassThru
    [void]$p.Handle   # keeps ExitCode readable after exit
    $script:proc = $p
    $btnCancel.Enabled = $true
    $lines = New-Object System.Collections.ArrayList
    $states = @{ $outF = @{ Pos = 0; Part = '' }; $errF = @{ Pos = 0; Part = '' } }
    $pump = {
        param([bool]$Final)
        foreach ($f in @($outF, $errF)) {
            $st = $states[$f]
            $txt = $st.Part + (Read-NewText $f $st)
            $parts = $txt -split "`r?`n"
            $st.Part = if ($Final) { '' } else { $parts[-1] }
            $take = if ($Final) { $parts } else { $parts[0..($parts.Count - 2)] }
            if ($parts.Count -eq 1 -and -not $Final) { $take = @() }
            foreach ($l in $take) {
                if ($l -eq '') { continue }
                if ($l -match '^(NEED|TOOL)\|') { [void]$lines.Add($l) }
                elseif (-not $Quiet -and $l -notmatch 'DeprecationWarning|use_nodes = True') { Write-Log $l }
            }
        }
    }
    while (-not $p.HasExited) {
        & $pump $false
        [System.Windows.Forms.Application]::DoEvents()
        Start-Sleep -Milliseconds 120
    }
    & $pump $true
    $script:proc = $null
    $btnCancel.Enabled = $false
    Remove-Item -LiteralPath $outF, $errF -ErrorAction SilentlyContinue
    $code = if ($script:cancelled) { -1 } else { $p.ExitCode }
    return @{ Lines = $lines; Code = $code }
}

function Set-Busy {
    param([bool]$Busy)
    foreach ($c in @($btnRender, $btnApply, $btnFind, $btnPasteDump, $btnCopyDump, $btnDetect, $btnRoot, $btnBlender, $btnI2P, $btnAll, $btnNone, $btnRendered)) { $c.Enabled = -not $Busy }
    $form.Cursor = if ($Busy) { [System.Windows.Forms.Cursors]::WaitCursor } else { [System.Windows.Forms.Cursors]::Default }
}

function Get-Ticked {
    $t = @(); foreach ($it in $lv.Items) { if ($it.Checked) { $t += $it.Text } }
    return ,$t
}

function Update-Count {
    $t = 0; foreach ($it in $lv.Items) { if ($it.Checked) { $t++ } }
    $lblCount.Text = "$t of $($lv.Items.Count) ticked"
}

function Write-OnlyFile {
    param([string[]]$Classes)
    $f = Join-Path $env:TEMP 'adfrc_gear_icons_only.txt'
    [System.IO.File]::WriteAllLines($f, $Classes)
    return $f
}

function Load-Looks {
    # class (lower) -> rendered icon png, from the last render
    $script:looks = @{}
    $lj = Join-Path (Get-Work) 'stage\looks.json'
    if (-not (Test-Path -LiteralPath $lj)) { return }
    try { $data = Get-Content -LiteralPath $lj -Raw | ConvertFrom-Json } catch { return }
    foreach ($prop in $data.PSObject.Properties) {
        $png = Join-Path (Get-Work) ('icons\' + $prop.Name + '.png')
        if (Test-Path -LiteralPath $png) {
            foreach ($c in $prop.Value.classes) { $script:looks[$c.ToLower()] = $png }
        }
    }
}

function Update-Colours {
    foreach ($it in $lv.Items) {
        $it.ForeColor = if ($script:looks.ContainsKey($it.Text.ToLower())) { [System.Drawing.Color]::DarkGreen } else { [System.Drawing.Color]::Black }
    }
}

function Show-Preview {
    if ($pic.Image) { $pic.Image.Dispose(); $pic.Image = $null }
    if ($lv.SelectedItems.Count -eq 0) { $lblPic.Text = 'Click a row.'; return }
    $it = $lv.SelectedItems[0]
    $png = $script:looks[$it.Text.ToLower()]
    if ($png -and (Test-Path -LiteralPath $png)) {
        $ms = New-Object System.IO.MemoryStream(, [System.IO.File]::ReadAllBytes($png))
        $pic.Image = [System.Drawing.Image]::FromStream($ms)
        $lblPic.Text = "$($it.Text)`r`n$($pic.Image.Width)x$($pic.Image.Height)"
    } else {
        $lblPic.Text = "$($it.Text)`r`nNot rendered yet."
    }
}

function Update-DumpLabel {
    $d = Join-Path (Get-Work) 'gear_dump.txt'
    if (Test-Path -LiteralPath $d) {
        $n = @(Select-String -LiteralPath $d -Pattern 'ADFI\|' -SimpleMatch:$false).Count
        $lblDump.Text = "Dump: $n classes, saved $((Get-Item -LiteralPath $d).LastWriteTime.ToString('d MMM HH:mm'))"
        $lblDump.ForeColor = [System.Drawing.Color]::DarkGreen
    } else {
        $lblDump.Text = 'No dump yet.'
        $lblDump.ForeColor = [System.Drawing.Color]::DarkRed
    }
}

function Test-Root {
    $r = $txtRoot.Text.Trim()
    if (-not $r -or -not (Test-Path -LiteralPath $r -PathType Container)) {
        Show-Msg 'Set the build folder first (your P: drive, the folder with ADF_Gear, ADF_Weapons and so on in it).' 'Warning' | Out-Null
        return $false
    }
    if (-not (Get-ChildItem -LiteralPath $r -Directory -Filter 'ADF*' -ErrorAction SilentlyContinue)) {
        if ((Show-Msg "No ADF... addon folders in`r`n$r`r`n`r`nUse it anyway?" 'Warning' 'YesNo') -ne 'Yes') { return $false }
    }
    return $true
}

function Detect-Tools {
    param([bool]$Overwrite)
    $a = @('tools')
    if ($txtBlender.Text.Trim() -and -not $Overwrite) { $a += @('--blender', $txtBlender.Text.Trim()) }
    if ($txtI2P.Text.Trim() -and -not $Overwrite) { $a += @('--imagetopaa', $txtI2P.Text.Trim()) }
    $res = Invoke-Core $a $true
    $t = @{}
    foreach ($l in $res.Lines) { $p = $l -split '\|'; if ($p[0] -eq 'TOOL') { $t[$p[1]] = $p[2] } }
    if ($t['blender']) { $txtBlender.Text = $t['blender'] }
    if ($t['imagetopaa']) { $txtI2P.Text = $t['imagetopaa'] }
    if ($t['blender']) { Write-Log "Blender: $($t['blender'])" }
    elseif ($t['bpy']) { Write-Log 'Blender: using the bpy Python module.' }
    else { Write-Log 'Blender: NOT FOUND. Install Blender 4.x or 5.x from blender.org, or Browse to blender.exe.' }
    if ($t['imagetopaa']) { Write-Log "ImageToPAA: $($t['imagetopaa'])" }
    else { Write-Log 'ImageToPAA: NOT FOUND. Install Arma 3 Tools from Steam (only needed for step 5), or Browse to ImageToPAA.exe.' }
    return $t
}

function Get-ToolArgs {
    $a = @()
    if ($txtBlender.Text.Trim()) { $a += @('--blender', $txtBlender.Text.Trim()) }
    if ($txtI2P.Text.Trim()) { $a += @('--imagetopaa', $txtI2P.Text.Trim()) }
    return ,$a
}

function Pick-File {
    param([string]$Title, [string]$Filter, [System.Windows.Forms.TextBox]$Box)
    $fd = New-Object System.Windows.Forms.OpenFileDialog
    $fd.Title = $Title; $fd.Filter = $Filter
    if ($Box.Text -and (Test-Path -LiteralPath $Box.Text)) { $fd.InitialDirectory = Split-Path -Parent $Box.Text }
    if ($fd.ShowDialog() -eq 'OK') { $Box.Text = $fd.FileName; Save-Settings }
}

# ============ Events ============
$btnRoot.Add_Click({
    $fb = New-Object System.Windows.Forms.FolderBrowserDialog
    $fb.Description = 'Select the build folder (P: drive root)'
    $fb.ShowNewFolderButton = $false
    if (Test-Path -LiteralPath $txtRoot.Text) { $fb.SelectedPath = $txtRoot.Text }
    if ($fb.ShowDialog() -eq 'OK') { $txtRoot.Text = $fb.SelectedPath; Save-Settings; Update-DumpLabel; Load-Looks; Update-Colours }
})
$btnBlender.Add_Click({ Pick-File 'Find blender.exe' 'blender.exe|blender.exe|Programs|*.exe' $txtBlender })
$btnI2P.Add_Click({ Pick-File 'Find ImageToPAA.exe (Arma 3 Tools)' 'ImageToPAA.exe|ImageToPAA.exe|Programs|*.exe' $txtI2P })
$btnDetect.Add_Click({ Set-Busy $true; [void](Detect-Tools $true); Save-Settings; Set-Busy $false })

$btnCopyDump.Add_Click({
    [System.Windows.Forms.Clipboard]::SetText((Get-Content -LiteralPath $dumpScript -Raw))
    Write-Log 'Dump script copied. In game: debug console > paste > LOCAL EXEC. It copies the result to your clipboard; then press "Paste dump from clipboard" here.'
})

$btnPasteDump.Add_Click({
    if (-not (Test-Root)) { return }
    $txt = [System.Windows.Forms.Clipboard]::GetText()
    $n = ([regex]::Matches($txt, 'ADFI\|')).Count
    if ($n -eq 0) {
        Show-Msg "The clipboard doesn't have a gear dump in it.`r`n`r`nRun the dump script in game first (LOCAL EXEC), then press this straight away." 'Warning' | Out-Null
        return
    }
    $w = Get-Work
    if (-not (Test-Path -LiteralPath $w)) { [void](New-Item -ItemType Directory -Path $w) }
    [System.IO.File]::WriteAllText((Join-Path $w 'gear_dump.txt'), $txt, (New-Object System.Text.UTF8Encoding($false)))
    Write-Log "Saved $n classes to $(Join-Path $w 'gear_dump.txt')"
    Update-DumpLabel
})

$btnFind.Add_Click({
    if (-not (Test-Root)) { return }
    if (-not (Test-Path -LiteralPath (Join-Path (Get-Work) 'gear_dump.txt'))) { Show-Msg 'Do step 1 first (dump and paste).' 'Warning' | Out-Null; return }
    $cats = @($categories | Where-Object { $chkCats[$_].Checked })
    if ($cats.Count -eq 0) { Show-Msg 'Tick at least one gear type.' 'Warning' | Out-Null; return }
    Set-Busy $true
    $txtLog.Clear()
    $a = @('select', '--machine', '--categories') + $cats
    if ($chkAll.Checked) { $a += '--all' }
    if ($chkNoShared.Checked) { $a += '--no-shared' }
    $res = Invoke-Core $a
    $lv.BeginUpdate(); $lv.Items.Clear()
    foreach ($l in $res.Lines) {
        $p = $l -split '\|'
        if ($p[0] -ne 'NEED') { continue }
        $it = New-Object System.Windows.Forms.ListViewItem($p[1])
        [void]$it.SubItems.Add($p[2]); [void]$it.SubItems.Add($p[3]); [void]$it.SubItems.Add($p[5])
        $it.Checked = $true
        [void]$lv.Items.Add($it)
    }
    $lv.EndUpdate()
    Load-Looks; Update-Colours; Update-Count
    if ($lv.Items.Count -eq 0) { Write-Log 'Nothing needs an icon. Tick "Redo items that already have their own icon" to redo some anyway.' }
    else { Write-Log 'Untick anything you don''t want, then press 4. Render ticked.' }
    Set-Busy $false
})

$lv.Add_ItemChecked({ Update-Count })
$lv.Add_SelectedIndexChanged({ Show-Preview })
$btnAll.Add_Click({ foreach ($it in $lv.Items) { $it.Checked = $true } })
$btnNone.Add_Click({ foreach ($it in $lv.Items) { $it.Checked = $false } })
$btnRendered.Add_Click({ foreach ($it in $lv.Items) { $it.Checked = $script:looks.ContainsKey($it.Text.ToLower()) } })

$btnSheet.Add_Click({
    $s = Join-Path (Get-Work) 'contact_sheet.png'
    if (Test-Path -LiteralPath $s) { Start-Process -FilePath $s } else { Show-Msg 'Nothing rendered yet.' | Out-Null }
})
$btnWork.Add_Click({
    $w = Get-Work
    if (-not (Test-Path -LiteralPath $w)) { [void](New-Item -ItemType Directory -Path $w -Force) }
    Start-Process explorer.exe $w
})

$btnCancel.Add_Click({
    if ($script:proc -and -not $script:proc.HasExited) {
        $script:cancelled = $true
        & taskkill.exe /PID $script:proc.Id /T /F | Out-Null
        Write-Log 'Cancelled.'
    }
})

$btnRender.Add_Click({
    if (-not (Test-Root)) { return }
    $ticked = Get-Ticked
    if ($ticked.Count -eq 0) { Show-Msg 'Tick at least one class.' | Out-Null; return }
    if (-not $txtBlender.Text.Trim()) {
        $t = Detect-Tools $false
        if (-not $t['blender'] -and -not $t['bpy']) { Show-Msg 'Blender not found. Install Blender 4.x or 5.x from blender.org, or use Browse... next to Blender.' 'Warning' | Out-Null; return }
    }
    $secs = [int]($ticked.Count * 8)
    if ($ticked.Count -gt 20) {
        if ((Show-Msg "Render $($ticked.Count) classes? Roughly $([Math]::Ceiling($secs / 60)) minute(s)." 'Question' 'OKCancel') -ne 'OK') { return }
    }
    Set-Busy $true
    $txtLog.Clear()
    Save-Settings
    $f = Write-OnlyFile $ticked
    $res = Invoke-Core (@('all', '--only-file', $f) + (Get-ToolArgs))
    Load-Looks; Update-Colours; Show-Preview
    if ($res.Code -eq 0) {
        Write-Log '=========================================='
        Write-Log 'Rendered. Click rows to check each icon (or open the contact sheet), then press 5.'
    } elseif ($res.Code -ne -1) {
        Write-Log "FAILED (exit code $($res.Code)). See the lines above."
    }
    Set-Busy $false
})

$btnApply.Add_Click({
    if (-not (Test-Root)) { return }
    $ticked = @(Get-Ticked | Where-Object { $script:looks.ContainsKey($_.ToLower()) })
    $skipped = (Get-Ticked).Count - $ticked.Count
    if ($ticked.Count -eq 0) { Show-Msg 'None of the ticked classes are rendered yet. Press 4 first.' | Out-Null; return }
    if (-not $txtI2P.Text.Trim()) {
        $t = Detect-Tools $false
        if (-not $t['imagetopaa']) { Show-Msg 'ImageToPAA not found. Install Arma 3 Tools from Steam, or use Browse... next to ImageToPAA.' 'Warning' | Out-Null; return }
    }
    Set-Busy $true
    $txtLog.Clear()
    $f = Write-OnlyFile $ticked
    Write-Log 'Checking what would change...'
    $res = Invoke-Core (@('apply', '--only-file', $f) + (Get-ToolArgs))
    if ($res.Code -ne 0) { Write-Log "FAILED (exit code $($res.Code))."; Set-Busy $false; return }
    $msg = "Put $($ticked.Count) icon(s) into the mod and edit the configs (listed in the log)?"
    if ($skipped -gt 0) { $msg += "`r`n`r`n$skipped ticked class(es) aren't rendered yet and will be skipped." }
    $msg += "`r`n`r`nOriginal configs are copied to temp\gear_icons\config_backup first."
    if ((Show-Msg $msg 'Question' 'OKCancel') -ne 'OK') { Write-Log 'Nothing written.'; Set-Busy $false; return }
    Write-Log '=========================================='
    $res = Invoke-Core (@('apply', '--apply', '--only-file', $f) + (Get-ToolArgs))
    if ($res.Code -eq 0) {
        Write-Log '=========================================='
        Write-Log 'Done. Lint, pack and check the icons in the Arsenal. Commit the new .paa files and the edited configs.'
    } else {
        Write-Log "FAILED (exit code $($res.Code)). See the lines above."
    }
    Set-Busy $false
})

$form.Add_FormClosing({
    if ($script:proc -and -not $script:proc.HasExited) { & taskkill.exe /PID $script:proc.Id /T /F | Out-Null }
    Save-Settings
})

# ============ Startup ============
$form.Add_Shown({
    if (-not $python) {
        Write-Log 'ERROR: Python 3 not found. Install it from python.org (tick "Add python.exe to PATH") and reopen this window.'
        foreach ($c in @($btnRender, $btnApply, $btnFind, $btnDetect)) { $c.Enabled = $false }
        return
    }
    if (-not (Test-Path -LiteralPath $coreScript)) {
        Write-Log "ERROR: gear_icons.py not found next to this script ($scriptDir)."
        foreach ($c in @($btnRender, $btnApply, $btnFind, $btnDetect)) { $c.Enabled = $false }
        return
    }
    # saved settings, else ADFRC_ROOT / P:\
    if (Test-Path -LiteralPath $settingsFile) {
        try {
            $s = Get-Content -LiteralPath $settingsFile -Raw | ConvertFrom-Json
            $txtRoot.Text = $s.root; $txtBlender.Text = $s.blender; $txtI2P.Text = $s.imagetopaa
        } catch { }
    }
    if (-not $txtRoot.Text) {
        if ($env:ADFRC_ROOT) { $txtRoot.Text = $env:ADFRC_ROOT }
        elseif (Test-Path -LiteralPath 'P:\') { $txtRoot.Text = 'P:\' }
    }
    Set-Busy $true
    $t = Detect-Tools $false
    if (-not $t['numpy'] -or -not $t['PIL']) {
        if ((Show-Msg 'This tool needs the Python packages numpy and Pillow. Install them now?' 'Question' 'YesNo') -eq 'Yes') {
            Write-Log 'Installing numpy + Pillow...'
            foreach ($l in (& $python @pythonArgs -m pip install --user -r $reqFile 2>&1)) { Write-Log "   $l" }
        }
    }
    Save-Settings
    if ($txtRoot.Text) { Update-DumpLabel; Load-Looks }
    Write-Log 'Ready. Work through the steps top to bottom.'
    Set-Busy $false
})

[void]$form.ShowDialog()
