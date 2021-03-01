#include "Asserter.h"

Asserter::Asserter(Expression *expression) :
    expression_(expression) {}

void Asserter::Accept(Visitor *visitor) {
    visitor->Visit(this);
}