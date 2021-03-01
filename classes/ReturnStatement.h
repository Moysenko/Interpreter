#pragma once

#include "expressions/Expression.h"
#include "ClassFields.h"

#include <string>

class ReturnStatement: public Expression {
public:
    ReturnStatement(Expression* expression);
    void Accept(Visitor* visitor);

    Expression* expression_;
};