#pragma once
#include "Expression.h"

class BoolExpression: public Expression {
public:
    explicit BoolExpression(bool value);
    void Accept(Visitor* visit) override;

    bool value_;
};