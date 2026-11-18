# Shadow LOD Maker - GUI for make_shadow_lods.py
# Adds Shadow Volume LODs to ADF Re-Cut gear p3ds (vests, helmets, packs).
# Author: IsoBones & Contributors
# License: MIT
#
# Needs Python 3 on PATH (the "py" launcher or "python") and make_shadow_lods.py
# in the same folder as this script. Launch with ShadowLODs.bat.

Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing
[System.Windows.Forms.Application]::EnableVisualStyles()

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$coreScript = Join-Path $scriptDir 'make_shadow_lods.py'
$backupDir = Join-Path $scriptDir 'temp\shadow_backups'

# ============ Find Python ============
$python = $null
$pythonArgs = @()
if (Get-Command py -ErrorAction SilentlyContinue) { $python = 'py'; $pythonArgs = @('-3') }
elseif (Get-Command python -ErrorAction SilentlyContinue) { $python = 'python' }

# ============ Form ============
$form = New-Object System.Windows.Forms.Form
$form.Text = 'Shadow LOD Maker'
$form.Size = New-Object System.Drawing.Size(820, 860)
$form.StartPosition = 'CenterScreen'
$form.FormBorderStyle = 'FixedDialog'
$form.MaximizeBox = $false

$labelFont = New-Object System.Drawing.Font("Segoe UI", 9)
$titleFont = New-Object System.Drawing.Font("Segoe UI", 9, [System.Drawing.FontStyle]::Bold)
$yPos = 15

# ============ Folder ============
$lblFolder = New-Object System.Windows.Forms.Label
$lblFolder.Location = New-Object System.Drawing.Point(20, $yPos)
$lblFolder.Size = New-Object System.Drawing.Size(770, 20)
$lblFolder.Text = 'Folder to scan for p3d models (build folder, or any addon folder inside it):'
$lblFolder.Font = $titleFont
$form.Controls.Add($lblFolder)
$yPos += 25

$txtFolder = New-Object System.Windows.Forms.TextBox
$txtFolder.Location = New-Object System.Drawing.Point(20, $yPos)
$txtFolder.Size = New-Object System.Drawing.Size(540, 25)
$txtFolder.Font = $labelFont
$txtFolder.Text = $scriptDir
$form.Controls.Add($txtFolder)

$btnBrowse = New-Object System.Windows.Forms.Button
$btnBrowse.Location = New-Object System.Drawing.Point(570, $yPos)
$btnBrowse.Size = New-Object System.Drawing.Size(100, 25)
$btnBrowse.Text = 'Browse...'
$btnBrowse.Font = $labelFont
$form.Controls.Add($btnBrowse)

$btnScan = New-Object System.Windows.Forms.Button
$btnScan.Location = New-Object System.Drawing.Point(680, $yPos)
$btnScan.Size = New-Object System.Drawing.Size(110, 25)
$btnScan.Text = 'Scan'
$btnScan.Font = $titleFont
$form.Controls.Add($btnScan)
$yPos += 35

# ============ Model list ============
$lblList = New-Object System.Windows.Forms.Label
$lblList.Location = New-Object System.Drawing.Point(20, $yPos)
$lblList.Size = New-Object System.Drawing.Size(770, 20)
$lblList.Text = 'Models (tick the ones to process):'
$lblList.Font = $titleFont
$form.Controls.Add($lblList)
$yPos += 22

$lvModels = New-Object System.Windows.Forms.ListView
$lvModels.Location = New-Object System.Drawing.Point(20, $yPos)
$lvModels.Size = New-Object System.Drawing.Size(770, 260)
$lvModels.View = 'Details'
$lvModels.CheckBoxes = $true
$lvModels.FullRowSelect = $true
$lvModels.GridLines = $true
$lvModels.Font = $labelFont
[void]$lvModels.Columns.Add('Model', 390)
[void]$lvModels.Columns.Add('Res LODs', 110)
[void]$lvModels.Columns.Add('View Pilot', 70)
[void]$lvModels.Columns.Add('Shadow LODs', 110)
[void]$lvModels.Columns.Add('LOD 1 faces', 80)
$form.Controls.Add($lvModels)
$yPos += 268

$btnAll = New-Object System.Windows.Forms.Button
$btnAll.Location = New-Object System.Drawing.Point(20, $yPos)
$btnAll.Size = New-Object System.Drawing.Size(120, 25)
$btnAll.Text = 'Select all'
$btnAll.Font = $labelFont
$form.Controls.Add($btnAll)

$btnNone = New-Object System.Windows.Forms.Button
$btnNone.Location = New-Object System.Drawing.Point(150, $yPos)
$btnNone.Size = New-Object System.Drawing.Size(120, 25)
$btnNone.Text = 'Select none'
$btnNone.Font = $labelFont
$form.Controls.Add($btnNone)

$btnMissing = New-Object System.Windows.Forms.Button
$btnMissing.Location = New-Object System.Drawing.Point(280, $yPos)
$btnMissing.Size = New-Object System.Drawing.Size(200, 25)
$btnMissing.Text = 'Select ones with no shadow'
$btnMissing.Font = $labelFont
$form.Controls.Add($btnMissing)
$yPos += 35

# ============ Options ============
$grpOpt = New-Object System.Windows.Forms.GroupBox
$grpOpt.Location = New-Object System.Drawing.Point(20, $yPos)
$grpOpt.Size = New-Object System.Drawing.Size(770, 120)
$grpOpt.Text = 'Options'
$grpOpt.Font = $titleFont
$form.Controls.Add($grpOpt)

$lblSource = New-Object System.Windows.Forms.Label
$lblSource.Location = New-Object System.Drawing.Point(15, 28)
$lblSource.Size = New-Object System.Drawing.Size(210, 20)
$lblSource.Text = 'Shadow 0 copied from Res LOD:'
$lblSource.Font = $labelFont
$grpOpt.Controls.Add($lblSource)

$numSource = New-Object System.Windows.Forms.NumericUpDown
$numSource.Location = New-Object System.Drawing.Point(230, 26)
$numSource.Size = New-Object System.Drawing.Size(55, 25)
$numSource.Minimum = 0; $numSource.Maximum = 10; $numSource.Value = 3
$numSource.Font = $labelFont
$grpOpt.Controls.Add($numSource)

$chkLow = New-Object System.Windows.Forms.CheckBox
$chkLow.Location = New-Object System.Drawing.Point(320, 26)
$chkLow.Size = New-Object System.Drawing.Size(235, 22)
$chkLow.Text = 'Shadow 10 (distance) from Res LOD:'
$chkLow.Font = $labelFont
$chkLow.Checked = $true
$grpOpt.Controls.Add($chkLow)

$numLow = New-Object System.Windows.Forms.NumericUpDown
$numLow.Location = New-Object System.Drawing.Point(560, 26)
$numLow.Size = New-Object System.Drawing.Size(55, 25)
$numLow.Minimum = 0; $numLow.Maximum = 10; $numLow.Value = 5
$numLow.Font = $labelFont
$grpOpt.Controls.Add($numLow)

$chkFirst = New-Object System.Windows.Forms.CheckBox
$chkFirst.Location = New-Object System.Drawing.Point(15, 58)
$chkFirst.Size = New-Object System.Drawing.Size(290, 22)
$chkFirst.Text = 'First-person copies (Shadow 1000/1010)'
$chkFirst.Font = $labelFont
$chkFirst.Checked = $true
$grpOpt.Controls.Add($chkFirst)

$lblShrink = New-Object System.Windows.Forms.Label
$lblShrink.Location = New-Object System.Drawing.Point(320, 60)
$lblShrink.Size = New-Object System.Drawing.Size(235, 20)
$lblShrink.Text = 'Shrink shadow inward (mm, 0 = off):'
$lblShrink.Font = $labelFont
$grpOpt.Controls.Add($lblShrink)

$numShrink = New-Object System.Windows.Forms.NumericUpDown
$numShrink.Location = New-Object System.Drawing.Point(560, 58)
$numShrink.Size = New-Object System.Drawing.Size(55, 25)
$numShrink.Minimum = 0; $numShrink.Maximum = 10; $numShrink.DecimalPlaces = 1
$numShrink.Increment = 0.5; $numShrink.Value = 0
$numShrink.Font = $labelFont
$grpOpt.Controls.Add($numShrink)

$chkReplace = New-Object System.Windows.Forms.CheckBox
$chkReplace.Location = New-Object System.Drawing.Point(15, 88)
$chkReplace.Size = New-Object System.Drawing.Size(290, 22)
$chkReplace.Text = 'Rebuild shadow LODs that already exist'
$chkReplace.Font = $labelFont
$grpOpt.Controls.Add($chkReplace)

$chkDry = New-Object System.Windows.Forms.CheckBox
$chkDry.Location = New-Object System.Drawing.Point(320, 88)
$chkDry.Size = New-Object System.Drawing.Size(300, 22)
$chkDry.Text = 'Dry run (report only, change nothing)'
$chkDry.Font = $labelFont
$grpOpt.Controls.Add($chkDry)
$yPos += 130

# ============ Action buttons ============
$btnRun = New-Object System.Windows.Forms.Button
$btnRun.Location = New-Object System.Drawing.Point(20, $yPos)
$btnRun.Size = New-Object System.Drawing.Size(560, 35)
$btnRun.Text = 'Make Shadow LODs for ticked models'
$btnRun.Font = New-Object System.Drawing.Font("Segoe UI", 10, [System.Drawing.FontStyle]::Bold)
$btnRun.BackColor = [System.Drawing.Color]::FromArgb(0, 120, 215)
$btnRun.ForeColor = [System.Drawing.Color]::White
$btnRun.FlatStyle = 'Flat'
$form.Controls.Add($btnRun)

$btnRestore = New-Object System.Windows.Forms.Button
$btnRestore.Location = New-Object System.Drawing.Point(590, $yPos)
$btnRestore.Size = New-Object System.Drawing.Size(200, 35)
$btnRestore.Text = 'Restore originals (ticked)'
$btnRestore.Font = $labelFont
$form.Controls.Add($btnRestore)
$yPos += 45

# ============ Log ============
$lblLog = New-Object System.Windows.Forms.Label
$lblLog.Location = New-Object System.Drawing.Point(20, $yPos)
$lblLog.Size = New-Object System.Drawing.Size(770, 20)
$lblLog.Text = 'Output Log:'
$lblLog.Font = $titleFont
$form.Controls.Add($lblLog)
$yPos += 22

$txtLog = New-Object System.Windows.Forms.TextBox
$txtLog.Location = New-Object System.Drawing.Point(20, $yPos)
$txtLog.Size = New-Object System.Drawing.Size(770, 150)
$txtLog.Multiline = $true
$txtLog.ScrollBars = 'Vertical'
$txtLog.ReadOnly = $true
$txtLog.Font = New-Object System.Drawing.Font("Consolas", 8)
$txtLog.BackColor = [System.Drawing.Color]::FromArgb(240, 240, 240)
$form.Controls.Add($txtLog)

# ============ Helpers ============
function Write-Log {
    param([string]$Message)
    $txtLog.AppendText("$Message`r`n")
    $txtLog.SelectionStart = $txtLog.Text.Length
    $txtLog.ScrollToCaret()
    $txtLog.Refresh()
    [System.Windows.Forms.Application]::DoEvents()
}

function Invoke-Core {
    # Runs make_shadow_lods.py from the scanned folder; returns its output lines.
    param([string[]]$CoreArgs)
    $root = $txtFolder.Text.Trim()
    Push-Location -LiteralPath $root
    try {
        $out = & $python @pythonArgs $coreScript @CoreArgs 2>&1
    } finally {
        Pop-Location
    }
    return $out | ForEach-Object { "$_" }
}

function Get-RelPath {
    param([string]$Root, [string]$Full)
    $r = (Resolve-Path -LiteralPath $Root).Path.TrimEnd('\') + '\'
    if ($Full.StartsWith($r, [System.StringComparison]::OrdinalIgnoreCase)) { return $Full.Substring($r.Length) }
    return $Full
}

function Get-Ticked {
    $items = @()
    foreach ($it in $lvModels.Items) { if ($it.Checked) { $items += $it } }
    return ,$items
}

function Set-Busy {
    param([bool]$Busy)
    foreach ($c in @($btnRun, $btnRestore, $btnScan, $btnBrowse, $btnAll, $btnNone, $btnMissing)) { $c.Enabled = -not $Busy }
    $form.Cursor = if ($Busy) { [System.Windows.Forms.Cursors]::WaitCursor } else { [System.Windows.Forms.Cursors]::Default }
}

function Update-Row {
    param($Item)
    $line = Invoke-Core @('--info', $Item.Tag) | Where-Object { $_ -like 'INFO|*' } | Select-Object -First 1
    if ($line) {
        $p = $line -split '\|'
        $Item.SubItems[1].Text = "$($p[2]): $($p[6])"
        $Item.SubItems[2].Text = $p[3]
        $Item.SubItems[3].Text = $p[4]
        $Item.SubItems[4].Text = $p[5]
    }
}

# ============ Events ============
$btnBrowse.Add_Click({
    $fb = New-Object System.Windows.Forms.FolderBrowserDialog
    $fb.Description = 'Select the folder to scan for p3d models'
    $fb.ShowNewFolderButton = $false
    if (Test-Path -LiteralPath $txtFolder.Text) { $fb.SelectedPath = $txtFolder.Text }
    if ($fb.ShowDialog() -eq 'OK') { $txtFolder.Text = $fb.SelectedPath }
})

$btnScan.Add_Click({
    $root = $txtFolder.Text.Trim()
    if (-not (Test-Path -LiteralPath $root -PathType Container)) {
        [System.Windows.Forms.MessageBox]::Show('Pick a folder that exists.', 'Shadow LOD Maker', 'OK', 'Error') | Out-Null
        return
    }
    Set-Busy $true
    $lvModels.Items.Clear()
    $txtLog.Clear()
    Write-Log "Scanning $root ..."
    # skip our own backup/temp folders and anything under a3 (vanilla data)
    $files = Get-ChildItem -LiteralPath $root -Filter '*.p3d' -Recurse -File -ErrorAction SilentlyContinue |
        Where-Object { $_.FullName -notmatch '\\(temp|_to_delete|a3)\\' }
    Write-Log "Found $($files.Count) p3d file(s). Reading LOD info..."
    $lvModels.BeginUpdate()
    foreach ($f in $files) {
        $rel = Get-RelPath $root $f.FullName
        $it = New-Object System.Windows.Forms.ListViewItem($rel)
        $it.Tag = $rel
        [void]$it.SubItems.Add('?'); [void]$it.SubItems.Add('?'); [void]$it.SubItems.Add('?'); [void]$it.SubItems.Add('?')
        [void]$lvModels.Items.Add($it)
    }
    $lvModels.EndUpdate()
    # read info in batches so the window stays responsive
    $batch = @(); $map = @{}
    foreach ($it in $lvModels.Items) { $map[$it.Tag.ToLower()] = $it }
    $all = @($lvModels.Items | ForEach-Object { $_.Tag })
    for ($i = 0; $i -lt $all.Count; $i += 8) {
        $chunk = $all[$i..([Math]::Min($i + 7, $all.Count - 1))]
        foreach ($line in (Invoke-Core (@('--info') + $chunk))) {
            if ($line -notlike 'INFO|*') { continue }
            $p = $line -split '\|'
            $it = $map[$p[1].ToLower()]
            if ($null -eq $it) { continue }
            $it.SubItems[1].Text = if ($p[2] -eq '-') { $p[6] } else { "$($p[2]): $($p[6])" }
            $it.SubItems[2].Text = $p[3]
            $it.SubItems[3].Text = $p[4]
            $it.SubItems[4].Text = $p[5]
            if ($p[4] -eq 'none') { $it.ForeColor = [System.Drawing.Color]::DarkRed }
        }
        [System.Windows.Forms.Application]::DoEvents()
    }
    Write-Log 'Done. Models in red have no shadow LODs.'
    Set-Busy $false
})

$btnAll.Add_Click({ foreach ($it in $lvModels.Items) { $it.Checked = $true } })
$btnNone.Add_Click({ foreach ($it in $lvModels.Items) { $it.Checked = $false } })
$btnMissing.Add_Click({ foreach ($it in $lvModels.Items) { $it.Checked = ($it.SubItems[3].Text -eq 'none') } })

$btnRun.Add_Click({
    $ticked = Get-Ticked
    if ($ticked.Count -eq 0) {
        [System.Windows.Forms.MessageBox]::Show('Tick at least one model.', 'Shadow LOD Maker', 'OK', 'Information') | Out-Null
        return
    }
    $opts = @('--source', "$($numSource.Value)")
    if ($chkLow.Checked) { $opts += @('--low', "$($numLow.Value)") }
    if (-not $chkFirst.Checked) { $opts += '--no-firstperson' }
    if ($numShrink.Value -gt 0) { $opts += @('--shrink', ([double]$numShrink.Value / 1000).ToString([System.Globalization.CultureInfo]::InvariantCulture)) }
    if ($chkReplace.Checked) { $opts += '--replace' }
    if ($chkDry.Checked) { $opts += '--dry-run' }
    if (-not $chkDry.Checked) {
        $msg = "Add shadow LODs to $($ticked.Count) model(s)?`n`nOriginals are copied to temp\shadow_backups first."
        if ([System.Windows.Forms.MessageBox]::Show($msg, 'Shadow LOD Maker', 'OKCancel', 'Question') -ne 'OK') { return }
    }
    Set-Busy $true
    $txtLog.Clear()
    Write-Log "Options: $($opts -join ' ')"
    Write-Log '=========================================='
    $n = 0
    foreach ($it in $ticked) {
        $n++
        Write-Log "[$n/$($ticked.Count)] $($it.Tag)"
        foreach ($line in (Invoke-Core ($opts + @($it.Tag)))) { Write-Log "   $line" }
        if (-not $chkDry.Checked) { Update-Row $it; if ($it.SubItems[3].Text -ne 'none') { $it.ForeColor = [System.Drawing.Color]::DarkGreen } }
    }
    Write-Log '=========================================='
    Write-Log 'Finished. Check any WARNING lines in Object Builder before packing.'
    Set-Busy $false
})

$btnRestore.Add_Click({
    $ticked = Get-Ticked
    if ($ticked.Count -eq 0) { return }
    $msg = "Put back the original (pre-shadow) version of $($ticked.Count) model(s)?"
    if ([System.Windows.Forms.MessageBox]::Show($msg, 'Shadow LOD Maker', 'OKCancel', 'Warning') -ne 'OK') { return }
    Set-Busy $true
    $txtLog.Clear()
    $root = $txtFolder.Text.Trim()
    foreach ($it in $ticked) {
        $bakName = ($it.Tag -replace '[\\/]', '__') -replace ':', ''
        $bak = Join-Path $backupDir $bakName
        if (Test-Path -LiteralPath $bak) {
            Copy-Item -LiteralPath $bak -Destination (Join-Path $root $it.Tag) -Force
            Write-Log "restored  $($it.Tag)"
            Update-Row $it
            $it.ForeColor = if ($it.SubItems[3].Text -eq 'none') { [System.Drawing.Color]::DarkRed } else { [System.Drawing.Color]::Black }
        } else {
            Write-Log "no backup $($it.Tag)  (looked for $bak)"
        }
    }
    Set-Busy $false
})

# ============ Startup checks ============
$form.Add_Shown({
    if (-not $python) {
        Write-Log 'ERROR: Python 3 not found. Install it from python.org (tick "Add to PATH") and reopen.'
        $btnRun.Enabled = $false; $btnScan.Enabled = $false
    } elseif (-not (Test-Path -LiteralPath $coreScript)) {
        Write-Log "ERROR: make_shadow_lods.py not found next to this script ($scriptDir)."
        $btnRun.Enabled = $false; $btnScan.Enabled = $false
    } else {
        Write-Log "Ready. Python: $python  |  Backups: $backupDir"
        Write-Log 'Pick a folder and press Scan.'
    }
})

[void]$form.ShowDialog()
