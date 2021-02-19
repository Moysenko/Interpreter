#include "types/Types.h"
#include "expressions/Expression.h"

#include <string>

class Instantiation: public Expression {
 public:
    Instantiation(
        Type* type_name,
        const std::string& variable, 
        Expression* expression);
    Instantiation(Type* type_name, const std::string& variable);
    void Accept(Visitor* visitor);

    Type* variable_type_;
    std::string variable_;
    Expression* expression_;
};