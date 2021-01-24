project(MyInterpreter)
cmake_minimum_required(VERSION 3.16)

set(
    HEADERS
    ${MyInterpreter_SOURCE_DIR}/driver.hh
    ${MyInterpreter_SOURCE_DIR}/parser.hh
    )

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MyInterpreter_SOURCE_DIR}/bin)

    
BISON_TARGET(
    MyParser
    parser.y
    ${MyInterpreter_SOURCE_DIR}/parser.cpp
    DEFINES_FILE ${MyInterpreter_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
    MyScanner
    scanner.l
    ${MyInterpreter_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
    MyInterpreter
    main.cpp
    driver.cpp
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
)
target_include_directories(MyInterpreter PRIVATE ${MyInterpreter_SOURCE_DIR})



