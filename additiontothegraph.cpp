//����� ������� ��������� ��� ���������� � �����
#include "Libraries.h"

//TODO: ���������� ��������� � �����
//TODO: ������ ������� � �����
//TODO: ������� ����(������ ��� �������(����� �� �� ������ ����), ���� �� ���� ������ �� ������ ����) � ����
//TODO: �������������� ���������
//TODO: �����������, ����������� � �������� ������
//TODO: �������� ��������
//TODO: ��������� ������, ������� ��������� � ������ �������(sgrt, �����)


void adtograph(Graph g) {
    const int N = sqrt(g.A.size());
    int** dop = new int* [N];

    /*����������� ������������ ������� �*/
    int** smezh = new int* [N];
    for (int i = 0; i < N; i++) {
        smezh[i] = new int[N];
        dop[i] = new int[N];
    }
        

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            smezh[i][j] = g.A[i * N + j];

    //0 ������ �� 1 � ��������
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