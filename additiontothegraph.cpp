//вывод таблицы смежности для дополнения к графу
#include "Libraries.h"

//TODO: компоненты связности и мосты
//TODO: радиус диаметр и центр
//TODO: эйлеров цикл(обойти все вершины(можно не по одному разу), ходя по всем ребрам по одному разу) и цепь
//TODO: тудудудудудуду тудудуууу
//TODO: объединение, пересечение и разность графов
//TODO: доделать краскала
//TODO: исправить ошибки, которые возникают в данном кроекте(sgrt, класс)


void adtograph(Graph g) {
    const int N = sqrt(g.A.size());
    int** dop = new int* [N];

    /*копирование изначального массива А*/
    int** smezh = new int* [N];
    for (int i = 0; i < N; i++) {
        smezh[i] = new int[N];
        dop[i] = new int[N];
    }
        

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            smezh[i][j] = g.A[i * N + j];

    //0 меняем на 1 и наоборот
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (smezh[i][j] == 0)
                dop[i][j] = 1;
            else
                dop[i][j] = 0;
            dop[i][i] = 0;
            std::cout << dop[i][j] << " ";
        }
        std::cout << std::endl;
    }
}