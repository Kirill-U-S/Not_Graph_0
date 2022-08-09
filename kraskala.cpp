#include "Libraries.h"

void kraskal(Graph g) {
    const int N = sqrt(g.A.size());

    /*копирование изначального массива А*/
    int** smezh = new int* [N];
    int sum = 0, vertices = 0;
    std::vector<int> minn;
    std::vector<int> versh;
    std::vector<std::vector<int>> vert;
    std::vector<std::vector<int>> buf;
    for (int i = 0; i < N; i++)
    {
        smezh[i] = new int[N];
        std::vector<int> e(N, 0);
        vert.push_back(e);
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            smezh[i][j] = g.A[i * N + j];

    for (int i = 0; i < N; i++) 
        for (int j = i; j < N; j++) 
            if (smezh[i][j] > 0) 
                minn.push_back(smezh[i][j]); //все ребра существующие ребра заносим в вектор

    sort(minn.begin(), minn.end());

    for (int z = 0; z < minn.size(); z++) {
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (minn[z] == smezh[i][j]) { //находим ребро в матрице смежности
                    /*for (int k = 0; k < N; k++) {
                        int degr = 0;
                        for (int f = k; f < N; f++)
                            if (vert[k][f])
                                degr += 1;
                        if (degr > 0 && degr < 3) {
                            t = false;
                            break;
                        }
                    }*///проверка на циклы(-)
                    vert[i][j] = vert[j][i] = minn[z];
                    int flag = 0;
                    int g = 0;
                    /*поиск циклов через обрезанный поиск*/
                    for (int i = 0; i < N; i++)
                    {
                        flag = 0;
                        int y = 0;
                        /*проверка на единичную вершину*/
                        for (int j = 0; j < N; j++)
                            if (vert[i][j] != 0)
                                y++;
                        /*-----------------------------*/

                        if (y != 1)
                            flag = dfs_cut(i, i, N, 0, vert);

                        if (flag == -1)
                            g += flag;
                        else if (flag > 0)
                            std::cout << "ERROR\n";
                    }
                    /*-----------------------------------*/
                    if (g < 0)
                        vert[i][j] = vert[j][i] = 0;
                    else {
                        std::vector<int> versh;
                        bool fl = true;
                        versh.push_back(i);
                        versh.push_back(j);
                        for (int i = 0; i < buf.size(); i++)
                            if (buf[i][0] == versh[0] && buf[i][1] == versh[1])
                                fl = false;
                        if (fl) {
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


























//алгоритм Краскала - старая версия
//#include "Libraries.h"
//#include "empty_class.h"
//
//void kraskala(Graph g) {
//    const int N = sqrt(g.A.size());
//
//    /*копирование изначального массива А*/
//    int** smezh = new int* [N];
//    for (int i = 0; i < N; i++)
//        smezh[i] = new int[N];
//
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++)
//            smezh[i][j] = g.A[i * N + j];
//
//    int sum = 0;
//    int min = INT_MAX;
//    std::vector<int> minn;
//    Graph a = Graph(N);                      //заполнила нулями в class.h удалила инициализацию(т е скорее всего надо создать                  
//    std::vector<std::vector<int>> buf;       //класс либо что-то еще вместо a, чтобы передавать в функцию find_cycles)
//
//    /*по возрастанию веса добавила ребра в minn*/
//    for (int i = 0; i < N; i++) {
//        for (int j = i; j < N; j++) {
//            if (smezh[i][j] > 0) {
//                min = smezh[i][j];
//                minn.push_back(min); 
//            }
//        }
//    }
//    sort(minn.begin(), minn.end());
//
//    for (int z = 0; z < minn.size(); z++) {
//        for (int i = 0; i < N; i++) {
//            for (int j = i; j < N; j++) {
//                if (minn[z] == smezh[i][j]) {                       //находим то самое ребро
//                    a.A[i * N + j] = a.A[j * N + i] = smezh[i][j];  //добавляем его в массив
//
//                    if (find_cycles_fact(a))  //тут неувязка, в эту функцию передается граф, который весь в нулях, а в kraskala - граф с таблицей смежности от пользователя
//                        a.A[i * N + j] = a.A[j * N + i] = 0;    //если находим циклы, то зануляем
//                    else {
//                        std::vector<int> versh;
//                        bool flag = true;
//                        versh.push_back(i);
//                        versh.push_back(j);  
//                        for (int i = 0; i < buf.size(); i++)
//                            if (buf[i][0] == versh[0] && buf[i][1] == versh[1])
//                                flag = false;
//                        if (flag) {                    //тут проверка на то, что не было такого ребра
//                            sum += minn[z];
//                            std::cout << i << " - " << j << " Weight: " << minn[z] << ". Interim amount: " << sum << std::endl;
//                            buf.push_back(versh);
//                        }
//                    }
//                }
//            }
//        }
//    }
//}