#include "StringExpression.h"

StringExpression::StringExpression(std::string value) {
    value_ = value;
}

void StringExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}