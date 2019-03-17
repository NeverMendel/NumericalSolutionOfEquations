#ifndef SOLUTIONMETHOD_H
#define SOLUTIONMETHOD_H

typedef unsigned int uint;

#include <QChart>
#include "expression.h"

class SolutionMethod
{
public:
    SolutionMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, double accuracy);
    ~SolutionMethod(){}
    virtual void next(uint steps = 1) = 0;
    virtual double getCurrentResult() = 0;
    virtual void display() = 0;
    bool hasFinished();
    uint getCurrentStep();
protected:
    QtCharts::QChart *chart;
    uint currentStep;
    Expression *expression;
    double lowerBound;
    double upperBound;
    double accuracy;
    bool finished;
private:
    uint totalSteps;
};

#endif // SOLUTIONMETHOD_H
