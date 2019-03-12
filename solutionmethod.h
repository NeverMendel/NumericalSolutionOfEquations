#ifndef SOLUTIONMETHOD_H
#define SOLUTIONMETHOD_H

typedef unsigned int uint;

#include <QChart>
#include "expression.h"

class SolutionMethod
{
public:
    SolutionMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, uint steps);
    virtual void nextStep() = 0;
    virtual void previousStep() = 0;
    virtual double getResult() = 0;
    uint getCurrentStep();
    uint getTotalSteps();
    void setStep(uint step);
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
