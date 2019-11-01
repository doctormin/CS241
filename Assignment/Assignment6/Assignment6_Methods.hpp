//
// Created by 18123 on 2019/10/26.
//

#ifndef CS241_ASSIGNMENT6_METHODS_HPP
#define CS241_ASSIGNMENT6_METHODS_HPP

#include <vector>


using std::vector;
using std::swap;
using std::min;

// Partition
template<typename T>
int partition(vector<T> &A, int pivot_index, int low, int high){
    swap(A[pivot_index], A[low]);
    T k = A[low];
    do{
        while(low < high && A[high] >= k) --high;
        if(low < high) A[low++] = A[high];

        while(low < high && A[low] < k) ++low;
        if(low < high) A[high--] = A[low];
    }while(low != high);
    A[low] = k;
    return low;
}

///划分函数的包裹函数
template<typename T>
int partition(vector<T> &A, int pivot_index = 0){
    return partition(A, pivot_index, 0, A.size() - 1);
}

///quickSort
template<typename T>
void quickSort(vector<T> &A, int low, int high){
    int mid;
    if(low >= high) return;
    mid = partition(A, low, low, high);
    quickSort(A, low, mid - 1);
    quickSort(A, mid + 1, high);
}

///quickSort包裹函数
template<typename T>
void quickSort(vector<T> &A) {
    quickSort(A, 0, A.size() - 1);
}

///Random_select
template<typename T>
T Rselect(vector<T> &A, int i, int low, int high){
    if(high == low) return A[low];  //只有一个元素

    int tmp = rand()%(high - low + 1);
    int r = tmp + low;
    T pivot = A[r];

    int pivot_ranking = partition(A, r, low, high);

    if(i == pivot_ranking)
        return pivot;
    else if(pivot_ranking > i) return Rselect(A, i, low, pivot_ranking - 1);
    else return Rselect(A, i , pivot_ranking + 1, high);
}

///Random_select包裹函数
template<typename T>
T Rselect(vector<T> A, int i){
    return Rselect(A, i, 0, A.size() - 1);
}



//声明
template<typename T>
T Dselect(vector<T> A, int i);

///my_sort 用于被 Rselect 调用
template<typename T>
void my_sort(vector<T> &A, int low, int high){
    for (int j = low; j < high; ++j) {
        int index = j;
        for (int k = j; k <= high; ++k) {
            if (A[k] < A[index]) index = k;
        }
        swap(A[j], A[index]);
    }
}
///Dselect
template<typename T>
T Dselect(vector<T> &A, int i, int low, int high){
    if (high == low) return A[low];

    ///只能分出一段：
    if (high - low <= 4) {
        my_sort(A, low, high);
        return A[(low + high) / 2];
    }
    ///可以分出几段
    for (int m = low; m <= high; m += 5) {
        my_sort(A, m, min(m + 4, high));
    }

    vector<T> TMP;
    for (int m = low + 2; m <= high; m += 5) {
        TMP.push_back(A[m]);
    }
    T pivot = Dselect(TMP, TMP.size() / 2);

    int r = -1;
    for (int m = low; m <= high; ++m) {
        if (pivot == A[m]) {
            r = m;
            break;
        }
    }
    if(r == -1){
        std::cerr << "finding pivot failed" << std::endl;
        std::terminate();
    }

    int index = partition(A, r, low, high);
    if (index == i)
        return pivot;
    else if (index > i)
        return Rselect(A, i, low, index - 1);
    else
        return Rselect(A, i, index + 1, high);
}

///Dselect包裹函数
template<typename T>
T Dselect(vector<T> A, int i){
    return Dselect(A, i, 0, A.size() - 1);
}

#endif //CS241_ASSIGNMENT6_METHODS_HPP
