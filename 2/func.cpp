#include "header.h"

double get_K(double a, double b, int r)
{
    double a_pow, b_pow;

    if(std::abs(a) < eps)
        a_pow = 0;
    else
        a_pow = std::pow(a, r + 1);

    if(std::abs(b) < eps)
        b_pow = 0;
    else
        b_pow = std::pow(b, r + 1);    

    return (b_pow - a_pow) / (r + 1);
}

double S_f(double a, double b, int r)
{
    std::vector<double> w = {w1, w2, w3, w4};
    std::vector<double> d = {d1, d2, d3, d4};

    double arg, arg_pow;
    double res = 0;

    for(int i = 0; i < m; i++)
    {
        arg = (a + b)/2 + d[i] * (b - a)/2;

        if(std::abs(arg) < eps)
            arg_pow = 0;
        else
            arg_pow = std::pow(arg, r);

        res += w[i] * arg_pow;
    }

    return res * (b-a);
}

