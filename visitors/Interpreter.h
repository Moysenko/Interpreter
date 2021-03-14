#include "types/Types.h"
#include "Visitor.h"
#include <map>

class Interpreter : public Visitor {
 public:
    Interpreter();
    void Visit(NumberExpression* expression) override;
    void Visit(StringExpression* expression) override;
    void Visit(BoolExpression* expression) override;
    void Visit(AddExpression* expression) override;
    void Visit(AndExpression* expression) override;
    void Visit(OrExpression* expression) override;
    void Visit(LessExpression* expression) override;
    void Visit(EqualExpression* expression) override;
    void Visit(NotEqualExpression* expression) override;
    void Visit(NegExpression* expression) override;
    void Visit(SubstractExpression* expression) override;
    void Visit(MulExpression* expression) override;
    void Visit(DivExpression* expression) override;
    void Visit(IdentExpression* expression) override;
    void Visit(GetElement* expression) override;
    void Visit(Instantiation* instantiation) override;
    void Visit(Assignment* assignment) override;
    void Visit(AssignmentList* assignment_list) override;
    void Visit(Statement* statement) override;
    void Visit(StatementSequence* statement_sequence) override;
    void Visit(IfStatement* if_statement) override;
    void Visit(WhileLoop* while_loop) override;
    void Visit(ForLoop* for_loop) override;
    void Visit(Printer* printer) override;
    void Visit(Asserter* asserter) override;
    void Visit(Class* class_decl) override;
    void Visit(Method* method_decl) override;
    void Visit(ClassFields* class_fields) override;
    void Visit(MethodInvocation* method_invocation) override;
    void Visit(FieldInvocation* field_invocation) override;
    void Visit(ReturnStatement* return_statement) override;
    void Visit(Array* array) override;
    void Visit(Pointer* pointer) override;
    void Visit(Program* program) override;

    int GetResult(Program* program);

 private:
    std::map<std::string, MultiType> variables_;
    bool is_tos_expression_;
    MultiType tos_value_;

    void SetTosValue(MultiType value);
    void UnsetTosValue();
    
};