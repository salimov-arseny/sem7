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

double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return std::abs(x1 * (y_2 - y_3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
}

double I_general(int r, int s)
{
    double sum = 0;

    int i1, i2, i3, j1, j2, j3;

    double k_r, k_s;

    double x_p, y_p;

    double integral_part;

    double detB = triangle_area(x_1, y_1, x_2, y_2, x_3, y_3) * 2;

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

    return detB * sum / fact(r+s+2);
}

double S_approx(int r, int s, const std::vector<double>& w, const std::vector<std::vector<double>>& eta, const std::vector<int>& deg, double triangle_area)
{
    double total_sum = 0;
    double x, y, tmp;

    for (size_t i = 0; i < w.size(); i++) 
    {    
        std::vector<double> eta_temp = eta[i];
        std::sort(eta_temp.begin(), eta_temp.end());

        std::vector<std::vector<double>> permutations;

        
        for(int j = 0; j < deg[i]; j++)
        {
            permutations.push_back(eta_temp);
            std::next_permutation(eta_temp.begin(), eta_temp.end());
        }

        for (const auto& p : permutations) 
        {
            x = p[0] * x_1 + p[1] * x_2 + p[2] * x_3;
            y = p[0] * y_1 + p[1] * y_2 + p[2] * y_3;

            if (std::abs(x) < eps && r == 0 && std::abs(y) < eps && s == 0) tmp = 1;
            else if (std::abs(x) < eps && r == 0) tmp = std::pow(y, s);
            else if (std::abs(y) < eps && s == 0) tmp = std::pow(x, r);
            else tmp = std::pow(x, r) * std::pow(y, s);

            total_sum += w[i] * tmp;
        }
    }
    
    return triangle_area * total_sum;
}