#include "header.h"

int main(void) 
{
    double i_exact, s_approx, K, delta, delta1, delta2;

    double area = triangle_area(x_1, y_1, x_2, y_2, x_3, y_3);

    std::vector<std::vector<std::vector<double>>> all_X;
    std::vector<std::vector<std::vector<double>>> all_Y;

    printf("\n--- Таблица 1 ---\n");
    printf("r+s   r    s        delta_rs\n");
    printf("-------------------------------------\n");
    
    int max_degree = 3;

    for (int degree = 0; degree <= max_degree; degree++) 
    {
        for (int r = 0; r <= degree; r++) 
        {
            int s = degree - r;

            i_exact = I_general(r, s, x_1, y_1, x_2, y_2, x_3, y_3);
            if (std::abs(i_exact) < 1e-15) continue;
                K = 1.0 / i_exact;

            s_approx = S_approx(r, s, w, eta, deg, area, x_1, y_1, x_2, y_2, x_3, y_3) * K;
            
            delta = std::abs(s_approx - 1.0);

            printf("%d     %d    %d        %.3e\n", degree, r, s, delta);
        }

        printf("-------------------------------------\n");
    }

    
    int r = 1, s = 2;

    i_exact = I_general(r, s, x_1, y_1, x_2, y_2, x_3, y_3);
    K = 1.0 / i_exact;
    s_approx = S_approx(r, s, w, eta, deg, area, x_1, y_1, x_2, y_2, x_3, y_3) * K;        
    delta1 = std::abs(s_approx - 1.0);

    generate_subdivisions(x_1, y_1, x_2, y_2, x_3, y_3, 4, all_X, all_Y);

    printf("\n--- Таблица 2 ---\n");
    printf("r = %d    s = %d\n", r, s);

    for(int l = 0; l <= 4; l++)
    {
        s_approx = 0;

        for(int i = 0; i < std::pow(4, l); i++)
        {
            s_approx += S_approx(r, s, w, eta, deg, area, all_X[l][i][0], all_Y[l][i][0], all_X[l][i][1], all_Y[l][i][1], all_X[l][i][2], all_Y[l][i][2]);
        }

        delta2 = std::abs(s_approx * K - 1.0);

        printf("l = %d, delta2 = %.3e, delta1/delta2 = %.3e\n", l, delta2, delta1/delta2);

        delta1 = delta2;
        area /= 4;
    }

    return 0;
}