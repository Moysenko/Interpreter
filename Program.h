#pragma once

#include "statements/StatementSequence.h"

class Program {
 public:
    Program(StatementSequence* statements);
    StatementSequence* statements_;
};