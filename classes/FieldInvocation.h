#pragma once

#include "expressions/Expression.h"

#include <string>

class FieldInvocation: public Expression {
public:
    FieldInvocation(Expression* expression, const std::string& field_name);
    void Accept(Visitor* visitor);

    Expression* expression_;
    std::string field_name_;
};