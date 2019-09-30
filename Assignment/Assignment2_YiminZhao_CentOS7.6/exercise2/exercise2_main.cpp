//
// Created by 18123 on 2019/9/25.
//
#include "NewtonInterpolation.h"
#include <iostream>
using namespace std;

int main() {
    double x;
    double ** m;
    m = new double *[7];
    for (int i = 0; i < 7; i++)
        m[i] = new double [7];
    NewtonInterpolation n1;
    n1.DividedDifferenceTable(m);

    while(true){
        cin >> x;
        if (cin.fail())
        {
            for (int i = 0; i < 7; i++)
                delete m[i];
            delete m;
            return -1;
        }
        n1.ApproximateValue(x, m);
    }
}
