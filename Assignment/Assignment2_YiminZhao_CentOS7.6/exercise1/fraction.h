//
// Created by 18123 on 2019/9/21.
//
//
#ifndef PAQ_HOMEWORK_FRACTION_H
#define PAQ_HOMEWORK_FRACTION_H
#include <iostream>

using namespace std;


class fraction
{
    friend fraction operator+(const fraction &r1, const fraction &r2);
    friend fraction operator-(const fraction &r1, const fraction &r2);
    friend fraction operator*(const fraction &r1, const fraction &r2);
    friend fraction operator/(const fraction &r1, const fraction &r2);
    friend ostream& operator<<(ostream &os, const fraction &obj);
public:
    int num;
    int den;
    void reduction();//分数化简
public:
    fraction(int n = 0, int d = 1) {num = n; den = d; reduction();}
    fraction& operator= (int n);
    fraction& operator= (fraction r1);
    bool operator== (int n);
    bool operator!= (int n);
};

#endif //PAQ_HOMEWORK_FRACTION_H
