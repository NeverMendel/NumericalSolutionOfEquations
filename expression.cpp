#include "expression.h"

Expression::Expression(std::string expression_str)
{
    this->expression_str = expression_str;
}

void Expression::addVariable(std::string variable, double value)
{
    if(variables.count(variable) == 0){
        variables.insert(std::make_pair(variable, value));
        symbol_table.add_variable(variable, variables[variable]);
    } else {
        variables[variable] = value;
    }
}

void Expression::changeVariable(std::string variable, double delta)
{
    variables[variable] += delta;
}

double Expression::getVariable(std::string variable)
{
    return variables[variable];
}

double Expression::solve()
{
    symbol_table.add_constants();
    expression.register_symbol_table(symbol_table);
    if(!parser.compile(expression_str, expression))
    {
        printf("Error: %s\tExpression: %s\n",
                     parser.error().c_str(),
                     expression_str.c_str());
    }
    return expression.value();
}

double Expression::derivative()
{
    return exprtk::derivative(expression, variables["x"]);
}

