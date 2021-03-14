#include "FieldInvocation.h"

FieldInvocation::FieldInvocation(Expression *expression, const std::string &field_name) :
    expression_(expression), field_name_(field_name){}

void FieldInvocation::Accept(Visitor *visitor) {
    visitor->Visit(this);
}