#pragma once

#include "expressions/Expression.h"
#include "statements/StatementSequence.h"


class WhileLoop: public Expression {
 public:
    WhileLoop(Expression* condition, StatementSequence* body);
    void Accept(Visitor* visitor);

    Expression* condition_;
    StatementSequence* body_;
};