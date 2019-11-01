#include "solve.h"
using namespace std;

int main(){
    double a, b, c;
    cin >> a >> b >> c;

    if (cin.fail() || a == 0){
        cerr << "Illegal inputs!" << endl;
        return -1;
    }
    try{
        if ((b*b - 4*a*c) < 0) throw 1;
    }
    catch(int){cerr << "b^2 − 4ac is less than zero!" << endl; return -1;}

    vector<double> v = solve(a, b, c);
    cout << "x1 = " << v[0] <<" x2 = " << v[1] << endl;
    return 0;
}