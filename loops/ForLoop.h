#pragma once

#include "expressions/Expression.h"
#include "statements/StatementSequence.h"


class ForLoop: public Expression {
 public:
    ForLoop(Expression* condition, Assignment* modifier, StatementSequence* body);
    void Accept(Visitor* visitor);

    Expression* condition_;
    Assignment* modifier_;
    StatementSequence* body_;
};