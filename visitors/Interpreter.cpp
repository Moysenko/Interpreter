#include "Interpreter.h"

#include "elements.h"

#include <iostream>

Interpreter::Interpreter() {
    variables_["one"] = 1;
    variables_["two"] = 2;
    is_tos_expression_ = false;
    tos_value_ = 0;
}

void Interpreter::Visit(NumberExpression* expression) {
    SetTosValue(expression->value_);
}

void Interpreter::Visit(StringExpression* expression) {
    SetTosValue(expression->value_);
}

void Interpreter::Visit(BoolExpression* expression) {
    SetTosValue(expression->value_);
}

void Interpreter::Visit(AddExpression* expression) {
    expression->first->Accept(this);
    if (std::holds_alternative<int>(tos_value_)) {
        int value = std::get<int>(tos_value_);
        expression->second->Accept(this);
        value += std::get<int>(tos_value_);
        SetTosValue(value);
    } else {
        std::string value = std::get<std::string>(tos_value_);
        expression->second->Accept(this);
        value += std::get<std::string>(tos_value_);
        SetTosValue(value);
    }
}

void Interpreter::Visit(AndExpression* expression) {
    expression->first->Accept(this);
    if (!std::holds_alternative<bool>(tos_value_)) {
        throw std::invalid_argument("inappropriate first argument for operator&&");
    }
    bool value = std::get<bool>(tos_value_);

    expression->second->Accept(this);
    if (!std::holds_alternative<bool>(tos_value_)) {
        throw std::invalid_argument("inappropriate second argument for operator&&");
    }
    value = value && std::get<bool>(tos_value_);

    SetTosValue(value);
}

void Interpreter::Visit(OrExpression* expression) {
    expression->first->Accept(this);
    if (!std::holds_alternative<bool>(tos_value_)) {
        throw std::invalid_argument("inappropriate first argument for operator||");
    }
    bool value = std::get<bool>(tos_value_);

    expression->second->Accept(this);
    if (!std::holds_alternative<bool>(tos_value_)) {
        throw std::invalid_argument("inappropriate second argument for operator||");
    }
    value = value || std::get<bool>(tos_value_);

    SetTosValue(value);
}

void Interpreter::Visit(LessExpression* expression) {
    expression->first->Accept(this);
    if (std::holds_alternative<int>(tos_value_)) {
        int value = std::get<int>(tos_value_);
        expression->second->Accept(this);
        SetTosValue(value < std::get<int>(tos_value_));
    } else {
        std::string value = std::get<std::string>(tos_value_);
        expression->second->Accept(this);
        SetTosValue(value < std::get<std::string>(tos_value_));
    }
}

void Interpreter::Visit(EqualExpression* expression) {
    expression->first->Accept(this);
    if (std::holds_alternative<int>(tos_value_)) {
        int value = std::get<int>(tos_value_);
        expression->second->Accept(this);
        SetTosValue(value == std::get<int>(tos_value_));
    } else if (std::holds_alternative<std::string>(tos_value_)) {
        std::string value = std::get<std::string>(tos_value_);
        expression->second->Accept(this);
        SetTosValue(value == std::get<std::string>(tos_value_));
    } else if (std::holds_alternative<bool>(tos_value_)) {
        bool value = std::get<bool>(tos_value_);
        expression->second->Accept(this);
        SetTosValue(value == std::get<bool>(tos_value_));
    } else {
        throw std::invalid_argument("inappropriate arguments for operator==");
    }
}

void Interpreter::Visit(NotEqualExpression* expression) {
    expression->first->Accept(this);
    if (std::holds_alternative<int>(tos_value_)) {
        int value = std::get<int>(tos_value_);
        expression->second->Accept(this);
        SetTosValue(value != std::get<int>(tos_value_));
    } else if (std::holds_alternative<std::string>(tos_value_)) {
        std::string value = std::get<std::string>(tos_value_);
        expression->second->Accept(this);
        SetTosValue(value != std::get<std::string>(tos_value_));
    } else if (std::holds_alternative<bool>(tos_value_)) {
        bool value = std::get<bool>(tos_value_);
        expression->second->Accept(this);
        SetTosValue(value != std::get<bool>(tos_value_));
    } else {
        throw std::invalid_argument("inappropriate arguments for operator!=");
    }
}

void Interpreter::Visit(NegExpression* expression) {
    expression->exp->Accept(this);
    if (!std::holds_alternative<bool>(tos_value_)) {
        throw std::invalid_argument("inappropriate argument for operator!");
    }
    SetTosValue(!std::get<bool>(tos_value_));
}

void Interpreter::Visit(SubstractExpression* expression) {
    expression->first->Accept(this);
    if (std::holds_alternative<int>(tos_value_)) {
        int value = std::get<int>(tos_value_);
        expression->second->Accept(this);
        value -= std::get<int>(tos_value_);
        SetTosValue(value);
    } else {
        throw std::invalid_argument("inappropriate arguments for operator-");
    }
}

void Interpreter::Visit(MulExpression* expression) {
    expression->first->Accept(this);
    if (std::holds_alternative<int>(tos_value_)) {
        int value = std::get<int>(tos_value_);
        expression->second->Accept(this);
        value *= std::get<int>(tos_value_);
        SetTosValue(value);
    } else {
        throw std::invalid_argument("inappropriate arguments for operator*");
    }
}

void Interpreter::Visit(DivExpression* expression) {
    expression->first->Accept(this);
    if (std::holds_alternative<int>(tos_value_)) {
        int value = std::get<int>(tos_value_);
        expression->second->Accept(this);
        value /= std::get<int>(tos_value_);
        SetTosValue(value);
    } else {
        throw std::invalid_argument("inappropriate arguments for operator/");
    }
}

void Interpreter::Visit(IdentExpression* expression) {
    SetTosValue(variables_[expression->ident_]);
}

void Interpreter::Visit(Instantiation* instantiation) {
    if (instantiation->expression_) {
        instantiation->expression_->Accept(this);
        variables_[instantiation->variable_] = tos_value_;
    } else {
        SetToDefault(*(instantiation->variable_type_), 
                     variables_[instantiation->variable_]);
    }
}

void Interpreter::Visit(Assignment* assignment) {
    assignment->expression_->Accept(this);
    variables_[assignment->variable_] = tos_value_;

    UnsetTosValue();
}

void Interpreter::Visit(AssignmentList* assignment_list) {
    for (Assignment* assignment: assignment_list->assignments_) {
        assignment->Accept(this);
    }
    UnsetTosValue();
}

void Interpreter::Visit(Statement* statement) {
    if (std::holds_alternative<Assignment*>(statement->link)) {
        std::get<Assignment*>(statement->link)->Accept(this);
    } else if (std::holds_alternative<IfStatement*>(statement->link)) {
        std::get<IfStatement*>(statement->link)->Accept(this);
    } else if (std::holds_alternative<Printer*>(statement->link)) {
        std::get<Printer*>(statement->link)->Accept(this);
    } else if (std::holds_alternative<Instantiation*>(statement->link)) {
        std::get<Instantiation*>(statement->link)->Accept(this);
    } else if (std::holds_alternative<WhileLoop*>(statement->link)) {
        std::get<WhileLoop*>(statement->link)->Accept(this);
    } else if (std::holds_alternative<ForLoop*>(statement->link)) {
        std::get<ForLoop*>(statement->link)->Accept(this);
    } else if (std::holds_alternative<Expression*>(statement->link)) {
        std::get<Expression*>(statement->link)->Accept(this);
    } 
}

void Interpreter::Visit(StatementSequence* statement_sequence) {
    for (Statement* statement: statement_sequence->statements_) {
        statement->Accept(this);
    }
    UnsetTosValue();
}

void Interpreter::Visit(IfStatement* if_statement) {
    if_statement->condition_->Accept(this);
    if (!std::holds_alternative<bool>(tos_value_)) {
        throw std::invalid_argument("inappropriate contidion for \"if\" statement");
    }

    if (std::get<bool>(tos_value_)) {
        if_statement->statement_sequence_[0]->Accept(this);
    } else if (if_statement->statement_sequence_[1]) {
        if_statement->statement_sequence_[1]->Accept(this);
    } else if (if_statement->else_if_statement_) {
        if_statement->else_if_statement_->Accept(this);
    }

    UnsetTosValue();
}

void Interpreter::Visit(WhileLoop* while_loop) {
    while_loop->condition_->Accept(this);
    if (!std::holds_alternative<bool>(tos_value_)) {
        throw std::invalid_argument("inappropriate contidion for while loop");
    }

    while (std::get<bool>(tos_value_)) {
        while_loop->body_->Accept(this);
        while_loop->condition_->Accept(this);
    }

    UnsetTosValue();
}

void Interpreter::Visit(ForLoop* for_loop) {
    for_loop->condition_->Accept(this);
    if (!std::holds_alternative<bool>(tos_value_)) {
        throw std::invalid_argument("inappropriate contidion for for loop");
    }

    while (std::get<bool>(tos_value_)) {
        for_loop->body_->Accept(this);
        for_loop->modifier_->Accept(this);
        for_loop->condition_->Accept(this);
    }

    UnsetTosValue();
}

void Interpreter::Visit(Printer* printer) {
    printer->expression_->Accept(this);

    if (std::holds_alternative<int>(tos_value_)) {
        std::cout << std::get<int>(tos_value_);
    } else if (std::holds_alternative<std::string>(tos_value_)) {
        std::cout << std::get<std::string>(tos_value_);
    } else if (std::holds_alternative<bool>(tos_value_)) {
        std::cout << (std::get<bool>(tos_value_) ? "true" : "false");
    }

    if (printer->new_line_) {
        std::cout << std::endl;
    }

    UnsetTosValue();
}

void Interpreter::Visit(Program* program) {
    program->statements_->Accept(this);
}

void Interpreter::SetTosValue(MultiType value) {
    tos_value_ = value;
    is_tos_expression_ = true;
}

void Interpreter::UnsetTosValue() {
    if (std::holds_alternative<int>(tos_value_)) {
        SetToDefault(Type::INT, tos_value_);
    } else if (std::holds_alternative<std::string>(tos_value_)) {
        SetToDefault(Type::STRING, tos_value_);
    } else if (std::holds_alternative<bool>(tos_value_)) {
        SetToDefault(Type::BOOL, tos_value_);
    } else {
        SetToDefault(Type::VOID, tos_value_);
    }
    is_tos_expression_ = false;
}

int Interpreter::GetResult(Program *program) {
    // std::cout << "START" << std::endl;
    UnsetTosValue();
    Visit(program);
    // std::cout << "END" << std::endl;
    return 0;
}