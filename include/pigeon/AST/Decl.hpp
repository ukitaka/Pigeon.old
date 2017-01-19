//
//  Decl.hpp
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/18.
//
//

#ifndef PIGEON_AST_DECL_H
#define PIGEON_AST_DECL_H

#include "pigeon/AST/Type.hpp"
#include "pigeon/AST/Identifier.hpp"
#include <memory>

namespace pigeon {

class Decl {};

class VarDecl : public Decl {
  std::shared_ptr<Type> Type;
  std::shared_ptr<Identifier> Identifier;
};
}

#endif /* Decl_hpp */
