#ifndef NEWTONTMETHOD_H
#define NEWTONTMETHOD_H

#include "solutionmethod.h"

#include <QtCharts>

using namespace std;

class NewtonMethod : public SolutionMethod
{
public:
    NewtonMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, double accuracy);
    void next(uint steps = 1);
    double getCurrentResult();
    void display();
private:
    double previous;
    double current;
    double nextPoint;
    QLineSeries *line;
};

#endif // NEWTONTMETHOD_H
