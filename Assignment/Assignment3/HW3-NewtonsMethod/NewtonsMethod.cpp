#include <iostream>
#include <cmath>
using namespace std;

int main(){
    const double x0 = 0.343036;
    int k = 1;
    cout << "x0: " << x0 << endl;
    double old_x = 100;
    double new_x = x0;
    while(fabs(new_x - old_x) >= 0.00001){
        old_x = new_x;
        new_x = new_x - (10 * new_x *new_x * new_x - 8.3 * new_x * new_x + 2.295 * new_x - 0.21141) / (30 * new_x * new_x - 2 * 8.3 * new_x + 2.295);
        cout << 'x' << k++ << ": " << new_x << endl;
    }
    return 0;
}