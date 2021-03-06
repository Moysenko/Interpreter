%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    class Scanner;
    class Driver;
    class Expression;
    class NumberExpression;
    class StringExpression;
    class BoolExpression;
    class AddExpression;
    class AndExpression;
    class OrExpression;
    class LessExpression;
    class SubstractExpression;
    class DivExpression;
    class IdentExpression;
    class Instantiation;
    class Assignment;
    class AssignmentList;
    class IfStatement;
    class WhileLoop;
    class ForLoop;
    class Statement;
    class StatementSequence;
    class Printer;

    class Program;
    class Type;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {    
    #include "types/Types.h"

    #include "driver.hh"
    #include "location.hh"

    #include "expressions/NumberExpression.h"
    #include "expressions/StringExpression.h"
    #include "expressions/BoolExpression.h"
    #include "expressions/Operators.h"
    #include "expressions/IdentExpression.h"
    #include "instantiations/Instantiation.h"
    #include "assignments/Assignment.h"
    #include "assignments/AssignmentList.h"
    #include "statements/Statement.h"
    #include "statements/StatementSequence.h"
    #include "if_statement/IfStatement.h"
    #include "loops/WhileLoop.h"
    #include "loops/ForLoop.h"
    #include "system_out/Printer.h"
    #include "Program.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    ASSIGN "="
    SEMICOLON ";"
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"
    LPAREN "("
    RPAREN ")"
    LSQBRACKET "["
    RSQBRACKET "]"
    LCURBRACKET "{"
    RCURBRACKET "}"
    DOT "."
    YSYSTEM "System"  // Y stands for reserved words
    YOUT "out"
    YPRINT "print"
    YPRINTLN "println"
    YPUBLIC "public"
    YSTATIC "static"
    YCLASS "class"
    YSTRING "String"
    YINT "Integer"
    YBOOLEAN "Boolean"
    YVOID "void"
    ARGS "args"  // presently let args be special token

    TRUE "true"
    FALSE "false"
    AND "&&"
    OR "||"
    LESS "<"
    GREATER ">"
    EQUAL "=="
    NOTEQUAL "!="
    NEG "!"

    YIF "if"
    YELSE "else"

    YFOR "for"
    YWHILE "while"
;


%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%token <std::string> STRING "string"

%nterm <Program*> unit
%nterm <Type*> var_type
%nterm <Expression*> exp
%nterm <Assignment*> assignment
%nterm <Instantiation*> instantiation
%nterm <StatementSequence*> statement_sequence
%nterm <Statement*> statement
%nterm <Printer*> print
%nterm <BoolExpression*> bool_exp
%nterm <IfStatement*> if_statement
%nterm <WhileLoop*> while_loop
%nterm <ForLoop*> for_loop

%%
%start unit;

unit: "class" "identifier" "{" 
        "public" "static" "void" "identifier" "(" "String" "[" "]" "args" ")" "{"
            statement_sequence
        "}"
      "}" { $$ = new Program($15); driver.program = $$; };

statement_sequence:
    %empty { $$ = new StatementSequence(); }
    | statement_sequence statement { $1->AddStatement($2); $$ = $1; };

statement:
    print ";" { $$ = new Statement($1); }
    | instantiation ";" {$$ = new Statement($1); }
    | assignment ";" { $$ = new Statement($1); }
    | exp ";" { $$ = new Statement($1); }
    | if_statement { $$ = new Statement($1); }
    | while_loop { $$ = new Statement($1); }
    | for_loop { $$ = new Statement($1); };

print:
    "System" "." "out" "." "print" "(" exp ")" { $$ = new Printer($7, false); }
    | "System" "." "out" "." "println" "(" exp ")" { $$ = new Printer($7, true); };

instantiation:
    var_type "identifier" "=" exp { $$ = new Instantiation($1, $2, $4); }
    | var_type "identifier" { $$ = new Instantiation($1, $2); };

var_type:
    YSTRING { $$ = new Type(Type::STRING); }
    | YINT { $$ = new Type(Type::INT); }
    | YBOOLEAN { $$ = new Type(Type::BOOL); }
    | YVOID { $$ = new Type(Type::VOID); };

assignment:
    "identifier" "=" exp {
        $$ = new Assignment($1, $3);
    };

if_statement:
    "if" "(" exp ")" "{" statement_sequence "}" { $$ = new IfStatement($3, $6); }
    | "if" "(" exp ")" "{" statement_sequence "}" 
      "else" "{" statement_sequence "}" { $$ = new IfStatement($3, $6, $10); }
    | "if" "(" exp ")" "{" statement_sequence "}" 
      "else" if_statement { $$ = new IfStatement($3, $6, $9); };

while_loop:
    "while" "(" exp ")" "{" statement_sequence "}" { $$ = new WhileLoop($3, $6); };

for_loop:
    "for" "(" ";" exp ";" assignment ")" "{" statement_sequence "}" { $$ = new ForLoop($4, $6, $9); }


%left "+" "-";
%left "*" "/";
%left "&&" "||";
%left "==" "!=";

exp:
    "number" { $$ = new NumberExpression($1); }
    | "string" { $$ = new StringExpression($1); }
    | bool_exp { $$ = $1; }
    | "identifier" { $$ = new IdentExpression($1); }
    | "(" exp ")" { $$ = $2; }
    | exp "+" exp { $$ = new AddExpression($1, $3); }
    | exp "-" exp { $$ = new SubstractExpression($1, $3); }
    | exp "*" exp { $$ = new MulExpression($1, $3); }
    | exp "/" exp { $$ = new DivExpression($1, $3); }
    | exp "&&" exp { $$ = new AndExpression($1, $3); }
    | exp "||" exp { $$ = new OrExpression($1, $3); }
    | exp "<" exp { $$ = new LessExpression($1, $3); }
    | exp ">" exp { $$ = new LessExpression($3, $1); }
    | exp "==" exp { $$ = new EqualExpression($1, $3); }
    | exp "!=" exp { $$ = new NotEqualExpression($1, $3); }
    | "!" exp { $$ = new NegExpression($2); };

bool_exp:
    "true" { $$ = new BoolExpression(true); }
    | "false" { $$ = new BoolExpression(false); };

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
