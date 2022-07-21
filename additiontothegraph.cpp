#include <iostream>
#include "Class_Graph.h"
#include "Algorithm.h"
//TODO: написать  везде комментарии
//TODO: связный ли граф (есть ли маршрут из одной вершины в другую)
//TODO: полный ли
//TODO: мультиграф ли он или псевдо
//TODO: циклы с 4, 5 и тд вершинами
//TODO: краскала
//TODO: эйлеров цикл и цепь
//TODO: тудудудудудуду тудудуууу
//TODO: разность графов

void adtograph(Graph g) {
    const int N = sqrt(g.A.size());
    int** dop = new int* [N];

    /*копирование изначального массива А*/
    int** smezh = new int* [N];
    for (int i = 0; i < N; i++)
        smezh[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            smezh[i][j] = g.A[i * N + j];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (smezh[i][j] == 0)
                dop[i][j] = 1;
            else
                dop[i][j] = 0;
            dop[i][i] = 0;
            std::cout << dop[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
