#include "Libraries.h"

void simple_cycles(Graph g)
{
    const int N = sqrt(g.A.size());
    int** arr = new int* [N];
    //буферный массив циклов
    std::vector<int> bb;
    std::vector<std::vector<int>> buf;

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
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (smezh[i][j] && !arr[i][j])
            {
                arr[i][j] = 1;
                for (int z = j + 1; z < N; z++)
                {
                    //буфер для буфера
                    std::vector<int> bb;
                    if (smezh[j][z] && smezh[z][i])
                    {
                        //проверка на наличие данного цикла
                        bool flag = true;
                        bb.push_back(i);
                        bb.push_back(j);
                        bb.push_back(z);
                        sort(bb.begin(), bb.end());

                        for (int i = 0; i < buf.size(); i++)
                            if (buf[i][0] == bb[0] && buf[i][1] == bb[1] && buf[i][2] == bb[2])
                                flag = false;
                        //------------------------
                        if (flag) {
                            arr[j][z] = arr[z][j] = 1;
                            std::cout << i << " - " << j << " - " << z << " - " << i << std::endl;

                            //добавление цикла
                            buf.push_back(bb);
                        }
                    }
                }
            }
        }
    }
}