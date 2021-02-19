#include "IfStatement.h"
#include <iostream>

IfStatement::IfStatement(
    Expression* condition, 
    StatementSequence* statement_sequence
):  condition_(condition), 
    statement_sequence_{statement_sequence, nullptr},
    else_if_statement_(nullptr) {}

IfStatement::IfStatement(
    Expression* condition, 
    StatementSequence* statement_sequence_true,
    StatementSequence* statement_sequence_false
):  condition_(condition), 
    statement_sequence_{statement_sequence_true, statement_sequence_false},
    else_if_statement_(nullptr) {}

IfStatement::IfStatement(
    Expression* condition, 
    StatementSequence* statement_sequence,
    IfStatement* else_if_statement
):  condition_(condition), 
    statement_sequence_{statement_sequence, nullptr},
    else_if_statement_(else_if_statement) {}

void IfStatement::Accept(Visitor* visitor) {
    visitor->Visit(this);
}