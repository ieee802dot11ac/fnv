# `objects.json`

This file contains the object configurations for your project. It is left blank for now - add objects you are decompiling here as needed.

## Format

```json
    "main": {
        "progress_category": "your-category",
        "mw_version": "X360/16.00.11886.00",
        "cflags": "base",
        "objects": {
            "path/to/file1.cpp": "MISSING",
            "path/to/file2.cpp": "MISSING"
        }
    }
```

- `"main"` The type of objects being configured here. The example above is for `main`, but you can add others as you see fit for your project (`engine`, `xdk`, etc).
- `"progress_category"` The category from `config.json` that this object type will count towards.
- `"mw_version"` The X360 compiler version.
- `"cflags"` The compiler flags to use for this object type.
- `"objects"` The different objects that make up this object type.

For additional reference on how this json should be formatted, feel free to use [the ongoing DC3 decomp's json](https://github.com/rjkiv/dc3-decomp/blob/main/config/373307D9/config.json) as an extra resource.
