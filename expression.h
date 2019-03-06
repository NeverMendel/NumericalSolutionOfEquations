#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string.h>

#include "exprtk.hpp"

using namespace exprtk;

class Expression
{
public:
    Expression(std::string expression_str);
    void setVariable(std::string variable, double value);
    double solve();

private:
    symbol_table<double> symbol_table;
    expression<double> expression;
    parser<double> parser;
    std::string expression_str;
};

#endif // EXPRESSION_H
