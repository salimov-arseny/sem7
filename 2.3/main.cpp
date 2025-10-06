#include "header.h"

int main(void) 
{
    double i_exact, s_approx, K, delta;

    double area = triangle_area(x_1, y_1, x_2, y_2, x_3, y_3);

    printf("\n--- Таблица 1 ---\n");
    printf("r+s   r    s        delta_rs\n");
    printf("-------------------------------------\n");
    
    int max_degree = 5;

    for (int degree = 0; degree <= max_degree; degree++) 
    {
        for (int r = 0; r <= degree; r++) 
        {
            int s = degree - r;

            i_exact = I_general(r, s);
            if (std::abs(i_exact) < 1e-15) continue;
                K = 1.0 / i_exact;

            s_approx = S_approx(r, s, w, eta, deg, area) * K;
            
            delta = std::abs(s_approx - 1.0);

            printf("%d     %d    %d        %.3e\n", degree, r, s, delta);
        }
        if (degree < max_degree) 
            printf("-------------------------------------\n");
    }

    return 0;
}