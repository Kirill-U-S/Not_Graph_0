#include <iostream>
#include <vector>
#include <cmath>
#include "Class_Graph.h"
#include "Algorithm.h"

/*мин-макс*/
void deg(Graph g)
{
    const int N = sqrt(g.A.size());
    int* deg = new int[N];
    int max = 0, min = N, Sum = 0;

    /*копирование изначального массива ј*/
    int** smezh = new int* [N];
    for (int i = 0; i < N; i++)
        smezh[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            smezh[i][j] = g.A[i * N + j];
    /*----------------------------------*/

    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < N; j++)
            sum += smezh[i][j];
        deg[i] = sum;
        if (deg[i] > max)
            max = deg[i];
        if (deg[i] < min)
            min = deg[i];
        Sum += deg[i];
    }
    std::cout << "max deg: " << max << "\nmin deg: " << min << "\nsred deg: " << (double)Sum / N << std::endl;
}