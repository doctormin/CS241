//
// Created by 18123 on 2019/10/19.
//

#ifndef CS241_MYDATA_H
#define CS241_MYDATA_H
#include<iostream>

template <typename T>
struct myData{
    T val;
    myData<T> * addr;

    explicit myData(T value):val(value), addr(this){}
    myData():addr(this){}
    myData& operator=(const myData &r){
        val = r.val;
        addr = r.addr;
    }
};

template <typename T>
struct Cmp_by_val{
    bool operator()(myData<T> a, myData<T> b){
        return a.val < b.val;
    }
};

template <typename T>
struct Cmp_by_addr{
    bool operator()(myData<T> a, myData<T> b){
        return a.addr < b.addr;
    }
};
#endif //CS241_MYDATA_H
