#pragma once

#include "expressions/Expression.h"
#include "types/Types.h"

#include <string>

class Method: public Expression {
public:
    Method(
            Type* type_name,
            const std::string& name,
            StatementSequence* statements);
    void Accept(Visitor* visitor);

    Type* return_type_;
    std::string name_;
    StatementSequence* statements_;
};