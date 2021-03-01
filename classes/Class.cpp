#include "Class.h"

Class::Class(const std::string &name, ClassFields *class_fields) :
    name_(name), class_fields_(class_fields) {}

void Class::Accept(Visitor *visitor) {
    visitor->Visit(this);
}