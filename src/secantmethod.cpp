#include "secantmethod.h"

SecantMethod::SecantMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, double accuracy) : SolutionMethod (expression, chart, lowerBound, upperBound, accuracy)
{
    previous = upperBound;
    current = lowerBound;

    line = nullptr;
}

void SecantMethod::next(uint steps)
{
    if(hasFinished()) return;
    for(uint i = 0; i < steps; i++){
        currentStep++;
        double next = current - (previous-current) / (expression->solve(previous) - expression->solve(current)) * expression->solve(current);
        current = next;

        if(abs(expression->solve(current)) < accuracy){
            printf("The solution of the equation is %f \n", next);
            finished = true;
            return;
        }
    }
    fflush(stdout);
}

double SecantMethod::getCurrentResult()
{
    return current;
}

void SecantMethod::display()
{
    if(hasFinished()){
        displayIntersectionPointLine();
    }
    if(line)
        chart->removeSeries(line);

    line = new QLineSeries();
    *line << QPointF(previous, expression->solve(previous)) << QPointF(current, expression->solve(current));
    line->setColor(Qt::red);
    QPen pen = line->pen();
    pen.setWidth(2);
    line->setPen(pen);
    chart->addSeries(line);
}
