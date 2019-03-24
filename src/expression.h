#ifndef EXPRESSION_H
#define EXPRESSION_H

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
    double solve(double xValue);
    double derivative();
    double derivative(double xValue);
    double second_derivative();
    double second_derivative(double xValue);

private:
    symbol_table<double> symbol_table;
    expression<double> expression;
    parser<double> parser;
    std::string expression_str;
    std::map<std::string, double> variables;
};

#endif // EXPRESSION_H
