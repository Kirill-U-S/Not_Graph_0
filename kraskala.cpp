#include <iostream>
#include <vector>
#include <algorithm>
#include "Libraries.h"

int kraskal()
{
    const int N = 10;
    int smezh[N][N] =
    {
        {0,10,0,0,20,0,0,15,0,0},
        {10,0,5,0,0,0,0,2,8,9},
        {0,5,0,16,0,0,0,0,4,0},
        {0,0,16,0,28,25,0,0,11,9},
        {20,0,0,28,0,15,0,0,0,0},
        {0,0,0,25,15,0,10,0,7,5},
        {0,0,0,0,0,10,0,11,0,3},
        {15,2,0,0,0,0,11,0,4,14},
        {0,8,4,11,0,7,0,4,0,0},
        {0,9,0,9,0,5,3,14,0,0}
    };

    int sum = 0, vertices = 0;
    int min = INT_MAX;
    std::vector<int> minn;
    std::vector<int> versh;
    std::vector<std::vector<int>> vert;
    std::vector<std::vector<int>> buf;

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
                if (minn[z] == smezh[i][j]) {
                    /*for (int k = 0; k < N; k++) {
                        int degr = 0;
                        for (int f = k; f < N; f++)
                            if (vert[k][f])
                                degr += 1;
                        if (degr > 0 && degr < 3) {
                            t = false;
                            break;
                        }
                    }*///�������� �� �����(-)
                    vert[i][j] = vert[i][j] = minn[z];
                    int flag = 0;
                    /*����� ������ ����� ���������� �����*/
                    for (int i = 0; i < N; i++)
                    {
                        bool* versh = new bool[N];
                        for (int i = 0; i < N; i++)
                            versh[i] = false;

                        flag += dfs_cut(i, i, N, 0, versh, vert);
                        if (flag > 0)
                            break;
                    }
                    /*-----------------------------------*/
                    if (flag > 0)
                        vert[i][j] = vert[i][j] = 0;
                    else {
                        std::vector<int> versh;
                        bool flag = true;
                        versh.push_back(i);
                        versh.push_back(j);
                        for (int i = 0; i < buf.size(); i++)
                            if (buf[i][0] == versh[0] && buf[i][1] == versh[1])
                                flag = false;
                        if (flag == 0) {
                            sum += minn[z];
                            std::cout << i << " - " << j << " Weight: " << minn[z] << ". Interim amount: " << sum << std::endl;
                            buf.push_back(versh);
                        }
                    }
                }
            }
        }
    }
    return 0;
}


























//�������� �������� - ������ ������
//#include "Libraries.h"
//#include "empty_class.h"
//
//void kraskala(Graph g) {
//    const int N = sqrt(g.A.size());
//
//    /*����������� ������������ ������� �*/
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
//    Graph a = Graph(N);                      //��������� ������ � class.h ������� �������������(� � ������ ����� ���� �������                  
//    std::vector<std::vector<int>> buf;       //����� ���� ���-�� ��� ������ a, ����� ���������� � ������� find_cycles)
//
//    /*�� ����������� ���� �������� ����� � minn*/
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
//                if (minn[z] == smezh[i][j]) {                       //������� �� ����� �����
//                    a.A[i * N + j] = a.A[j * N + i] = smezh[i][j];  //��������� ��� � ������
//
//                    if (find_cycles_fact(a))  //��� ��������, � ��� ������� ���������� ����, ������� ���� � �����, � � kraskala - ���� � �������� ��������� �� ������������
//                        a.A[i * N + j] = a.A[j * N + i] = 0;    //���� ������� �����, �� ��������
//                    else {
//                        std::vector<int> versh;
//                        bool flag = true;
//                        versh.push_back(i);
//                        versh.push_back(j);  
//                        for (int i = 0; i < buf.size(); i++)
//                            if (buf[i][0] == versh[0] && buf[i][1] == versh[1])
//                                flag = false;
//                        if (flag) {                    //��� �������� �� ��, ��� �� ���� ������ �����
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