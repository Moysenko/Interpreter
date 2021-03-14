cmake_minimum_required(VERSION 3.16)

project(Interpreter)
set(
    HEADERS
    driver.hh
    parser.hh
    )

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)
    
set(CMAKE_CXX_STANDARD 17)

BISON_TARGET(
    ParserVisitor
    parser.y
    ${Interpreter_SOURCE_DIR}/parser.cpp
    COMPILE_FLAGS --graph
    DEFINES_FILE ${Interpreter_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
    ScannerVisitor
    scanner.l
    ${Interpreter_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(ScannerVisitor ParserVisitor)

add_executable(
    MiniJava
    main.cpp
    driver.cpp
    ${BISON_ParserVisitor_OUTPUTS}
    ${FLEX_ScannerVisitor_OUTPUTS}
    types/Types.cpp
    expressions/NumberExpression.cpp
    expressions/StringExpression.cpp
    expressions/BoolExpression.cpp
    expressions/Operators.cpp
    expressions/IdentExpression.cpp
    assignments/Assignment.cpp
    assignments/AssignmentList.cpp
    statements/Statement.cpp
    statements/StatementSequence.cpp
    if_statement/IfStatement.cpp
    loops/WhileLoop.cpp
    loops/ForLoop.cpp
    system_out/Printer.cpp
    instantiations/Instantiation.cpp
    visitors/Interpreter.cpp
    Program.cpp
    assert/Asserter.cpp
    classes/Class.cpp
    classes/ClassFields.cpp
    classes/Method.cpp
    classes/MethodInvocation.cpp
    classes/FieldInvocation.cpp
    classes/ReturnStatement.cpp
    types/Array.cpp
    types/Pointer.cpp
)

target_include_directories(
    MiniJava PRIVATE ${Interpreter_SOURCE_DIR}
)

add_custom_target(
    VisitorTree
    COMMAND dot -Tpng ${Interpreter_SOURCE_DIR}/parser.gv -o ${Interpreter_SOURCE_DIR}/parser.png
    
    DEPENDS ${Interpreter_SOURCE_DIR}/parser.cpp
)

add_dependencies(MiniJava VisitorTree)



