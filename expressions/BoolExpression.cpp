#include "BoolExpression.h"

BoolExpression::BoolExpression(bool value) {
    value_ = value;
}

void BoolExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}