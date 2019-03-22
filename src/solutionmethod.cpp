#include "solutionmethod.h"

#define RESOLUTION 100

SolutionMethod::SolutionMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, double accuracy)
{
    this->expression = expression;
    this->chart = chart;
    this->lowerBound = lowerBound;
    this->upperBound = upperBound;
    this->accuracy = accuracy;
    currentStep = 0;
    finished = false;
    minY = numeric_limits<double>::max();
    maxY = numeric_limits<double>::min();
    double increment = (upperBound - lowerBound) / RESOLUTION;
    for(double pos = lowerBound; pos <= upperBound; pos+= increment){
        double current = expression->solve(pos);
        if(!isinf(current)){
            minY = min(minY, current);
            maxY = max(maxY, current);
        }
    }
    printf("min: %f max:%f \n", minY, maxY);
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
