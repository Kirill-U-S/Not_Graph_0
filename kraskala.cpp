//�������� ��������
#include "Libraries.h"
#include "empty_class.h"

void kraskala(Graph g) {
    const int N = sqrt(g.A.size());

    /*����������� ������������ ������� �*/
    int** smezh = new int* [N];
    for (int i = 0; i < N; i++)
        smezh[i] = new int[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            smezh[i][j] = g.A[i * N + j];

    int sum = 0;
    int min = INT_MAX;
    std::vector<int> minn;
    Graph a = Graph(N);                      //��������� ������ � class.h ������� �������������(� � ������ ����� ���� �������                  
    std::vector<std::vector<int>> buf;       //����� ���� ���-�� ��� ������ a, ����� ���������� � ������� find_cycles)

    /*�� ����������� ���� �������� ����� � minn*/
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
                if (minn[z] == smezh[i][j]) {                       //������� �� ����� �����
                    a.A[i * N + j] = a.A[j * N + i] = smezh[i][j];  //��������� ��� � ������

                    if (find_cycles_fact(a))  //��� ��������, � ��� ������� ���������� ����, ������� ���� � �����, � � kraskala - ���� � �������� ��������� �� ������������
                        a.A[i * N + j] = a.A[j * N + i] = 0;    //���� ������� �����, �� ��������
                    else {
                        std::vector<int> versh;
                        bool flag = true;
                        versh.push_back(i);
                        versh.push_back(j);  
                        for (int i = 0; i < buf.size(); i++)
                            if (buf[i][0] == versh[0] && buf[i][1] == versh[1])
                                flag = false;
                        if (flag) {                    //��� �������� �� ��, ��� �� ���� ������ �����
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