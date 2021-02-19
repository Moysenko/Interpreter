#pragma once
#include "Expression.h"

class AddExpression: public Expression {
 public:
    AddExpression(Expression* e1, Expression* e2);
    void Accept(Visitor* visitor) override;
    Expression* first;
    Expression* second;
};

class SubstractExpression: public Expression {
 public:
    SubstractExpression(Expression* e1, Expression* e2);
    void Accept(Visitor* visitor) override;

    Expression* first;
    Expression* second;
};

class DivExpression: public Expression {
 public:
    DivExpression(Expression* e1, Expression* e2);
    void Accept(Visitor* visitor) override;
    Expression* first;
    Expression* second;
};

class MulExpression: public Expression {
 public:
    MulExpression(Expression* e1, Expression* e2);
    void Accept(Visitor* visitor) override;

    Expression* first;
    Expression* second;
};

class AndExpression: public Expression {
 public:
    AndExpression(Expression* e1, Expression* e2);
    void Accept(Visitor* visitor) override;
    Expression* first;
    Expression* second;
};

class OrExpression: public Expression {
 public:
    OrExpression(Expression* e1, Expression* e2);
    void Accept(Visitor* visitor) override;
    Expression* first;
    Expression* second;
};

class LessExpression: public Expression {
 public:
    LessExpression(Expression* e1, Expression* e2);
    void Accept(Visitor* visitor) override;
    Expression* first;
    Expression* second;
};

class EqualExpression: public Expression {
 public:
    EqualExpression(Expression* e1, Expression* e2);
    void Accept(Visitor* visitor) override;
    Expression* first;
    Expression* second;
};

class NotEqualExpression: public Expression {
 public:
    NotEqualExpression(Expression* e1, Expression* e2);
    void Accept(Visitor* visitor) override;
    Expression* first;
    Expression* second;
};

class NegExpression: public Expression {
 public:
    NegExpression(Expression* other_exp);
    void Accept(Visitor* visitor) override;
    Expression* exp;
};