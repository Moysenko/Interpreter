#include "WhileLoop.h"
#include <iostream>

WhileLoop::WhileLoop(
    Expression* condition, 
    StatementSequence* body
):  condition_(condition),
    body_(body) {}

void WhileLoop::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
