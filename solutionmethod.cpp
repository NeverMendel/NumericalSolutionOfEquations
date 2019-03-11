#include "solutionmethod.h"

SolutionMethod::SolutionMethod(Expression *e1, Expression *e2, QtCharts::QChart *chart, int lowerBound, int upperBound, uint steps)
{
    this->e1 = e1;
    this->e2 = e2;
    this->chart = chart;
    this->lowerBound = lowerBound;
    this->upperBound = upperBound;
    totalSteps = steps;
    //calculate isIncreasing
    e1->addVariable("x", lowerBound);
    e2->addVariable("x", lowerBound);
    double start = e2->solve() - e1->solve();
    e1->addVariable("x", upperBound);
    e2->addVariable("x", upperBound);
    double end = e2->solve() - e1->solve();
    isIncreasingFunction = end > start;
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
