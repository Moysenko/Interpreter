#include "Instantiation.h"

Instantiation::Instantiation(
    Type* type_name,
    const std::string& variable,
    Expression* expression
) : variable_type_(type_name), variable_(variable), expression_(expression) {}

Instantiation::Instantiation(
    Type* type_name,
    const std::string& variable
) : variable_type_(type_name), variable_(variable), expression_(nullptr) {}


void Instantiation::Accept(Visitor* visitor) {
    visitor->Visit(this);
}