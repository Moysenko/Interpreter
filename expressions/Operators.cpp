#include "Operators.h"

AddExpression::AddExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}
void AddExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

SubstractExpression::SubstractExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}
void SubstractExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

DivExpression::DivExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}
void DivExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

MulExpression::MulExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}
void MulExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

AndExpression::AndExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}
void AndExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

OrExpression::OrExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}
void OrExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

LessExpression::LessExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}
void LessExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

EqualExpression::EqualExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}
void EqualExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

NotEqualExpression::NotEqualExpression(
    Expression *e1, Expression *e2
): first(e1), second(e2) {}
void NotEqualExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

NegExpression::NegExpression(
    Expression* other_exp
): exp(other_exp) {}
void NegExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

GetElement::GetElement(
    Expression *expression, Expression *index
): expression_(expression), index_(index) {}
void GetElement::Accept(Visitor *visitor) {
    visitor->Visit(this);
}