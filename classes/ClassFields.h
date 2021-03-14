#pragma once

#include "expressions/Expression.h"
#include "Method.h"
#include "instantiations/Instantiation.h"

#include <vector>
#include <variant>

class ClassFields : public Expression {
public:
    void AddField(Method* method);
    void AddField(Instantiation* instantiation);
    void Accept(Visitor* visitor);

    std::vector<std::variant<Method*, Instantiation*>> fields_;
};