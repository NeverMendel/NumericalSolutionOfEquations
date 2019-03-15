#include "bisectionmethod.h"

BisectionMethod::BisectionMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, uint steps) : SolutionMethod (expression, chart, lowerBound, upperBound, steps)
{};

void BisectionMethod::next(uint steps)
{
    expression->addVariable("x", mid);
    for(uint i = 0; i < steps; i++){
        printf("lowerBound: %f, upperBound: %f", lowerBound, upperBound);
        mid = (upperBound + lowerBound) / 2;
        double res = expression->solve();
        if(res == 0.0){
            //mid is the correct solution
            printf("The solution of the equation is %f", mid);
            return;
        } else {
            double valueDerivative = expression->derivative();
            if(valueDerivative > 0){
                if(res>0)
                    upperBound = mid;
                else
                    lowerBound = mid;
            } else if (valueDerivative < 0){
                if(res>0)
                    lowerBound = mid;
                else
                    upperBound = mid;
            } else {
                printf("Error, derivative in %f is 0", mid);
                return;
            }
        }
    }
}

double BisectionMethod::getCurrentResult()
{
    return mid;
}

void BisectionMethod::display()
{
    //TODO display lowerbound and upperbound line
}
