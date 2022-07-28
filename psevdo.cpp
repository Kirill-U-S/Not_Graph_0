#include <iostream>
#include <cmath>
#include "Class_Graph.h"
#include "Algorithm.h"

void psevdo(Graph g) {
    const int N = sqrt(g.A.size());
    /*копирование изначального массива ј*/
    int** smezh = new int* [N];
    for (int i = 0; i < N; i++)
        smezh[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            smezh[i][j] = g.A[i * N + j];
    bool multi = false;
    bool gd = false;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i != j && smezh[i][j] > 1)
                multi = true;
            else if(i==j && smezh[i][j] > 0)
                gd = true;
            else continue;
        }
    }
    if (multi && gd)
        std::cout << "psevdograph";
    else
        std::cout << "not psevdograph";
}