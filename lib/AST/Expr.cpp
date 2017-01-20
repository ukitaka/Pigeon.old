//
//  Expr.cpp
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/19.
//
//

#include "pigeon/AST/Expr.hpp"
#include <memory>

using namespace pigeon;

Expr::Expr(ExprKind Kind) : Kind(Kind) {}

IntegerLiteral::IntegerLiteral(llvm::StringRef Val)
    : Expr(ExprKind::IntegerLiteral), Val(Val) {}

ParenExpr::ParenExpr(std::shared_ptr<Expr> SubExpr)
    : Expr(ExprKind::Paren), SubExpr(SubExpr) {}

BinaryExpr::BinaryExpr(std::shared_ptr<Expr> LHS,
                       std::shared_ptr<Operator> Oper,
                       std::shared_ptr<Expr> RHS)
    : Expr(ExprKind::Binary), LHS(LHS), Oper(Oper), RHS(RHS) {}
