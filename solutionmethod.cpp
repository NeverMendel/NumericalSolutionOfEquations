#include "solutionmethod.h"

SolutionMethod::SolutionMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, double accuracy)
{
    this->expression = expression;
    this->chart = chart;
    this->lowerBound = lowerBound;
    this->upperBound = upperBound;
    this->accuracy = accuracy;
    finished = false;
}

bool SolutionMethod::hasFinished()
{
    return finished;
}

uint SolutionMethod::getCurrentStep()
{
    return currentStep;
}
