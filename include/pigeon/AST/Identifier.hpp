//
//  Identifier.hpp
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/19.
//
//

#ifndef PIGEON_AST_IDENTIFIER_H
#define PIGEON_AST_IDENTIFIER_H

#include "llvm/ADT/StringRef.h"
#include <string>

namespace pigeon {
class Identifier {
  llvm::StringRef Name;

public:
  Identifier(llvm::StringRef Name);
  llvm::StringRef getName() const { return Name; }
};
}

#endif /* PIGEON_AST_IDENTIFIER_H */
