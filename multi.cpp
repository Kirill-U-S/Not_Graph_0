//является ли мультиграфом
#include "Libraries.h"

void multi(Graph g) {
    const int N = sqrt(g.A.size());
    /*копирование изначального массива А*/
    int** smezh = new int* [N];
    for (int i = 0; i < N; i++)
        smezh[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            smezh[i][j] = g.A[i * N + j];
    bool multi = false;    
    bool gd = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!smezh[j][j]) //на главной диагонали(гг) должны быть нули 
                gd = false;
            if (i != j && smezh[i][j] > 1)   //хотя бы одно ребро (не элемент гг) должно быть кратным(элемент должен быть равен 2 или более)
                multi = true;
        }
    }
    if (multi && gd)
        std::cout << "multigraph";
    else
        std::cout << "not multi";
}
