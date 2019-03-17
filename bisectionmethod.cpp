#include "bisectionmethod.h"

BisectionMethod::BisectionMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, uint steps) : SolutionMethod (expression, chart, lowerBound, upperBound, steps)
{};

void BisectionMethod::next(uint steps)
{
    for(uint i = 0; i < steps; i++){
        printf("lowerBound: %f, upperBound: %f, mid: %f", lowerBound, upperBound, mid);
        mid = (upperBound + lowerBound) / 2;
        expression->addVariable("x", mid);
        double res = expression->solve();
        printf("res: %f", res);
        if(abs(res) < 0.1){// the solution is within 0.1 of error
            //mid is the correct solution
            printf("The solution of the equation is %f", mid);
            return;
        } else {
            double valueDerivative = expression->derivative();
            printf("valueDerivative: %f", valueDerivative);
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
        fflush(stdout);
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
