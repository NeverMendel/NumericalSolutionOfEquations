#ifndef BISECTIONMETHOD_H
#define BISECTIONMETHOD_H

#include "solutionmethod.h"
#include "expression.h"
#include <QtCharts>

class BisectionMethod : public SolutionMethod
{
public:
    BisectionMethod();
    void nextStep();
    void previousStep();
};

#endif // BISECTIONMETHOD_H
