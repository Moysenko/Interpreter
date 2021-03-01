#pragma once

#include <variant>
#include "expressions/Expression.h"
#include "assignments/Assignment.h"
#include "classes/ReturnStatement.h"

#include <string>

class Statement: public Expression {
 public:
    Statement(Assignment* other_link);
    Statement(Expression* other_link);
    Statement(Instantiation* other_link);
    Statement(Printer* other_link);
    Statement(Asserter* other_link);
    Statement(IfStatement* other_link);
    Statement(WhileLoop* other_link);
    Statement(ForLoop* other_link);
    Statement(ReturnStatement* other_link);
    Statement(StatementSequence* other_link);

    void Accept(Visitor* visitor);

    std::variant<Assignment*, 
                 Expression*, 
                 Instantiation*, 
                 Printer*,
                 Asserter*,
                 IfStatement*, 
                 WhileLoop*,
                 ForLoop*,
                 ReturnStatement*,
                 StatementSequence*> link;
};