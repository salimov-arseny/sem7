#include "header.h"

int main(int argc, char* argv[]) 
{
    if(argc != 3)
    {
        printf("Введите значение степеней r, s\n");
        return -1;
    }

    int r, s;

    r = std::stoi(argv[1]);
    s = std::stoi(argv[2]);

    double i_general = I_general(r, s);
    double i_test = I_test(r, s);
    double difference = std::abs(i_general - i_test);

    printf("Значение для общего треугольника (%.2lf, %.2lf),(%.2lf, %.2lf),(%.2lf, %.2lf): %.3e\n\n", x_1, y_1, x_2, y_2, x_3, y_3, i_general);

    printf("Значение для тестового треугольника (0,0),(0,1),(2,0): %.3e\n\n", i_test);

    //printf("r = %d, s = %d ,", r, s);

    printf("Модуль разности: %.3e\n", difference);

    return 0;
}