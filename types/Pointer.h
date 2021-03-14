#pragma once

#include "Types.h"
#include "expressions/Expression.h"

class Pointer: public Expression {
public:
    Pointer(Type* array_type);
    void Accept(Visitor* visitor);

    Type* type_;
};