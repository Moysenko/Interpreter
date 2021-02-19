#pragma once

#include <variant>
#include "expressions/Expression.h"
#include "statements/StatementSequence.h"

class IfStatement: public Expression {
 public:
    IfStatement(Expression* condition, 
                StatementSequence* statement_sequence);

    IfStatement(Expression* condition, 
                StatementSequence* statement_sequence_true,
                StatementSequence* statement_sequence_false);

    IfStatement(Expression* condition, 
                StatementSequence* statement_sequence,
                IfStatement* else_if_statement);

    void Accept(Visitor* visitor);

    Expression* condition_;
    StatementSequence* statement_sequence_[2]; // [0] if true else [1]
    IfStatement* else_if_statement_;
};