#include "secantmethod.h"

SecantMethod::SecantMethod(Expression *expression, QtCharts::QChart *chart, double lowerBound, double upperBound, double accuracy) : SolutionMethod (expression, chart, lowerBound, upperBound, accuracy)
{
    previous = lowerBound;
    current= upperBound;

    line = nullptr;
}

void SecantMethod::next(uint steps)
{
    if(hasFinished()) return;
    if(currentStep==0){
        current = lowerBound-(((upperBound-lowerBound)/(expression->solve(upperBound) - expression->solve(lowerBound)))*expression->solve(lowerBound));

        if(abs(lowerBound-current)>abs(upperBound-current)) previous= lowerBound;
        else previous= upperBound;

        printf("previous: %f current:%f", previous, current);fflush(stdout);
    }
    for(uint i = 0; i < steps; i++){
        currentStep++;
        double next = current-(previous-current)/(expression->solve(previous)-expression->solve(current))*expression->solve(current);
        printf("%f", next);
        //previous = current;
        current = next;
        if(abs(expression->solve(current)) < accuracy){
                printf("result is %f", next);
                finished = true;
        }
        fflush(stdout);
    }
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
