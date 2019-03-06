#include "solutionmethod.h"

SolutionMethod::SolutionMethod(QtCharts::QChart *chart, uint steps)
{
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
