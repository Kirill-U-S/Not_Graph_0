#include <iostream>
#include <vector>
#include <algorithm>
#include "empty_class.h"
#include "Algorithm.h"

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
    Graph a = Graph(N);

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (smezh[i][j] > 0) {
                min = smezh[i][j];
                minn.push_back(min);
            }
        }
    }
    sort(minn.begin(), minn.end());

    for (int z = 0; z < minn.size(); z++) {
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (minn[z] == smezh[i][j]) {       //находим то самое ребро
                    a.A[i * N + j] = smezh[i][j];  //добавляем его в массив/////////////////////////////////////////////////////////
                    a.A[j * N + i] = smezh[i][j];  //на всякий пожарный симметричный тоже
                    if (find_cycles_fact(a)) {         //если находим циклы, то зануляем
                        a.A[i * N + j] = 0;
                        a.A[j * N + i] = 0;
                    }
                    else {
                        sum += minn[z];
                        std::cout << i << " - " << j << " Weight: " << minn[z] << ". Interim amount: " << sum << std::endl;
                    }
                }
            }
        }
    }

    return 0;
}


















//(vershx[i] == 0 || vershy[j] == 0) && (vershx[i]==0 || vershx[j]==0))
