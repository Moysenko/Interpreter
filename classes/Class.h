#pragma once

#include "expressions/Expression.h"
#include "ClassFields.h"

#include <string>

class Class: public Expression {
public:
    Class(const std::string& name, ClassFields* class_fields);
    void Accept(Visitor* visitor);

    std::string name_;
    ClassFields* class_fields_;
};