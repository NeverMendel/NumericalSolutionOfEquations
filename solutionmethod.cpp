#include "solutionmethod.h"

SolutionMethod::SolutionMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, double accuracy)
{
    this->expression = expression;
    this->chart = chart;
    this->lowerBound = lowerBound;
    this->upperBound = upperBound;
    this->accuracy = accuracy;
    currentStep = 0;
    finished = false;
    double lbValue = expression->solve(lowerBound);
    double ubValue = expression->solve(upperBound);
    minY = std::min(lbValue, ubValue);
    maxY = std::max(lbValue, ubValue);
}

void SolutionMethod::displayIntersectionPointLine()
{
    QLineSeries *intersectionPointSeries = new QLineSeries();
    *intersectionPointSeries << QPointF(getCurrentResult(), maxY) << QPointF(getCurrentResult(), minY);
    intersectionPointSeries->setColor(Qt::blue);
    chart->addSeries(intersectionPointSeries);
}

void SolutionMethod::finish()
{
    while(!hasFinished()){
        next();
    };
}

bool SolutionMethod::hasFinished()
{
    return finished;
}

uint SolutionMethod::getCurrentStep()
{
    return currentStep;
}
