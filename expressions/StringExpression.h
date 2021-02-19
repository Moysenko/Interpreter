#pragma once
#include "Expression.h"
#include <string>

class StringExpression: public Expression {
public:
    explicit StringExpression(std::string value);
    void Accept(Visitor* visit) override;

    std::string value_;
};