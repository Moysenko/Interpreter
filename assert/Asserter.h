#pragma once

#include "expressions/Expression.h"

class Assert: public Expression {
public:
    Assert(Expression* expression);
    void Accept(Visitor* visitor);

    Expression* expression_;
};