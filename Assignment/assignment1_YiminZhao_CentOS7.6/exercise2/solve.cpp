#include "solve.h"

vector<double> solve(double a, double b, double c){
    double deta = sqrt(b*b - 4*a*c);
    vector<double> v(2);
    v[0] = (-b + deta)/ 2*a;
    v[1] = (-b + deta)/ 2*a;
    return v;
}