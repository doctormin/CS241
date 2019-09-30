#include <iostream>
#include <iomanip>
using namespace std ;

//error #1 lacking of declaration of function
double ctok(double c);

int main()
{
    double c = 0 ;
    cout << "Celsius: " ;
    cin >> c ; // error #2 variable name mistaken
    double k = ctok (c) ; // error #3 wrong input type
    cout <<"Kelvin : "<< k << '\n'; // error #4 mistaking '\' from '/'
    // system("pause") ;
    return 0 ;

};

// error #5 wrong input type
double ctok(double c)
{
    double k = c + 273.15;
    return k;
}