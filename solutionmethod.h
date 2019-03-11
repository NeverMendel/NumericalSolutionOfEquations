#ifndef SOLUTIONMETHOD_H
#define SOLUTIONMETHOD_H

typedef unsigned int uint;

#include <QChart>
#include "expression.h"

class SolutionMethod
{
public:
    SolutionMethod(Expression *e1, Expression *e2, QtCharts::QChart *chart, int lowerBound, int upperBound, uint steps);
    virtual void nextStep() = 0;
    virtual void previousStep() = 0;
    uint getCurrentStep();
    uint getTotalSteps();
    void setStep(uint step);
protected:
    QtCharts::QChart *chart;
    uint currentStep;
    Expression *e1, *e2;
    int lowerBound;
    int upperBound;
private:
    uint totalSteps;
};

#endif // SOLUTIONMETHOD_H
