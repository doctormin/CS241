#include <iostream>
#include <string>
#include <vector>
using namespace std;


class LCS {
public:
    int LongestCommonSubsequence(const string& text1, const string& text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        vector<vector<int>> c(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = 0; i <= l1; i++)
            c[i][0] = 0;
        for (int i = 0; i <= l2; i++)
            c[0][i] = 0;
        for (int i = 1; i <= l1; i++)
            for (int j = 1; j <= l2; j++){
                if (text1[i] == text2[j]){
                    c[i][j] = c[i-1][j-1]+1;
                }
                else{
                    c[i][j] = c[i-1][j] > c[i][j-1] ? c[i-1][j] : c[i][j-1];
                }
            }
        /*
        for(auto i : c){
           for(auto j : i)
               cout << j;
           cout << endl;
        }*/
        int  longest_length = c[l1][l2];
        return longest_length;
    }
};


class WIS {
public:
    int WeightedIntervalScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        int size = profit.size();
        //re-order by the endTime
        for (int i = 0; i < size; i++)
            for (int j = i; j < size; j++){
                if(endTime[j] < endTime[i]){
                    swap(endTime[i], endTime[j]);
                    swap(startTime[i], startTime[j]);
                    swap(profit[i], profit[j]);
                }
            }
        vector<int> results(size);
        results.assign(profit.begin(),profit.end());

        for(int i = 0; i < size; i++){
            for(int j = 0; j < i; j++){
                if(endTime[j] <= startTime[i]){
                    //cout << "profit[" << i << "] = max{" << results[i] << ", " << profit[i] + results[j] << "}" << endl;
                    results[i] = max(results[i], profit[i] + results[j]);
                }
            }
            /*
            cout << "round" << i << ": ";
            for (auto k : results){
                cout << k << "  " ;
            }
            cout << endl;*/
        }

        //find the max
        int max_profit = 0;
        for (auto i : results){
            if (i > max_profit){
                max_profit = i;
            }
        }
        return max_profit;
    }
};


class KP {
public:
    int KnapsackProblem(vector<int> &weight, vector<int> &value, int W) {
        int n = weight.size();
        vector<vector<int>> c(n + 1, vector<int>(W + 1, 0));//c[i][j]表示用容量为j的背包处理前i个物体的最优value
        for (int i = 0; i <= n; i ++)
            c[i][0] = 0;
        for (int i = 0; i <= W; i++)
            c[0][i] = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= W; j++){
                if(j < weight[i]) {//放不下第i个物品，则与处理前i-1个物品的值一样
                    c[i][j] = c[i-1][j];
                }
                else{//放得下第i个物品,在放和不放中取舍
                    c[i][j] = max(c[i-1][j], c[i-1][j-weight[i]] + value[i]);
                }
            }
        }
        int maximum_value;
        maximum_value = c[n][W];
        return maximum_value;
    }
};


// For testing
int main(int argc, const char * argv[]) {
    
    //*********** Test Longest Common Subsequence ***********//
    string text1 = "springtime";
    string text2 = "printing";
    LCS lcs = LCS();
    cout << "Test Longest Common Subsequence..." << endl;
    cout << lcs.LongestCommonSubsequence(text1, text2) << endl;
    cout << "The expected output: 6" << endl;
    cout << endl;

    //********** Test Weighted Interval Scheduling **********//
    vector<int> startTime = {1,2,3,4,6};
    vector<int> endTime = {3,5,9,6,9};
    vector<int> profit = {20,20,100,70,60};
    WIS wis = WIS();
    cout << "Test Weighted Interval Scheduling..." << endl;
    cout << wis.WeightedIntervalScheduling(startTime, endTime, profit) << endl;
    cout << "The expected output: 150" << endl;
    cout << endl;

    //*************** Test Knapsack Problem ****************/
    vector<int> weight = {1, 2, 5, 6, 7};
    vector<int> value = {1, 6, 18, 22, 28};
    int W = 11;
    KP kp = KP();
    cout << "Test Knapsack Problem..." << endl;
    cout << kp.KnapsackProblem(weight, value, W) << endl;
    cout << "The expected output: 40" << endl;
    cout << endl;

    return 0;
}
