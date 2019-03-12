#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string.h>
#include <map>

#include "exprtk.hpp"

using namespace exprtk;

class Expression
{
public:
    Expression(std::string expression_str);
    void addVariable(std::string variable, double value);
    void changeVariable(std::string variable, double delta);
    double getVariable(std::string variable);
    double solve();
    double derivative();

private:
    symbol_table<double> symbol_table;
    expression<double> expression;
    parser<double> parser;
    std::string expression_str;
    std::map<std::string, double> variables;
};

#endif // EXPRESSION_H
