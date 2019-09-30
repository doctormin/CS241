#include <iostream>
#include <iomanip>
using namespace std ;

double ctok(double c);

int main()
{
    double c = 0;
    cout << "Celsius : ";

    try{
        cin >> c;
        if (c < -273.15) throw 1;
    }
    catch(int) {cout << "Error reporting!" << endl; return -1;};

    cout << ctok(c);
    return 0;
}


double ctok(double c)
{
    double k = c + 273.15;
    return k;
}
