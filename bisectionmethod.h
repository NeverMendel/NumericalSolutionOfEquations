#ifndef BISECTIONMETHOD_H
#define BISECTIONMETHOD_H

#include "solutionmethod.h"
#include "expression.h"
#include <QtCharts>

class BisectionMethod : public SolutionMethod
{
public:
    BisectionMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, double accuracy);
    void next(uint steps = 1);
    double getCurrentResult();
    void display();
private:
    double mid;
    QLineSeries *lowerBoundSeries;
    QLineSeries *upperBoundSeries;
};

#endif // BISECTIONMETHOD_H
