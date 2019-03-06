#include "expression.h"

Expression::Expression(std::string expression_str)
{
    this->expression_str = expression_str;
}

void Expression::setVariable(std::string variable, double value)
{
    symbol_table.add_variable(variable, value);
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

