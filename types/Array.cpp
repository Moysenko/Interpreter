#include "Array.h"

Array::Array(Type* array_type, Expression *expression) :
    type_(array_type), expression_(expression) {}

void Array::Accept(Visitor *visitor) {
    visitor->Visit(this);
}