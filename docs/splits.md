# `splits.txt`

This file contains file splits for a module.

Example:

```yaml
path/to/file.cpp:
	.rdata      start:0x82044A58 end:0x82045A70
	.rdata      start:0x822916D8 end:0x82291728 rename:.rdata$r
	.pdata      start:0x822C2118 end:0x822C25F0
	.text       start:0x8249D270 end:0x824A2678
	.data       start:0x82F0D998 end:0x82F0D9F0
	.data       start:0x82F60C88 end:0x82F60D88 rename:.bss
```

## Format

```yaml
path/to/file.cpp: [file attributes]
    section     [section attributes]
    ...
```

- `path/to/file.cpp` The name of the source file, usually relative to `src`. The file does **not** need to exist to start.  
  This corresponds to an entry in `configure.py` for specifying compiler flags and other options.

### Section attributes

- `start:` The start address of the section within the file.
- `end:` The end address of the section within the file.
- `align:` Specifies the alignment of the section. If not specified, the default alignment for the section is used.
- `rename:` Writes this section under a different name when generating the split object. Used for `.ctors$10`, etc.
- `skip` Skips this data when writing the object file. Used for ignoring data that's linker-generated.
