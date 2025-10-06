#include <iostream>   
#include <cmath> 
#include <functional>
#include <iomanip>

const double eps = 1e-14;

// ТРЕУГОЛЬНИК 0

// const double x_1 = 0;
// const double y_1 = 0;

// const double x_2 = 0;
// const double y_2 = 1;

// const double x_3 = 2;
// const double y_3 = 0;


// ТРЕУГОЛЬНИК 1

const double x_1 = 0;
const double y_1 = 0.5;

const double x_2 = 2;
const double y_2 = 0.5;

const double x_3 = 0;
const double y_3 = 1.5;


//ТРЕУГОЛЬНИК 2

// const double x_1 = 0.7;
// const double y_1 = 0;

// const double x_2 = 2.7;
// const double y_2 = 0;

// const double x_3 = 0.7;
// const double y_3 = 1;


//ТРЕУГОЛЬНИК 3

// const double x_1 = 1;
// const double y_1 = 1;

// const double x_2 = 3;
// const double y_2 = 1;

// const double x_3 = 1;
// const double y_3 = 2;

const std::vector<double> w = 
{
    1.0 / 3
};

const std::vector<std::vector<double>> eta = 
{
    {0, 1.0 / 2, 1.0 / 2}
};

const std::vector<int> deg = 
{
    3
};

double fact(int n);
double comb(int n, int k);
double multicomb(int n, int k1, int k2, int k3);

double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3);
double I_general(int r, int s);
double S_approx(int r, int s, const std::vector<double>& w, const std::vector<std::vector<double>>& eta, const std::vector<int>& deg, double triangle_area); 