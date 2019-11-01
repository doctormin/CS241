#include <iostream>
#include <iomanip>
using namespace std ;

double ctok(double c);

int main()
{
    double c = 0;
    double k;
    cout << "Celsius : ";
    cin >> c;

    try{
        k = ctok(c);
    }
    catch(double) {cerr << "Error reporting!" << endl; return -1;}

    cout << k;

    return 0;
}


double ctok(double c)
{
    if (c < -273.15) throw c;
    double k = c + 273.15;
    return k;
}
