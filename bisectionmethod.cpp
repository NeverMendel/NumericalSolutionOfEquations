#include "bisectionmethod.h"

void BisectionMethod::nextStep()
{
    double mid = (upperBound + lowerBound) / 2;
    e1->addVariable("x", mid);
    double r1 = e1->solve();
    double r2 = e2->solve();
    if(r2 - r1 > 0){
        if(isIncreasingFunction)
            lowerBound = mid;
        else
            upperBound = mid;
    } else if (r2 - r1 < 0){
        if(isIncreasingFunction)
            upperBound = mid;
        else
            lowerBound = mid;
    } else {
        //mid is the correct solution
    }
}
