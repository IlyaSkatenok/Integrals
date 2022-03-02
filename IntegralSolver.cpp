#include "Integrals.h"

double rectangle(double aL, double bH, int n)
{
    double step = (bH - aL) / n;

    double result = 0;

    for (int i = 0; i < n; i++)
    {
        result += formulaFunc(aL + step * (i + 0.5));
    }

    result *= step;
    return result;
}

double trapezoid(double aL, double bH, int Incount)
{
    double step = (bH - aL) / Incount;

    double result = formulaFunc(aL) + formulaFunc(bH);

    for (int i = 1; i < Incount; i++)
    {
        result += 2 * formulaFunc(aL + i * step);
    }

    result *= step / 2;
    return result;
}

double Simpson(double aL, double bH, int Incount)
{
    double oddSum = 0.0, evenSum = 0.0;

    double step = (bH - aL) / Incount;

    double result = (formulaFunc(aL) + formulaFunc(bH));

    double lim = Incount / 2;

    for (int i = 1; i <= lim; i++)
    {
        oddSum += formulaFunc(aL + (2 * i - 1) * step);
    }

    oddSum *= 4;

    for (int i = 1; i < lim; i++)
    {
        evenSum += formulaFunc(aL + (2 * i) * step);
    }

    evenSum *= 2;
    result += oddSum + evenSum;
    result *= (step / 3);
    return result;
}


