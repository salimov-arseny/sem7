#include "header.h"

int main(void) 
{    
    int r = 0, k;

    double delta, K, S;

    double delta1, delta2, h, a1, b1;

    for(r = 0; r < 10; r++)
    {
        K = get_K(a, b, r);

        S = S_f(a, b , r);

        delta = std::abs(S/K - 1);

        printf("r = %d, delta_r = %.3e\n", r, delta);

        if(delta > eps)
            break;
    }

    K = get_K(a, b, r);

    std::cout << std::endl;

    delta1 = delta;

    for(int l = 1; l < 6; l++)
    {
        k = std::pow(2, l);
        S = 0;
        h = (b-a) / k;

        for(int j = 0; j < k; j++)
        {
            a1 = a + j * h;
            b1 = a + (j + 1) * h;

            S += S_f(a1, b1, r);
        }

        delta2 = std::abs(S/K - 1);

        printf("l = %d, delta2 = %.3e, delta1/delta2 = %.3e\n", l, delta2, delta1/delta2);

        delta1 = delta2;
    }

    return 0;
}