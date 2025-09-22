#include <iostream>   
#include <cmath> 
#include <functional> 

const int N_INTEGRATION_STEPS = 100000; 
const int MAX_ITERATIONS = 10000; 

double func(double t);

double integrate(std::function<double(double)> func, double a, double b);

double F(double x);

