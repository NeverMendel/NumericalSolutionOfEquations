#ifndef BISECTIONMETHOD_H
#define BISECTIONMETHOD_H

#include "solutionmethod.h"
#include "expression.h"
#include <QtCharts>

class BisectionMethod : public SolutionMethod
{
public:
    BisectionMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, uint steps);
    void nextStep();
    void previousStep();
    double getResult();
};

#endif // BISECTIONMETHOD_H
