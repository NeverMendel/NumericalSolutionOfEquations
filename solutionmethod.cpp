#include "solutionmethod.h"

SolutionMethod::SolutionMethod(Expression *e1, Expression *e2, QtCharts::QChart *chart, uint steps)
{
    this->e1 = e1;
    this->e2 = e2;
    this->chart = chart;
    totalSteps = steps;
}

uint SolutionMethod::getCurrentStep()
{
    return currentStep;
}

uint SolutionMethod::getTotalSteps()
{
    return totalSteps;
}

void SolutionMethod::setStep(uint step)
{
    currentStep = step;
}
