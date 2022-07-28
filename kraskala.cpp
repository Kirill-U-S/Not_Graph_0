//алгоритм Краскала
#include "Libraries.h"
#include "empty_class.h"

void kraskala(Graph g) {
    const int N = sqrt(g.A.size());

    /*копирование изначального массива А*/
    int** smezh = new int* [N];
    for (int i = 0; i < N; i++)
        smezh[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            smezh[i][j] = g.A[i * N + j];

    int sum = 0;
    int min = INT_MAX;
    std::vector<int> minn;
    Graph a = Graph(N);                      //заполнила нулями в class.h удалила инициализацию(т е скорее всего надо создать                  
    std::vector<std::vector<int>> buf;       //класс либо что-то еще вместо a, чтобы передавать в функцию find_cycles)

    /*по возрастанию веса добавила ребра в minn*/
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (smezh[i][j] > 0) {
                min = smezh[i][j];
                minn.push_back(min); 
            }
        }
    }
    sort(minn.begin(), minn.end());

    for (int z = 0; z < minn.size(); z++) {
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (minn[z] == smezh[i][j]) {                       //находим то самое ребро
                    a.A[i * N + j] = a.A[j * N + i] = smezh[i][j];  //добавляем его в массив

                    if (find_cycles_fact(a))  //тут неувязка, в эту функцию передается граф, который весь в нулях, а в kraskala - граф с таблицей смежности от пользователя
                        a.A[i * N + j] = a.A[j * N + i] = 0;    //если находим циклы, то зануляем
                    else {
                        std::vector<int> versh;
                        bool flag = true;
                        versh.push_back(i);
                        versh.push_back(j);  
                        for (int i = 0; i < buf.size(); i++)
                            if (buf[i][0] == versh[0] && buf[i][1] == versh[1])
                                flag = false;
                        if (flag) {                    //тут проверка на то, что не было такого ребра
                            sum += minn[z];
                            std::cout << i << " - " << j << " Weight: " << minn[z] << ". Interim amount: " << sum << std::endl;
                            buf.push_back(versh);
                        }
                    }
                }
            }
        }
    }
}