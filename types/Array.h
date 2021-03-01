#pragma once

#include "Types.h"
#include "expressions/Expression.h"

class Array: public Expression {
public:
    Array(Type* array_type, Expression* expression);
    void Accept(Visitor* visitor);

    Type* type_;
    Expression* expression_;
};