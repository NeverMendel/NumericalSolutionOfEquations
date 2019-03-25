#ifndef SECANTMETHOD_H
#define SECANTMETHOD_H

#include "solutionmethod.h"

using namespace std;

class SecantMethod : public SolutionMethod
{
public:
    SecantMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, double accuracy);
    void next();
    double getCurrentResult();
    void display();
private:
    double previous;
    double current;
    QLineSeries *line;
    double minY;
    double maxY;
};

#endif // SECANTMETHOD_H
