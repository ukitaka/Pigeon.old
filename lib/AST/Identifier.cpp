//
//  Identifier.cpp
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/19.
//
//

#include "pigeon/AST/Identifier.hpp"

using namespace pigeon;

Identifier::Identifier(llvm::StringRef Name) : Name(Name) {}
