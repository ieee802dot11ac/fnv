# `config.json`

This file contains the progress categories and the compiler flags for your project.

## Format

```json
    "progress_categories": {
        "sdk": "XDK Code"
    },
    "asflags": [],
    "ldflags": [],
    "cflags": {
        "base": {
            "flags": [
                "/nologo",
                "/c"
            ]
        }
    }
```

- `"progress_categories"` The different progress categories for your project. Useful for tracking progress for game specific code, engine code, XDK code, etc. These will show up when your project finishes building and reports the progress percentages.
- `"asflags"` Leftover from dtk-template, goes unused.
- `"ldflags"` Leftover from dtk-template, goes unused.
- `"cflags"` Your project's compiler flags. Set the main compiler flags for your project as a whole in `base`, and then other sections can build off of it. So for example, you can have something like below, where you have a `base` compiler flag setup, and sub-configurations `engine` or `xdk` that build off the `base` flag set.

```json
    "cflags": {
        "base": {
            "flags": [
                "/nologo",
                "/c",
                "/GR",
                "/O1"
            ]
        },
        "engine": {
            "base": "base",
            "flags": [
                "/O2"
            ]
        },
        "xdk": {
            "base": "base",
            "flags": [
                "/Zi"
            ]
        }
    }
```
