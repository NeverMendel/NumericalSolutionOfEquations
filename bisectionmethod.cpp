#include "bisectionmethod.h"

BisectionMethod::BisectionMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, double accuracy) : SolutionMethod (expression, chart, lowerBound, upperBound, accuracy)
{};

void BisectionMethod::next(uint steps)
{
    if(hasFinished()) return;
    for(uint i = 0; i < steps; i++){
        mid = (upperBound + lowerBound) / 2;
        printf("lowerBound: %f, upperBound: %f, mid: %f, accuracy: %f \n", lowerBound, upperBound, mid, accuracy);
        expression->addVariable("x", mid);
        double res = expression->solve();
        printf("res: %f \n", res);
        if(abs(res) < accuracy){// the solution is within the desired accuracy
            //mid is the correct solution
            finished = true;
            printf("The solution of the equation is %f \n", mid);
            return;
        } else {
            double valueDerivative = expression->derivative();
            printf("valueDerivative: %f \n", valueDerivative);
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
                finished = true;
                printf("Error, derivative in %f is 0 \n", mid);
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
