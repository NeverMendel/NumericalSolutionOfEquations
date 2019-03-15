#ifndef SOLUTIONMETHOD_H
#define SOLUTIONMETHOD_H

typedef unsigned int uint;

#include <QChart>
#include "expression.h"

class SolutionMethod
{
public:
    SolutionMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, uint steps);
    virtual void next(uint steps = 1) = 0;
    virtual double getCurrentResult() = 0;
    virtual void display() = 0;
    uint getCurrentStep();
    uint getTotalSteps();
protected:
    QtCharts::QChart *chart;
    uint currentStep;
    Expression *expression;
    double lowerBound;
    double upperBound;
private:
    uint totalSteps;
};

#endif // SOLUTIONMETHOD_H
