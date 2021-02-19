#include "Statement.h"

Statement::Statement(Assignment* other_link): link(other_link) {}

Statement::Statement(Expression* other_link): link(other_link) {}

Statement::Statement(Instantiation* other_link): link(other_link) {}

Statement::Statement(Printer* other_link): link(other_link) {}

Statement::Statement(IfStatement* other_link): link(other_link) {}

Statement::Statement(WhileLoop* other_link): link(other_link) {}

Statement::Statement(ForLoop* other_link): link(other_link) {}

void Statement::Accept(Visitor* visitor) {
    visitor->Visit(this);
}