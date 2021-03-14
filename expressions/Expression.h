#pragma once
#include "visitors/Visitor.h"


class Expression {
 public:
    virtual void Accept(Visitor* visitor) = 0;
    virtual ~Expression() = default;
};
