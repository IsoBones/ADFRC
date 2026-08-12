<!--
Title format: fix: / add: / tweak: / ci: / docs: followed by a short description.

Write your text OUTSIDE the grey comment blocks. Anything inside them is
invisible once the PR is posted. If a section doesn't apply, write N/A under
it rather than deleting it.
-->

## Summary

<!-- One or two sentences: what this changes and why. Add "Fixes #123" if it closes an issue. -->


## Details

<!--
The actual explanation:
- what was broken and what the root cause was
- the approach taken, and anything tried that didn't work
- new classnames, config paths, or CBA settings introduced
- anything a reviewer would otherwise reverse-engineer from the diff
-->


## Testing

<!-- Be specific. "Loaded fine" isn't testing. -->

- ADFRC version tested against:
- Other mods loaded:


## Checklist

These aren't clickable until the PR exists. Create it first, then tick the
boxes on the posted description. If an item doesn't apply, tick it and say why
in a comment.

**Repo integrity**

- [ ] Branch is up to date with `main` and merges cleanly
- [ ] No addon folder renames (`ADF_Air` -> `adfrc_air`). If intentional, it's explained above and every `requiredAddons` / path reference is updated
- [ ] No classnames renamed or removed without a pointer class left behind
- [ ] `CfgPatches` is present on new addons and `requiredAddons` covers everything actually depended on
- [ ] No protected legacy models or their source files (see `ASSETS_LICENSE.md`)
- [ ] New `.paa` files went through Git LFS
- [ ] Diff contains only intended changes
- [ ] Added myself to `CONTRIBUTORS.md` if this is my first PR

**Functional**

- [ ] Tested against the current public Workshop build, not an older local one
- [ ] No new RPT errors or warnings, or they're explained below
- [ ] Debug output removed (`diag_log`, `systemChat`, `hint` spam, commented-out experiments)
- [ ] No hardcoded local paths (`P:\`, drive letters, absolute mission paths)
- [ ] Nothing that previously worked has stopped working, including other open issues touching these assets
- [ ] Scripts: tested in MP or on a dedicated server, locality considered
- [ ] New assets: correct faction, side, `scope` / `scopeCurator`, and visible in Eden and Zeus


## Notes for the reviewer

<!-- Known limitations, deliberate omissions, follow-up work, explanations for any RPT noise introduced. -->