//
//  Type.cpp
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/18.
//
//

#include "pigeon/AST/Type.hpp"

namespace pigeon {
enum class TypeKind { BuiltinVoid, BuiltinInt };

class Type {
  TypeKind Kind;

public:
  TypeKind getKind() const { return Kind; }
};
}
