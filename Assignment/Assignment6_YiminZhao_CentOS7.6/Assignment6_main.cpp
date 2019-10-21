#include <iostream>
#include <limits>
#include <ctime>
using namespace std;
typedef float T; // Change the type here


int main()
{
    int x, r, round, i_th;
    
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
        while (cin >> x) {
            /*
             *to do : store the inputs
             */
        }

        cout << "Partition array by random select pivot" << endl;
        // to do :
        r = rand()%(n); // n is the size of current array
        
        /*
         * to do ：print r and A[r];
         */
        
        /*
         * to do : Partition array by A[r]
         *         print the rearranged array
         */
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
        while (cin >> x) {
            /*
             *to do : store the inputs
             */
        }
        cout << "Sort Array" << endl;
        /*
         *to do : quicksort
         *        print the sorted array
         */
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
        while (cin >> x) {
            /*
             *to do : store the inputs
             */
        }
        // to do:
        i_th = rand()%(n) + 1; // n is the size of current array
        cout << "select i-th smallest element" << endl;
        /*
         *to do : random selection
         *        print i-th and i-th value
         */
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
        while (cin >> x) {
            /*
             *to do : store the inputs
             */
        }
        // to do :
        i_th = rand()%(n) + 1; // n is the size of current array
        
        cout << "select i-th smallest element" << endl;
        /*
         *to do : deterministic selection
         *        print i-th and i-th value
         */
    }

    return 0;
}
