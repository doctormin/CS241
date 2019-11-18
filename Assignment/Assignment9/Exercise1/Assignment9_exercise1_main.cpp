    `//
    // Created by 18123 on 2019/11/16.
    //
    #include <iostream>
    #include <string>
    #include <vector>
    #include <random>
    #include <algorithm>

    using namespace std;
    ///基因池
    const string GENES =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ" \
            "abcdefghijklmnopqrstuvwxyz 1234567890 , .-;: !\"#%&/()=?@${[]}";
    ///目标字符串
    const string TARGET = "Hello, World! 19/11/09";
    ///最大迭代次数限制
    const int MAX_ITERATION_TIMES = 5000;

    class Population{//种群(只含有一代）
    private:
        int population_size; //每一代的个体数
        int string_length; //染色体的长度
        double pc; //交配概率
        double pm ; //突变概率
        vector<string> generation;  //每一代
        vector<int> Fitness;
        vector<int> sum_of_Fitness;
        //维护Fitness
        void fitness(){
            int tmp = 0;
            for (int i = 0; i < population_size; i++){
                Fitness[i] = 0;
                for(int k = 0; k < string_length; k++){
                    if (generation[i][k] == TARGET[k])//第k个字符相同
                        Fitness[i]++;
                }
                tmp += Fitness[i];
                sum_of_Fitness[i] = tmp;
            }
        }
    public:
        Population():generation(3000), Fitness(3000), sum_of_Fitness(3000){
            population_size = 3000; //每一代的个体数
            string_length = 22;  //染色体的长度
            pc = 0.8;  //交配概率
            pm = 0.01; //突变概率
            //构造随机的generation
            random_device random_device;
            mt19937 engine(random_device());
            uniform_int_distribution<int> dis(0, GENES.size()-1);

            for(int i = 0; i < population_size; i++){
                for(int j = 0; j < string_length; j++){
                    int index = dis(engine);
                    generation[i].push_back(GENES[index]) ;
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
            uniform_int_distribution<int> dis2(0, GENES.size()-1);
            for(int i = 0; i < population_size; i++){
                for(int j = 0; j < string_length; j++){
                    if(dis1(engine) < pm) {//第i个染色体的第j位发生突变
                        int choose = dis2(engine); //随机突变为基因池的第choose位
                        generation[i][j] = GENES[choose];
                    }
                }
            }
            fitness(); //维护Fitness
        }

        void crossover(){//交叉互换
            random_device random_device;
            mt19937 engine(random_device());
            uniform_real_distribution<double> dis1(0.0, 1.0);
            uniform_int_distribution<int> dis2(0, generation[0].size()- 1);
            shuffle(generation.begin(), generation.end(), engine);


            for(int i = 0; i < generation.size() / 2; i++){
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
            vector<string> tmp(generation);
            random_device random_device;
            mt19937 engine(random_device());
            uniform_int_distribution<int> dis(0, sum_of_Fitness[population_size-1]-1);
            for(int i = 0; i < population_size; i++){
                int index = selection_index(dis(engine));
                generation[i] = tmp[index];
            }
            fitness();
        }

        string GetOptimal(){
            //找到generation中Fitness最大的string并return之
            int max_index = distance(Fitness.begin(), max_element(Fitness.begin(), Fitness.end()));
            return generation[max_index];
        }

        bool check_ok(){//检查是否得到满意的结果
            return (GetMaxFitness() == 22);
        }
    };



    int main(){
        //****exercise1****
        cout << "*****test of exercise1 :******" << endl;
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

