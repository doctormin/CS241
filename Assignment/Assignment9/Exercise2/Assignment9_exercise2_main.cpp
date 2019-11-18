//
// Created by 18123 on 2019/11/17.
//
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

const int MAX_ITERATION_TIMES = 5000;

class Population{//种群(只含有一代）
private:
    vector<vector<int> > generation;
    vector<double> Fitness;
    vector<double> sum_of_Fitness;
    int population_size;
    double pc;
    double pm;
    //二进制编码->实数
    double decode(vector<int> individual) {
        double tmp = 0;
        for (auto i:individual) {
            tmp = (tmp + i) * 2;
        }
        double results = 15 * (tmp/2) / (65536 - 1) - 1.0;
        return results;
    }

    //维护Fitness
    void fitness(){
        int tmp = 0;
        for (int i = 0; i < population_size; i++){
            double x = decode(generation[i]);
            double length = fabs(10000 * x - 110857);
            Fitness[i] = (120000 - length);
            tmp += Fitness[i];
            sum_of_Fitness[i] = tmp;
        }
    }
public:

    Population():generation(200), Fitness(200), sum_of_Fitness(200){
        population_size = 200; //每一代的个体数
        pc = 0.4;  //交配概率
        pm = 0.01; //突变概率
        //构造随机的generation
        random_device random_device;
        mt19937 engine(random_device());
        uniform_real_distribution<double> dis(0, 1);
        //随机化二进制码
        for (int i = 0; i < population_size; ++i) {
            for (int k = 0; k < 16; ++k) {
                generation[i].push_back(dis(engine) < 0.5);
            }
        }
        fitness();
    }

    int GetMaxFitness(){

        auto max_fitness = max_element(Fitness.begin(), Fitness.end());
        int index = max_fitness-Fitness.begin();
        return Fitness[index];  //Fitness中的最大值
    }

    void mutation(){
        random_device random_device;
        mt19937 engine(random_device());
        uniform_real_distribution<double> dis1(0.0, 1.0);
        uniform_int_distribution<int> dis2(0, 1);

        for(int i = 0; i < population_size; i++){
            for(int k = 0; k < 16; k++){
                if(dis1(engine) < pm){//第i个个体的第k位发生突变
                    generation[i][k] = dis2(engine);
                }
            }
        }

        fitness(); //维护Fitness
    }

    void crossover(){//交叉互换
        random_device random_device;
        mt19937 engine(random_device());
        uniform_real_distribution<double> dis1(0.0, 1.0);
        uniform_int_distribution<int> dis2(0, 15);

        for(int i = 0; i < population_size / 2; i++){
            if(dis1(engine) > pc) continue;
            //将generation[i]与generation[population_size - 1 - i]交配
            int start_index = dis2(engine);
            int end_index = dis2(engine);
            if(start_index == end_index) continue;

            if(start_index > end_index) swap(start_index, end_index);
            for(int k = start_index; k <= end_index; k++){
                swap(generation[i][k], generation[2*i + 1][k]);
            }
        }
        fitness();
    }

    int selection_index(int dis){
        for(int i = 0; i < sum_of_Fitness.size(); ++i){
            if( dis < sum_of_Fitness[i])
                return i;
        }
    }

    void selection(){
        vector<vector<int> > tmp(generation);  //generation的副本
        random_device random_device;
        mt19937 engine(random_device());
        uniform_int_distribution<int> dis(0, sum_of_Fitness[population_size-1]-1);
        for(int i = 0; i < population_size; i++){
            int index = selection_index(dis(engine));
            generation[i] = tmp[index];
        }
        fitness();
    }

    double GetOptimal(){
        //找到generation中Fitness最大的x并return之
        int max_index = distance(Fitness.begin(), max_element(Fitness.begin(), Fitness.end()));
        return decode(generation[max_index]); //解码为实数
    }

    bool check_ok(){//检查是否得到满意的结果
        double x = GetOptimal();
        return (x > 11.08 && x < 11.10);
    }
};



int main(){
    //****exercise2****
    cout << "*****test of exercise2 :******" << endl;
    Population p;
    p.selection();
    for(int i = 0; i < MAX_ITERATION_TIMES; i++){
        cout << "The optimal of generation" << i+1 <<": ";
        cout << p.GetOptimal();
        cout << endl;
        if(p.check_ok()) break; //得到了最终结果，迭代终止
        p.crossover();
        p.mutation();
        p.selection();
    }
    return 0;
};


