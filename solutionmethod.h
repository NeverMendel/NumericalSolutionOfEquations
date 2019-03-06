#ifndef SOLUTIONMETHOD_H
#define SOLUTIONMETHOD_H

typedef unsigned int uint;

#include <QChart>

class SolutionMethod
{
public:
    SolutionMethod(QtCharts::QChart *chart, uint steps);
    virtual void nextStep();
    virtual void previousStep();
    uint getCurrentStep();
    uint getTotalSteps();
protected:
    QtCharts::QChart *chart;
    uint totalSteps;
    uint currentStep;
};

#endif // SOLUTIONMETHOD_H
