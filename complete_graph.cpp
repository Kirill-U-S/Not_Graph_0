//полный или сильносвязный граф
#include <iostream>
#include <cmath>
#include "Class_Graph.h"
#include "Algorithm.h"

void complete(Graph g) {
    const int N = sqrt(g.A.size());
    /*копирование изначального массива А*/
    int** smezh = new int* [N];
    for (int i = 0; i < N; i++)
        smezh[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            smezh[i][j] = g.A[i * N + j];
    bool ed = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N, !smezh[j][j]; j++)
        {
            if (i != j)                 //всё кроме главной диагонали должно быть в единицах,
            {                           //поэтому смотрим на все элементы кроме диагональных
                if (smezh[i][j] != 1)
                    ed = false;
            }
        }
    }
    if (ed)
        std::cout << "complete";   //если для орграфа, то strongly connected
    else
        std::cout << "incomplete";
}
