//
// Created by 18123 on 2019/9/25.
//
#include "NewtonInterpolation.h"
#include <iostream>
using namespace std;

NewtonInterpolation::NewtonInterpolation()  {};

void NewtonInterpolation::DividedDifferenceTable(double **m){
    for(int i = 0; i < 7; i ++) {
        m[i][0] = y[i];
        //cout << m[i][0] <<endl;
    }

    for(int j = 1; j < 7; j++) //列遍历（从第一列到第六列）
        for(int i = j; i < 7; i++)
        {
            //cout << "m["<<i<<"]["<<j<<"] = (m["<<i <<"]["<<j-1<<"] - m["<<i -1<<"]["<<j-1<<"]) / (x["<<i<<"] - x["<<i-j<<"])"<<endl;
            //cout << "m["<<i<<"]["<<j<<"] = (" << m[i][j-1] << "-" << m[i-1][j-1] <<") / ("<<x[i]<<'-'<<x[i-j]<<" = "<<(m[i][j-1] - m[i-1][j-1]) / (x[i] - x[i-j])<<endl;
            m[i][j] = (m[i][j-1] - m[i-1][j-1]) / (x[i] - x[i-j]);
        }


    /// 输出

    for (int i = 0; i < 7; i++){
        for (int j = 0; j <= i; j++){
            cout.width(15);
            cout << m[i][j];
        }
        cout << endl;
    }

}

void NewtonInterpolation::ApproximateValue(double d, double **m){
    double answer = m[0][0];
    double tmp = 1;
    for (int i = 1; i < 7; i++){
        tmp *= (d - x[i - 1]);
        answer += m[i][i] * tmp;
    }
    cout << answer <<endl;
}