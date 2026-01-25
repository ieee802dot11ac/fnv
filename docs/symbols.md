# `symbols.txt`

This file contains all symbols for a module, one per line.

Example line:

```
?CamJointPositions@DancerSkeleton@@UBAXPAVVector3@@@Z = .text:0x8251D260; // type:function size:0x14 scope:global
```

## Format

Numbers can be written as decimal or hexadecimal. Hexadecimal numbers must be prefixed with `0x`.

Comment lines starting with `//` or `#` are permitted, but are currently **not** preserved when updating the file.

```
symbol_name = section:address; // [attributes]
```

- `symbol_name` - The name of the symbol. (For C++, this is the mangled name, e.g. `__dt__13mDoExt_bckAnmFv`)
- `section` - The section the symbol is in.
- `address` - The address of the symbol.

### Attributes

All attributes are optional, and are separated by spaces.

- `type:` The symbol type. `function`, `object`, or `label`.
- `size:` The size of the symbol.
- `scope:` The symbol's visibility. `global` (default), `local` or `weak`.
- `align:` The symbol's alignment.
- `data:` The data type used when writing disassembly. `byte`, `2byte`, `4byte`, `8byte`, `float`, `double`, `int`, `short`, `string`, `wstring`, `string_table`, or `wstring_table`.
