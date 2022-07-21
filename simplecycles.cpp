#include <vector>
#include <algorithm>
#include "Class_Graph.h"
#include "Algorithm.h"

void simple_cycles(Graph g)
{
    const int N = 4;
    int smezh[N][N] =
    {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };
    int arr[N][N]{}, versh[N] = { 1 }, y = 0, x = 0, sum = 0, k = 0;
    //буферный массив циклов
    std::vector<int> bb;
    std::vector<std::vector<int>> buf;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (smezh[i][j] && !arr[i][j])
            {
                arr[i][j] = 1;
                x = i;
                y = j;
                for (int z = y + 1; z < N; z++)
                {
                    //буфер для буфера
                    std::vector<int> bb;
                    if (smezh[y][z])
                    {
                        //проверка на наличие данного цикла
                        bool flag = true;
                        bb.push_back(x);
                        bb.push_back(y);
                        bb.push_back(z);
                        sort(bb.begin(), bb.end());

                        for (int i = 0; i < buf.size(); i++)
                            if (buf[i][0] == bb[0] && buf[i][1] == bb[1] && buf[i][2] == bb[2])
                                flag = false;
                        //------------------------
                        if (flag) {
                            arr[y][z] = arr[z][y] = 1;
                            std::cout << x << " - " << y << " - " << z << std::endl;

                            //добавление цикла
                            buf.push_back(bb);
                        }
                    }

                    //старая версия
                    //if (smezh[y][z] && flag)
                    //{
                    //    arr[y][z] = arr[z][y] = 1;
                    //    std::cout << x << " - " << y << " - " << z << " - " << x << std::endl;
                    //    
                    //    //добавление цикла
                    //    bb.push_back(x);
                    //    bb.push_back(y);
                    //    bb.push_back(z);

                    //    sort(bb.begin(), bb.end());
                    //    buf.push_back(bb);
                    //}
                }
            }
        }
    }
}