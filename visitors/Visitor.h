#pragma once

#include "forward_decl.h"

class Visitor {
 public:
    virtual void Visit(NumberExpression* expression) = 0;
    virtual void Visit(StringExpression* expression) = 0;
    virtual void Visit(BoolExpression* expression) = 0;
    virtual void Visit(AddExpression* expression) = 0;
    virtual void Visit(AndExpression* expression) = 0;
    virtual void Visit(OrExpression* expression) = 0;
    virtual void Visit(LessExpression* expression) = 0;
    virtual void Visit(EqualExpression* expression) = 0;
    virtual void Visit(NotEqualExpression* expression) = 0;
    virtual void Visit(NegExpression* expression) = 0;
    virtual void Visit(SubstractExpression* expression) = 0;
    virtual void Visit(MulExpression* expression) = 0;
    virtual void Visit(DivExpression* expression) = 0;
    virtual void Visit(IdentExpression* expression) = 0;
    virtual void Visit(Instantiation* instantiation) = 0;
    virtual void Visit(Assignment* assignment) = 0;
    virtual void Visit(AssignmentList* assignment_list) = 0;
    virtual void Visit(Statement* statement) = 0;
    virtual void Visit(StatementSequence* statement_sequence) = 0;
    virtual void Visit(IfStatement* if_statement) = 0;
    virtual void Visit(WhileLoop* while_loop) = 0;
    virtual void Visit(ForLoop* for_loop) = 0;
    virtual void Visit(Printer* printer) = 0;
    virtual void Visit(Program* program) = 0;
};
