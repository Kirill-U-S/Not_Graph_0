//���������� ������� ������������
#include "Libraries.h"

int **reachability_m(Graph g) {
    const int N = sqrt(g.A.size());
    /*����������� ������������ ������� �*/
    int** smezh = new int* [N];
    int** reachability = new int* [N];
    for (int i = 0; i < N; i++) {
        smezh[i] = new int[N];
        reachability[i] = new int[i + 1];
    }
        

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            smezh[i][j] = g.A[i * N + j];
            reachability[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                reachability[i][i] = 1;     //�������� �� ������� ��������� ���������� ������� ���������
            else if (smezh[i][j])           //��� ������� �� ������� ��������� ����� �������� � ����� �������
                reachability[i][j] = reachability[j][i] = 1;
            else {
                //����� ��������
                int k = i;
                for (int m = 0; m < N; m++) {
                    if (smezh[k][m] && smezh[m][j])
                        reachability[i][j] = reachability[j][i] = 1;
                    else if (smezh[k][m])
                        k = m;
                }
            }
            std::cout << reachability[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return reachability;
}