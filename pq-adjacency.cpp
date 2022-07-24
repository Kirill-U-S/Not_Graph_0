#include <iostream>
#include "Class_Graph.h"
#include "Algorithm.h"

void pq_adjacency(Graph g)
{
    const int N = sqrt(g.A.size());
    /*копирование изначального массива А*/
    int** smezh = new int* [N];
    for (int i = 0; i < N; i++)
        smezh[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            smezh[i][j] = g.A[i * N + j];
    /*----------------------------------*/

    const int Ne = 6, rebrs = 8;

    //TODO: чтобы pq прилетал из графа g с вызовом функции (инициализировать)
    int pq[Ne][rebrs] =
    {
        {1,0,1,0,0,1,0,0},
        {1,1,0,1,1,0,0,0},
        {0,1,1,0,0,0,0,0},
        {0,0,0,1,0,0,1,0}, 
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,0,1,1,1},
    };

    int x, y;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < rebrs; j++)
        {
            if (pq[i][j] == 1)
            {
                x = i;
                y = j;
                for (int z = x + 1; z < N; z++)
                    if (pq[z][y] == 1)
                        smezh[x][z] = smezh[z][x] = 1;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            std::cout << smezh[i][j] << " ";
        std::cout << std::endl;
    }
}
//TODO: перевод pp -> pq
//перевод pp -> pq
//int main()
//{
//    const int N = 6;
   /* int smezh[N][N] =
    {
        {0,1,1,0,0,1};
        {1,0,1,1,1,0};
        {1,1,0,0,0,0};
        {0,1,0,0,0,1};
        {0,1,0,0,0,1};
        {1,0,0,1,1,0};
    };*/
//    int sum = 0, rebrs;
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++)
//            sum += smezh[i][j];
//    rebrs = sum / 2;
//    int arr[N][rebrs];
//}