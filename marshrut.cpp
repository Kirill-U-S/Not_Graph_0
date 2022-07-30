//������� �� ����
#include "Libraries.h"

void reachability(Graph g) {
    const int N = sqrt(g.A.size());
    Graph a = Graph(N);
    a = g;
    int** matrix = reachability_m(a);  //���������� ������� ������������
    bool flag = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] != 1)    //��� �������� ������ ������� ������ ���� ��������� �� ��� �������� �����
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
