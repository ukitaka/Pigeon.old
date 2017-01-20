//
//  Expr.hpp
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/19.
//
//

#ifndef PIGEON_AST_EXPR_H
#define PIGEON_AST_EXPR_H

#include "pigeon/AST/Operator.hpp"
#include "llvm/ADT/StringRef.h"
#include <memory>

namespace pigeon {

enum class ExprKind {
  IntegerLiteral,
  Binary,
  Paren,
};

class Expr {
  ExprKind Kind;

public:
  ExprKind getKind() const { return Kind; }
  Expr(ExprKind Kind);
};

class IntegerLiteral : public Expr {
  llvm::StringRef Val;

public:
  IntegerLiteral(llvm::StringRef Val);
};

class ParenExpr : public Expr {
  std::shared_ptr<Expr> SubExpr;

public:
  ParenExpr(std::shared_ptr<Expr> SubExpr);
};

class BinaryExpr : public Expr {
  std::shared_ptr<Expr> LHS;
  std::shared_ptr<Operator> Oper;
  std::shared_ptr<Expr> RHS;

public:
  BinaryExpr(std::shared_ptr<Expr> LHS, std::shared_ptr<Operator> Oper,
             std::shared_ptr<Expr> RHS);
};
}

#endif /* PIGEON_AST_EXPR_H */
