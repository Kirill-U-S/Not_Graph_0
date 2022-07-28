//�������� �� ������������
#include "Libraries.h"

void multi(Graph g) {
    const int N = sqrt(g.A.size());
    /*����������� ������������ ������� �*/
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
            if (!smezh[j][j]) //�� ������� ���������(��) ������ ���� ���� 
                gd = false;
            if (i != j && smezh[i][j] > 1)   //���� �� ���� ����� (�� ������� ��) ������ ���� �������(������� ������ ���� ����� 2 ��� �����)
                multi = true;
        }
    }
    if (multi && gd)
        std::cout << "multigraph";
    else
        std::cout << "not multi";
}
