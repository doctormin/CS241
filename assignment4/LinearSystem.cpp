//
// Created by 18123 on 2019/10/4.
//
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

inline double clear_residual(const double x){
    if(x < 1e-6 && x > -1e-6) return 0.0;
    else return x;
}
int main() {
    int _num_;
    cout << "Input the number of equations and unknowns n:";
    cin >> _num_;
    cout << endl;
    const int num = _num_;
    if (cin.fail()) {
        cerr << "Invalid input!" << endl;
        return -1;
    }
    double a[num][num]; //coefficient matrix
    double b[num];  // constants vector
    double x[num];  //root vector
    cout << "Input the augmented matrix of Ax=b as [A b]:" << endl;
    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            cin >> a[i][k];
            if (cin.fail()) {
                cerr << "Invalid input!" << endl;
                return -1;
            }
        }
        cin >> b[i];
        if (cin.fail()) {
            cerr << "Invalid input!" << endl;
            return -1;
        }
    }

    double m[num][num]; //为参数矩阵的副本
    double _b_[num];  //为常数矩阵的副本
    for (int i = 0; i < num; i++){
        for (int k = 0; k < num; k++)
            m[i][k] = a[i][k];
        _b_[i] = b[i];
    }
    //检查矩阵的秩
    double tmp = 0;
    for (int k = 0; k < num - 1; k++) {
        if (m[k][k] == 0){
            cerr << "No unique solution exists!" << endl;
            return -2;
        }
        for (int i = k + 1; i < num; i++) {
            tmp = m[i][k] / m[k][k];
            for (int j = k; j < num; j++){
                m[i][j] = clear_residual(m[i][j] - tmp * m[k][j]);
            }
            _b_[i] = clear_residual(_b_[i] - _b_[k] * tmp);
        }
    }
    if (m[num - 1][num - 1] == 0){
        cerr << "No unique solution exists!" << endl;
        return -3;
    }
    cout << endl;
    cout << "[0] Jacobi Iteration  [1] Gaussian Elimination" << endl;
    cout << "Choose a method: ";
    int choose;
    cin >> choose;
    if (cin.fail() || (choose != 1 && choose != 0)) {
        cerr << "Invalid input!" << endl;
        return -1;
    }
    cout << endl;
    if (choose == 0){ //Jacobi Iteration
        int iteration = 10000;
        double x2[num];
        cout << "Input the initial approximation x(0):" << endl;
        //输入初始值
        for (int i = 0; i < num; i++)
            cin >> x2[i];
        cout << endl;
        for(int times = 0; times < iteration; times++){
            for (int i = 0; i < num; i++){
                tmp = 0.0;
                for (int j = 0; j < num; j++){
                    if (i == j) continue;
                    tmp += a[i][j] * x2[j];
                }
                x[i] = (b[i] - tmp) / a[i][i];
            }
            //check
            double max = 0;
            for (int i = 0; i < num; i++){
                tmp = abs(x[i] - x2[i]);
                if (max < tmp) max = tmp;
            }
            if (max < 0.001){
                cout << "Results is:" << endl;
                for (int i = 0; i < num; i++)
                    cout << x[i] << " ";
                cout << endl;
                return 0;
            }
            //renew
            for (int i = 0; i < num; i++)
                x2[i] = x[i];
        }
        cerr <<  "Maximum number of iterations exceeded!" << endl;
        return -4;
    }

    if (choose == 1){ //Gaussian Elimination
        for (int i = 1; i <= num; i++){
            for(int k = 1; k < i; k++){
                _b_[num - i] -= m[num - i][num - k] * x[num - k];
            }
            x[num - i] = _b_[num - i] / m[num - i][num - i];
        }
    }
    cout << "Results is:" << endl;
    for(int i = 0; i < num; i++)
        cout << x[i] << " ";
    cout << endl;
    return 0;
}
