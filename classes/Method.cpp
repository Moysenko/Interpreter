#include "Method.h"

Method::Method(
    Type *type_name,
    const std::string &name,
    StatementSequence *statements
) : return_type_(type_name), name_(name), statements_(statements) {}

void Method::Accept(Visitor *visitor) {
    visitor->Visit(this);
}