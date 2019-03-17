#include "bisectionmethod.h"

BisectionMethod::BisectionMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, double accuracy) : SolutionMethod (expression, chart, lowerBound, upperBound, accuracy)
{
    double lbValue = expression->solve(lowerBound);
    double ubValue = expression->solve(upperBound);
    minY = std::min(lbValue, ubValue);
    maxY = std::max(lbValue, ubValue);
    printf("min: %f, max: %f", minY, maxY);
    lowerBoundSeries = nullptr;
    upperBoundSeries = nullptr;
}

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
        currentStep++;
        fflush(stdout);
    }
}

double BisectionMethod::getCurrentResult()
{
    return mid;
}

void BisectionMethod::display()
{
    if(!hasFinished()){
        if(lowerBoundSeries)
            chart->removeSeries(lowerBoundSeries);
        if(upperBoundSeries)
            chart->removeSeries(upperBoundSeries);

        lowerBoundSeries = new QLineSeries();
        *lowerBoundSeries << QPointF(lowerBound, maxY) << QPointF(lowerBound, minY);
        lowerBoundSeries->setColor(Qt::red);
        chart->addSeries(lowerBoundSeries);


        upperBoundSeries = new QLineSeries();
        *upperBoundSeries << QPointF(upperBound, maxY) << QPointF(upperBound, minY);
        upperBoundSeries->setColor(Qt::red);
        chart->addSeries(upperBoundSeries);
    } else {
        QLineSeries *lowerBoundSeries = new QLineSeries();
        *lowerBoundSeries << QPointF(mid, maxY) << QPointF(mid, minY);
        lowerBoundSeries->setColor(Qt::blue);
        chart->addSeries(lowerBoundSeries);

        printf("Finished");
    }
}
