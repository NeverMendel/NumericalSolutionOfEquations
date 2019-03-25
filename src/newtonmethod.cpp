#include "newtonmethod.h"

NewtonMethod::NewtonMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, double accuracy) : SolutionMethod (expression, chart, lowerBound, upperBound, accuracy)
{
    if(abs(expression->solve(lowerBound))>abs(expression->solve(upperBound)))
        current = lowerBound;
    else
        current = upperBound;
    nextPoint = current - (expression->solve(current) / expression->derivative(current));

    line = nullptr;
}

void NewtonMethod::next(uint steps)
{
    if(hasFinished()) return;
    for(uint i = 0; i < steps; i++){
        current = nextPoint;
        nextPoint = current - (expression->solve(current) / expression->derivative(current));
        currentStep++;

        if(abs(expression->solve(current)) < accuracy){
            printf("The solution of the equation is %f \n", current);
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
    if(line)
        chart->removeSeries(line);

    if(hasFinished())
        displayIntersectionPointLine();
    line = new QLineSeries();
    *line << QPointF(current, expression->solve(current)) << QPointF(nextPoint, 0);
    line->setColor(Qt::red);
    QPen pen = line->pen();
    pen.setWidth(2);
    line->setPen(pen);
    chart->addSeries(line);
}
