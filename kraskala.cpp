#include "Libraries.h"
#include "empty_class.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    const int N = 10;
    int smezh[N][N] =
    {
        {0,10,0,0,20,0,0,15,0,0},
        {10,0,5,0,0,0,0,2,8,9},
        {0,5,0,16,0,0,0,0,4,0},
        {0,0,16,0,28,25,0,0,11,9},
        {20,0,0,28,0,15,0,0,0,0},
        {0,0,0,25,15,0,10,0,7,5},
        {0,0,0,0,0,10,0,11,0,3},
        {15,2,0,0,0,0,11,0,4,14},
        {0,8,4,11,0,7,0,4,0,0},
        {0,9,0,9,0,5,3,14,0,0}
    };

    int sum = 0;
    int min = INT_MAX;
    std::vector<int> minn;
    Graph a = Graph(N);                      //заполнила нулями в class.h удалила инициализацию(т е скорее всего надо создать 
                                             //класс либо что-то еще вместо a, чтобы передавать в функцию find_cycles
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (smezh[i][j] > 0) {
                min = smezh[i][j];
                minn.push_back(min);
            }
        }
    }
    sort(minn.begin(), minn.end());

    /*   int vershx[N];
       int vershy[N];*/
    for (int z = 0; z < minn.size(); z++) {
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (minn[z] == smezh[i][j]) {       //находим то самое ребро
                    a.A[i * N + j] = a.A[j * N + i] = smezh[i][j];  //добавляем его в массив
                    if (find_cycles_fact(a))         //если находим циклы, то зануляем
                        a.A[i * N + j] = a.A[j * N + i] = 0;
                    else {
                        /*vershx[z] = i;
                        vershy[z] = j;*/
                        sum += minn[z];
                        std::cout << i << " - " << j << " Weight: " << minn[z] << ". Interim amount: " << sum << std::endl;
                    }//печатает одно и тоже несколько раз. как запоминать две переменные на одной строке z(учитывая то, что эти вершины могут повторятся)?
                }
            }
        }
    }
    /*for (int z = 0; z < minn.size(); z++) {
        for (int i = 1; i < minn.size(); i++) {
            if (vershx[z] == vershx[i] && vershy[z] == vershy[i])
                break;
            else
                sum += minn[z];                                          //запись в векторы или массивы(хз какой длины), чтобы сравнивать
            std::cout << vershx[z] << " - " << vershy[z] << " Weight: " << minn[z] << ". Interim amount: " << sum << std::endl;
        }
    }*/
    return 0;
}



















//(vershx[i] == 0 || vershy[j] == 0) && (vershx[i]==0 || vershx[j]==0))
