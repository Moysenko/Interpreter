#include "Pointer.h"

Pointer::Pointer(Type* array_type) : type_(array_type){}

void Pointer::Accept(Visitor *visitor) {
    visitor->Visit(this);
}