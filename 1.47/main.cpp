#include "header.h"

int main(int argc, char* argv[]) 
{    
    if(argc != 3)
    {
        printf("Usage: %s alpha delta\n", argv[0]);
        return 1;
    }

    double alpha = std::stod(argv[1]);
    double delta = std::stod(argv[2]);

    const double k = 0.1; 
    double C = 3.0 - alpha / 3.0; 
    double x_prev = 0.0; 
    double x_curr = 0.0;    

    if(std::abs(C) > F(1))
    {
        printf("alpha = %lf, уравнение не имеет решений\n", alpha);
        return 0;
    }

    bool converged = false;
    for(int i = 0; i < MAX_ITERATIONS; i++) 
    {   
        double integral_value = F(x_prev);

        x_curr = x_prev - k * (integral_value - C);

        //std::cout << "Итерация " << i + 1 << ": x = " << x_curr << ", |x_curr - x_prev| = " << std::abs(x_curr - x_prev) << std::endl;

        if(std::abs(x_curr) > 1e-10)
        {
            if (std::abs(x_curr - x_prev) < delta * std::abs(x_curr)) 
            {
                converged = true;
                break;
            }
        }
        else
        {
            if(std::abs(x_curr - x_prev) < delta)
            {
                converged = true;
                break;
            }
        }

        x_prev = x_curr;
    }
    
    printf("------------------------------------\n");
    if (converged) 
        printf("alpha = %lf, x = %.10lf\n", alpha, x_curr);
    else
        printf("Метод не сошелся за %d итераций\n", MAX_ITERATIONS);

    return 0;
}