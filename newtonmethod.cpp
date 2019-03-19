#include "newtonmethod.h"

NewtonMethod::NewtonMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, double accuracy) : SolutionMethod (expression, chart, lowerBound, upperBound, accuracy)
{
    current = lowerBound;
    nextPoint= lowerBound;
    line = nullptr;
}

void NewtonMethod::next(uint steps)
{
    if(hasFinished()) return;
    for(uint i = 0; i < steps; i++){
        currentStep++;
        current= nextPoint;
        nextPoint = current-(expression->solve(current)/expression->derivative(current));

        printf("previous: %f, derivative: %f", previous, expression->derivative(previous));

        if(abs(expression->solve(current)) < accuracy){
                printf("result is %f", current);
                finished = true;
                return;
        }
        fflush(stdout);
    }
}

double NewtonMethod::getCurrentResult()
{
    return current;
}

void NewtonMethod::display()
{
    if(line) chart->removeSeries(line);

    if(currentStep>0)
    {
        line = new QLineSeries();
        *line << QPointF(current, expression->solve(current)) << QPointF(nextPoint, 0);
        line->setColor(Qt::red);
        QPen pen = line->pen();
        pen.setWidth(2);
        line->setPen(pen);
        chart->addSeries(line);
    }
}
