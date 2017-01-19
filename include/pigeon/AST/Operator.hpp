//
//  Operator.hpp
//  pigeon
//
//  Created by Yuki Takahashi on 2017/01/19.
//
//

#ifndef PIGEON_AST_OPERATOR_H
#define PIGEON_AST_OPERATOR_H

namespace pigeon {
enum class OperatorKind { Add, Sub, Mul, Shl };

class Operator {};
class BinaryOperator : public Operator {
  const OperatorKind Kind;

public:
  BinaryOperator(OperatorKind Kind);
  OperatorKind getKind() const { return Kind; };
};
}

#endif /* PIGEON_AST_OPERATOR_H */
