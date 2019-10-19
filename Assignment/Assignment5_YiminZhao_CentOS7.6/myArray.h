//
// Created by 18123 on 2019/10/16.
//
#ifndef CS241_MYARRAY_H
#define CS241_MYARRAY_H

#include<iostream>


///对myArray的声明
template<typename Elem>
class myArray{
private:
    Elem * array;
    unsigned _size_;//目前使用容量
    unsigned _capacity_;//最大容量
private:
    void DoubleTheSize();//在最大容量不够时把最大容量扩大一倍

public:
    class iterator;//迭代器 定义见后
    explicit myArray(int c = 10);
    ~myArray();
    void push_back(const Elem &v);
    void pop_back();
    unsigned size() const {return _size_;}
    unsigned  capacity() const {return _capacity_;}
    Elem& operator[](const int n);
    auto& operator=(const myArray<Elem> &r);
    iterator begin();
    iterator end();
};

///对iterator（内嵌类）的声明和定义
template <typename Elem>
class myArray<Elem>::iterator{
private:
    int pointer;
    myArray<Elem> * p;  //用来识别对应的容器实例
public:
    //构造函数
    iterator(){
        p = NULL;
        pointer = 0;
    }
    iterator(myArray<Elem> *p, int pointer) {
        this->p = p;
        this->pointer = pointer;
    }
    iterator& operator=(iterator const &r){
        p = r.p;
        pointer = r.pointer;
    }
    //前缀++
    iterator& operator++(){
        pointer++;
        return *this;
    }
    //后缀++
    iterator operator++(int x){
        auto tmp = *this;
        this->pointer++;
        return tmp;
    }

    bool operator==(const iterator &r){
        return (r.p == this->p && r.pointer == this->pointer);
    }

    bool operator!=(const iterator &r){
        return (r.p != this->p || r.pointer != this->pointer);
    }
    //解引用重载
    Elem& operator*() const{
        return p->array[pointer];
    }


};


///对myArray成员函数的定义：
template<typename Elem>
void myArray<Elem>::DoubleTheSize() { //将容量扩为两倍
    auto tmp = array;
    _capacity_ *= 2;
    array = new Elem[_capacity_];
    for (int i = 0; i < _capacity_ / 2; i ++)
        array[i] = tmp[i];
    delete tmp;
}

template<typename Elem>
myArray<Elem>::myArray(int c) {
    _size_ = 0;
    _capacity_ = c;
    array = new Elem[_capacity_];
}

template<typename Elem>
myArray<Elem>::~myArray() {
    delete [] array;
}

template<typename Elem>
void myArray<Elem>::push_back(const Elem &v) {
    if(_size_ == _capacity_) DoubleTheSize();
    array[_size_++] = v;
}

template<typename Elem>
void myArray<Elem>::pop_back() {
    if(_size_ == 0) {
        std::cout << "elements clear! --- pop_back stopped" << std::endl;
    }
    else _size_--;
}

template<typename Elem>
Elem& myArray<Elem>::operator[](const int n) {
    return array[n];
}

template<typename Elem>
auto& myArray<Elem>::operator=(const myArray<Elem> &r) {
    delete []array;
    _size_= r._size_;
    _capacity_ = r._capacity_;
    array = new Elem[_size_];
    for (int i = 0; i < _size_; i++)
        array[i] = r.array[i];
    return *this;
}

template<typename Elem>
typename myArray<Elem>::iterator myArray<Elem>::begin() {
    return myArray<Elem>::iterator(this, 0);
}

template<typename Elem>
typename myArray<Elem>::iterator myArray<Elem>::end() {
    return iterator(this, _size_);
}

#endif //CS241_MYARRAY_H

