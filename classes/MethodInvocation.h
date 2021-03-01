#pragma once

#include "expressions/Expression.h"

#include <string>

class MethodInvocation: public Expression {
public:
    MethodInvocation(Expression* expression, const std::string& method_name);
    void Accept(Visitor* visitor);

    Expression* expression_;
    std::string method_name_;
};