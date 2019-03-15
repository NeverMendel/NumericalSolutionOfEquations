#include "solutionmethod.h"

SolutionMethod::SolutionMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, uint steps)
{
    this->expression = expression;
    this->chart = chart;
    this->lowerBound = lowerBound;
    this->upperBound = upperBound;
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
