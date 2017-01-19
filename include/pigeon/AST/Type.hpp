//
//  Type.hpp
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/18.
//
//

#ifndef PIGEON_AST_SOURCE_H
#define PIGEON_AST_SOURCE_H

namespace pigeon {
enum class TypeKind { BuiltinVoid, BuiltinInt };

class Type {
  TypeKind Kind;

public:
  TypeKind getKind() const { return Kind; }
};
}

#endif /* PIGEON_AST_SOURCE_H */
