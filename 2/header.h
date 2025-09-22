#include <iostream>   
#include <cmath> 
#include <functional> 

const double eps = 1e-15;

const int m = 4;
const double w1 = (18 + std::sqrt(30))/72;
const double w2 = (18 - std::sqrt(30))/72;
const double w3 = (18 - std::sqrt(30))/72;
const double w4 = (18 + std::sqrt(30))/72;

const double d1 = -std::sqrt((15 - 2*std::sqrt(30))/35);
const double d2 = -std::sqrt((15 + 2*std::sqrt(30))/35);
const double d3 =  std::sqrt((15 + 2*std::sqrt(30))/35);
const double d4 =  std::sqrt((15 - 2*std::sqrt(30))/35);

const double a = 0;
const double b = 1;

double get_K(double a, double b, int r);

double S_f(double a, double b, int r);
