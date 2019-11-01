#include "fraction.h"
#include <iostream>
using namespace std;

fraction operator+ (const fraction &r1, const fraction &r2)
{
    fraction tmp;
    tmp.num = r1.num*r2.den + r1.den*r2.num;
    tmp.den = r1.den*r2.den;
    tmp.reduction();
    if (tmp.num == 0)
        tmp.den = 1;
    return tmp;
}

fraction operator- (const fraction &r1, const fraction &r2)
{
    fraction tmp;
    tmp.num = r1.num*r2.den - r2.num*r1.den;
    tmp.den = r1.den * r2.den;
    if (tmp.num == 0)
        tmp.den = 1;
    tmp.reduction();
    return tmp;
}

fraction operator* (const fraction &r1, const fraction &r2)
{
    fraction tmp;
    tmp.num = r1.num*r2.num;
    tmp.den = r1.den*r2.den;
    if (tmp.num == 0)
        tmp.den = 1;
    tmp.reduction();
    return tmp;
}

fraction operator/ (const fraction &r1, const fraction &r2)
{
    fraction tmp;
    tmp.num = r1.num * r2.den;
    tmp.den = r1.den * r2.num;
    if (tmp.num == 0)
        tmp.den = 1;
    tmp.reduction();
    return tmp;
}

ostream& operator<<(ostream &os, const fraction &obj)
{
    if(obj.den == 1 || obj.num == 0) //分母为一时只输出分子
    {
        os << obj.num;
        return os;
    }
    os << obj.num << '/' << obj.den;
    return os;
}

void fraction::reduction()
{
    int tmp = (num > den) ? den : num;

    for (; tmp > 1; --tmp)
        if (num % tmp == 0 && den % tmp == 0) {
            num /= tmp;
            den /= tmp;
            break;
        }
}

fraction& fraction::operator=(int n)
{
   num = n;
   den = 1;
   return *this;
}

fraction& fraction::operator=(fraction r1){
    num = r1.num;
    den = r1.den;
    this->reduction();
    return *this;
}

bool fraction::operator==(int n)
{
    return (num == n && den == 1);
}

bool fraction::operator!=(int n)
{
    if (den != 1) return 1;
    else return(num != n);
}