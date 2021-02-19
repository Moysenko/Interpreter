#include "ForLoop.h"
#include <iostream>

ForLoop::ForLoop(
    Expression* condition, 
    Assignment* modifier,
    StatementSequence* body
):  condition_(condition),
    modifier_(modifier),
    body_(body) {}

void ForLoop::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
