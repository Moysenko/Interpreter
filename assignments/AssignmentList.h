#pragma once

#include "assignments/Assignment.h"
#include <vector>

class AssignmentList : public Expression {
 public:
    void AddAssignment(Assignment* assignment);
    void Accept(Visitor* visitor);

    std::vector<Assignment*> assignments_;
};