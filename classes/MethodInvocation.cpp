#include "MethodInvocation.h"

MethodInvocation::MethodInvocation(Expression *expression, const std::string &method_name) :
    expression_(expression), method_name_(method_name) {}

void MethodInvocation::Accept(Visitor *visitor) {
    visitor->Visit(this);
}