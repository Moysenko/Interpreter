#include "ClassFields.h"

void ClassFields::AddField(Method *method) {
    fields_.emplace_back(method);
}

void ClassFields::AddField(Instantiation *instantiation) {
    fields_.emplace_back(instantiation);
}

void ClassFields::Accept(Visitor *visitor) {
    visitor->Visit(this);
}



