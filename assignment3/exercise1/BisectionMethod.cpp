//
// Created by 18123 on 2019/9/27.
//
#include <iostream>
#include <cmath>
using namespace std;

double f(double x);
inline double half(double a, double b){return (a+b)/2;}

int main() {
    double a = 0.28516;
    double b = 0.400912;
    double tmp = 100;
    int k = 0;
    const double sigma = 0.00001;
    while (fabs(tmp - half(a,b)) >= sigma){
        tmp = half(a,b);
        if (f(half(a,b)) == 0){
            cout << 'x' << k++ << ": " <<half(a,b) << endl;
            return 0;
        }
        else if(f(half(a,b)) > 0){
            cout << 'x' << k++ << ": " << half(a,b) << endl;
            b = half(a,b);
            continue;
        }
        else if(f(half(a,b)) < 0){
            cout << 'x' << k++ << ": " << half(a,b) << endl;
            a = half(a, b);
            continue;
        }

    }
    return 0;
}

double f(double x) {
    return 10 * x * x * x - 8.3 * x * x + 2.295 * x - 0.21141;
}