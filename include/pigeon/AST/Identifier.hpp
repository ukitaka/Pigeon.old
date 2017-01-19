//
//  Identifier.hpp
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/19.
//
//

#ifndef PIGEON_AST_IDENTIFIER_H
#define PIGEON_AST_IDENTIFIER_H

#include <string>
#include "llvm/ADT/StringRef.h"

namespace pigeon {
    class Identifier {
        llvm::StringRef Name;
    public:
        llvm::StringRef getName() const { return Name; }
    };
}

#endif /* PIGEON_AST_IDENTIFIER_H */
