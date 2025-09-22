#include "header.h"

double func(double t) 
{
    if (1.0 + std::pow(t, 5) < 0) 
        return 0.0;

    return std::sqrt(1.0 + std::pow(t, 5));
}

double integrate(std::function<double(double)> func, double a, double b) 
{
    if (std::abs(a-b) < 1e-15) return 0.0;

    if (a > b) return -integrate(func, b, a);

    double h = (b - a) / N_INTEGRATION_STEPS;
    double sum = (func(a) + func(b)) / 2; 

    for(int i = 1; i < N_INTEGRATION_STEPS; i++) 
        sum += func(a + i * h);
        
    return sum * h;
}

double F(double x) 
{
    return integrate(func, -x, x);
}


