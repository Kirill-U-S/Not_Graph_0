#include <iostream>
#include <new>
int main()
{
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
    int smezh[N][N]{}, x, y;
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
//по данным таблицы смежности построить таблицу инцидентности
//не знаем, как пронумерованы ребра, нужен рисунок, либо список вершин и ребер(но хз надо ли делать эту фичу)
/*#include <iostream>
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
*/

