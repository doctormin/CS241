//
// Created by 18123 on 2019/9/21.
//
#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
    fraction up[4];
    fraction down[4];
    fraction quo[4];

    int tmp;

    for(int i = 3; i >= 0; i--)
    {
        cin >> tmp;
        if(cin.fail()){
            cerr << "error" << endl;
            return -1;
        }
        up[i] = tmp; //赋值后分子为tmp,分母为1
        quo[i] = 0;
    }
    if (up[3] == 0){
        cerr << "error" <<endl;
        return -2;
    }
    for(int i = 3; i >= 0; i--){
        cin >> tmp;
        if(cin.fail()){
            cerr << "error" << endl;
            return -1;
        }
        down[i] = tmp;
    }

    int m = 3;
    int n;


    for(int i = 3; i >= 0; i--)
        if(down[i] != 0){
            n = i;
            break;
        }

    int k = 0;
    for (int i = m - n; i >= 0; i--){

        //cout << "++++++++++++++++++++++++++++++++"<< endl;
        //cout << "quo[" << i << "] = up[" << i + n << "] / down[" << n << "]" <<endl;
        //cout << "quo[" << i <<"] = "<< quo[i] << " up[" << i+n<<"] = " << up[i+n] << " down[" << n<<"]= " << down[n] <<endl;
        quo[i] = up[i + n] / down[n];
        //cout <<"result: " << "quo[" << i << "] = " <<quo[i]<<endl;
        //cout <<"----------------------------------"<<endl;

        for(int j = n; j >= 0; j--)
        {

            //cout << "up[" << i+j << "] = up[" << i+j <<"] - down["<<j<<"]*quo[" << i <<"]"<<endl;
            //cout <<"up[" << i+j << "] = "<<up[i+j] <<" down["<<j<<"] = "<<down[j] << " quo[" <<i<<"] = " << quo[i]<<endl;
            //cout << "down["<<i<<"]*quo["<<i<<"]=" <<down[j]*quo[i]<<endl;
            up[i+j] = up[i+j] - down[j]*quo[i];
            //cout << "reslut:" << up[i+j] << endl;

        }
    }

    ///输出
    //cout << "==========" << endl;
    bool flag = true;
    for (int i = 3; i >= 0; i--)
    {
        if(quo[i] == 0 && flag && i!=0) continue;
        else
        {
            cout << quo[i] << ' ';
            flag = false;
        }
    }
    flag = true;
    cout << endl;
    for (int i = 3; i >= 0; i--)
    {
        if(up[i] == 0 && flag && i!=0) continue;
        else
        {
            cout << up[i] << ' ';
            flag = false;
        }
    }
    cout << endl;
    return 0;
}