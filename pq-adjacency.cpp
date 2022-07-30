#include "Libraries.h"

void pq_pp(Graph g)
{
    const int N = sqrt(g.A.size());
    const int rebrs = g.D.size() / N;
    /*копирование изначального массива А*/
    int** smezh = new int* [N];
    for (int i = 0; i < N; i++)
        smezh[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            smezh[i][j] = g.A[i * N + j];
    /*----------------------------------*/

    /*копирование изначального массива pq*/
    int** pq = new int* [N];
    for (int i = 0; i < N; i++)
        pq[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < rebrs; j++)
            pq[i][j] = g.D[i * N + j];
    /*-----------------------------------*/

    //работающий пример
    /*int pq[Ne][rebrs] =
    {
        {1,0,1,0,0,1,0,0},
        {1,1,0,1,1,0,0,0},
        {0,1,1,0,0,0,0,0},
        {0,0,0,1,0,0,1,0}, 
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,0,1,1,1},
    };*/

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < rebrs; j++)
        {
            if (pq[i][j] == 1)
            {
                int x = i;
                int y = j;
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

void pp_pq(Graph g) 
{
    int N = sqrt(g.A.size());

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (g.A[i * N + j] > 0)
                for (int k = 0; k < N; k++)
                    if (i == k || j == k)
                        g.D.push_back(1);
                    else
                        g.D.push_back(0);
}