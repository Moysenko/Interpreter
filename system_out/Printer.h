#pragma once

#include "expressions/Expression.h"
#include <string>

class Printer: public Expression {
 public:
    Printer(Expression* expression, bool new_line);
    void Accept(Visitor* visitor);

    Expression* expression_;
    bool new_line_;
};