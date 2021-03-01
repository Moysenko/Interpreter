#pragma once

#include "expressions/Expression.h"

class Asserter: public Expression {
public:
    Asserter(Expression* expression);
    void Accept(Visitor* visitor);

    Expression* expression_;
};