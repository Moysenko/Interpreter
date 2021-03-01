#include "Assert.h"

Assert::Assert(Expression *expression) :
    expression_(expression) {}

void Assert::Accept(Visitor *visitor) {
    visitor->Visit(this);
}