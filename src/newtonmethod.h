#ifndef NEWTONTMETHOD_H
#define NEWTONTMETHOD_H

#include "solutionmethod.h"

using namespace std;

class NewtonMethod : public SolutionMethod
{
public:
    NewtonMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, double accuracy);
    void next();
    double getCurrentResult();
    void display();
private:
    double current;
    double nextPoint;
    QLineSeries *line;
};

#endif // NEWTONTMETHOD_H
