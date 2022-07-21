#include <iostream>
#include <vector>
#include <algorithm>
#include "Class_Graph.h"
#include "Algorithm.h"

void prima(Graph g) {
    const int N = sqrt(g.A.size());
    int* versh = new int[N];
    int** arr = new int* [N];
    /*копирование изначального массива А*/
    int** smezh = new int* [N];
    for (int i = 0; i < N; i++)
        smezh[i] = new int[N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            smezh[i][j] = g.A[i * N + j];
            arr[i][j] = 0;
        }
        versh[i] = 0;
    }
    versh[0] = 1;
    int y = 0, x = 0, sum = 0, k = 0;

    while (k++ < N - 1)
    {
        int minn = INT_MAX;
        for (int i = 0; i < N; i++)
            if (!versh[i])
                arr[x][i] = smezh[x][i]; //присваивание строки

        arr[y][x] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((arr[i][j] < minn) && arr[i][j] && !versh[j]) {
                    minn = arr[i][j];
                    y = i; // last
                    x = j; // найденная вершина
                }
            }
        }
        versh[x] = arr[y][x];
        sum += versh[x];
        std::cout << "Step " << k << ": edge " << y << " - " << x << ", weight " << versh[x] << ". sum: " << sum << std::endl;
    }
}
