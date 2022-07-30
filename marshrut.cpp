//связный ли граф
#include "Libraries.h"

void reachability(Graph g) {
    const int N = sqrt(g.A.size());
    Graph a = Graph(N);
    a = g;
    int** matrix = reachability_m(a);  //построение матрицы достижимости
    bool flag = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] != 1)    //все элементы данной матрицы должны быть единицами по опр связного графа
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
        std::cout << "connected";
    else
        std::cout << "disconnected";
}
