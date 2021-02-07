#pragma once

#include "statements/Statement.h"
#include <vector>

class StatementSequence : public Expression {
 public:
    void AddStatement(Statement* statement);
    void Accept(Visitor* visitor);

    std::vector<Statement*> statements_;
};