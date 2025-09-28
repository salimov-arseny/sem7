#include "header.h"

double fact(int n)
{
    double res = 1;

    if(n < 0)
        return 0;
    else
    {
        for(int i = 2; i <= n; i++)
            res *= i;
    }
    return res;
}

double comb(int n, int k)
{
    if(k < 0 || k > n) 
        return 0;

    if (k == 0 || k == n)
        return 1.0;

    if (k > n / 2) 
        k = n - k;

    double res = 1.0;
    for (int i = 1; i <= k; i++)
        res = res * (n - i + 1) / i;

    return res;
}

double multicomb(int n, int k1, int k2, int k3)
{
    if(k1 + k2 + k3 != n || k1 < 0 || k2 < 0 || k3 < 0)
        return 0;
    
    return comb(n, k1) * comb(n - k1, k2); 
}

double I_test(int r, int s)
{
    double sum = 0;
    double tmp = 0;

    for(int k = 0; k <= s + 1; k++)
    {
        if(k % 2 == 0)
            tmp = comb(s+1, k)/(r+k+1);
        else
            tmp = - comb(s+1, k)/(r+k+1);

        sum += tmp;
    }

    return std::pow(2.0, r+1)/(s+1)*sum;
}

double I_general(int r, int s)
{
    double sum = 0;

    int i1, i2, i3, j1, j2, j3;

    double k_r, k_s;

    double x_p, y_p;

    double integral_part;

    double detB = x_1 * (y_2 - y_3) + x_2 * (y_3 - y_1) + x_3 * (y_1 - y_2);

    for (i1 = 0; i1 <= r; ++i1) 
    {
        for (i2 = 0; i2 <= r - i1; ++i2) 
        {
            i3 = r - i1 - i2;
            for (j1 = 0; j1 <= s; ++j1) 
            {
                for (j2 = 0; j2 <= s - j1; ++j2) 
                {
                    j3 = s - j1 - j2;

                    k_r = multicomb(r, i1, i2, i3);
                    k_s = multicomb(s, j1, j2, j3);

                    x_p = std::pow(x_1, i1) * std::pow(x_2, i2) * std::pow(x_3, i3);
                    y_p = std::pow(y_1, j1) * std::pow(y_2, j2) * std::pow(y_3, j3);
                
                    integral_part = fact(i1 + j1) * fact(i2 + j2) * fact(i3 + j3);

                    sum += k_r * k_s *x_p * y_p * integral_part;
                }
            }
        }
    }

    return std::abs(detB) * sum / fact(r+s+2);
}