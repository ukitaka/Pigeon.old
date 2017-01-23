## Grammar

+ `digit-zero` →  0
+ `digit-non-zero` →  1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
+ `digit` →  `digit-zero` | `digit-non-zero`
+ `digits` →  `digit`
+ `digits` →  `digit` `digit`
+ `character-uppercase` →  A | B | ... | Z
+ `character-lowercase` →  a | b | ... | z
+ `character` →  `character-uppercase` | `character-lowercase`

### `oper_binary`

+ `oper_binary` →  + | - | * | / 

### `identifier`

+ `identifier-head` → `character-lowercase` 
+ `identifier-character` → `character-lowercase` | `character-uppercase` | `digit`
+ `identifier-characters` → `identifier-character`
+ `identifier-characters` → `identifier-character` `identifier-character`
+ `identifier` → `identifier-head` 
+ `identifier` → `identifier-head` | `identifier-characters`

### `type`

+ `type-head` → `character-uppercase` 
+ `type-character` → `character-lowercase` | `character-uppercase` | `digit`
+ `type-characters` → `type-character`
+ `type-characters` → `type-character` `type-character`
+ `type` → `type-characters` 

### `integer-literal`

+ `integer-literal-head` →  `digit-non-zero`
+ `integer-literal` →  `integer-literal-head`
+ `integer-literal` →  `integer-literal-head` `digits`

### `expr`

+ `expr` → ( `expr` )
+ `expr` → `expr` `oper_binary` `expr`
+ `expr` → `integer-literal`

### `decl-var`

+ `decl-var` →  var `identifier` : `type`
+ `decl-var` →  var `identifier` : `type` = `expr`
+ `decl-var` →  var `identifier` = `expr`

### `decl-top-level`

+ `decl-top-level` → `decl-var`

### `translation-unit`

+ `translation-unit` → `decl-top-level`

