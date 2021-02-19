#include "StatementSequence.h"

void StatementSequence::AddStatement(Statement* statement) {
    statements_.push_back(statement);
}

void StatementSequence::Accept(Visitor* visitor) {
    visitor->Visit(this);
}