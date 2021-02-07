#include "Printer.h"

Printer::Printer(Expression* expression, bool new_line) : 
    expression_(expression), new_line_(new_line) {}

void Printer::Accept(Visitor* visitor) {
    visitor->Visit(this);
}