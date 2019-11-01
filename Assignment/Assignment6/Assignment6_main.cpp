#include <iostream>
#include <limits>
#include <ctime>
#include "Assignment6_Methods.hpp"
using namespace std;
typedef float T; // Change the type here


int main()
{
    int r, round, i_th;
    T x;

    // Q1:
    cout << "--------------------------------- "<< endl;
    cout << " Q1: Test Partition" << endl;
    cout << "--------------------------------- "<< endl;

    cout << "How many times you want to test Partition?"<<endl;
    cin >> round;
    // input 0 to skip this part
    for(int i = 0; i < round; ++i){
        // clear the input buffer, no need to change.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Input values: " <<endl;
        vector<T> A;
        while (cin >> x) {
            A.push_back(x);
        }
        if(A.empty()){
            cerr << "error input!" << endl;
            return -1;
        }

        cout << "Partition array by random select pivot" << endl;

        r = rand()%(A.size());
        cout << "r = " << r << endl;
        cout << "A[r] = " << A[r] << endl;
        partition(A, r);
        for(auto iter : A)
            cout << iter << ' ';
        cout << endl;
    }

    // Q2:
    // clear the input buffer, no need to change.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "--------------------------------- "<< endl;
    cout << " Q2: Test Quicksort " << endl;
    cout << "--------------------------------- "<< endl;

    cout << "How many times you want to test Quicksort?"<<endl;
    cin >> round;
    // ----- input 0 to skip this part
    for(int i = 0; i< round; ++i){
        // clear the input buffer, no need to change.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Input values: " <<endl;
        vector<T> B;
        while (cin >> x) {
            B.push_back(x);
        }
        if(B.empty()){
            cerr << "error input!" << endl;
            return -1;
        }
        cout << "Sort Array" << endl;

        quickSort(B);
        for(auto iter = B.begin(); iter != B.end(); iter++)
            cout << *iter << ' ';
        cout << endl;
    }


    // Q3:
    // clear the input buffer, no need to change.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "--------------------------------- "<< endl;
    cout << " Q3: Test Rselect " << endl;
    cout << "--------------------------------- "<< endl;

    cout << "How many times you want to test Rselect?"<<endl;
    cin >> round;
    //input 0 to skip this part
    for(int i = 0; i < round; ++i){
        // clear the input buffer, no need to change.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Input values: " <<endl;
        vector<T> C;
        while (cin >> x) {
            C.push_back(x);
        }
        if(C.empty()){
            cerr << "error input!" << endl;
            return -1;
        }
        // to do:
        i_th = rand()%(C.size()) + 1; // n is the size of current array
        cout << "select i-th smallest element" << endl;

        T value = Rselect(C, i_th - 1);
        cout << "i_th = " << i_th << endl;
        cout << "value = " << value << endl;
    }

    // Q4:
    // clear the input buffer, no need to change.
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "--------------------------------- "<< endl;
    cout << " Q4: Test Dselect " << endl;
    cout << "--------------------------------- "<< endl;

    cout << "How many times you want to test Dselect?"<<endl;
    cin >> round;
    //input 0 to skip this part
    for(int i = 0; i< round; ++i){
        // clear the input buffer, no need to change.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Input values: " <<endl;
        vector<T> D;
        while (cin >> x) {
            D.push_back(x);
        }
        if(D.empty()){
            cerr << "error input!" << endl;
            return -1;
        }
        // to do :
        i_th = rand()%(D.size()) + 1; // n is the size of current array
        
        cout << "select i-th smallest element" << endl;
        T value = Dselect(D, i_th - 1);
        cout << "i_th = " << i_th << endl;
        cout << "value = " << value << endl;
    }
    return 0;
}
