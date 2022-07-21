#include <iostream>
#include <new>
#include "Class_Graph.h"
#include "Algorithm.h"

void pq_adjacency(Graph g)
{
    const int N = sqrt(g.A.size());
    /*����������� ������������ ������� �*/
    int** smezh = new int* [N];
    for (int i = 0; i < N; i++)
        smezh[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            smezh[i][j] = g.A[i * N + j];
    /*----------------------------------*/

    const int N = 6, rebrs = 8;

    int pq[N][rebrs] =
    {
        {1,0,1,0,0,1,0,0},
        {1,1,0,1,1,0,0,0},
        {0,1,1,0,0,0,0,0},
        {0,0,0,1,0,0,1,0}, 
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,0,1,1,1},
    };

    int smezh[N][N]{}, x, y ;
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
    return 0;
}
//�� ������ ������� ��������� ��������� ������� �������������
//�� �����, ��� ������������� �����, ����� �������, ���� ������ ������ � �����(�� �� ���� �� ������ ��� ����)
#include <iostream>
using namespace std;
int main()
{
    const int N = 6;
    int smezh[N][N] =
    {
        {0,1,1,0,0,1};
        {1,0,1,1,1,0};
        {1,1,0,0,0,0};
        {0,1,0,0,0,1};
        {0,1,0,0,0,1};
        {1,0,0,1,1,0};
    };
    int sum = 0, rebrs;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        sum += smezh[i][j];
    rebrs = sum / 2;
    int arr[N][rebrs];

    return 0;
}