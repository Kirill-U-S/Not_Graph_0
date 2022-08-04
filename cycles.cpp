//����� ������ � ����� �� �� �����
#include "Libraries.h"

using namespace std;
//TODO: ��������� ��������� ������ �������, �������, ��� ��� �������, ����� ��������� �����������
int dfs_cut(int nach, int v, int N, int path_dlina, vector<vector<int>> arr) {
	path_dlina++;

	for (int u = 0; u < N; u++) {
		int y = 0;
		if (arr[v][u] > 0) {
			if (u != nach) {
				vector<vector<int>> copy;
				vector<int> g(N, 0);

				for (int i = 0; i < N; i++)
					copy.push_back(g);

				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						copy[i][j] = arr[i][j];

				copy[v][u] = 0;
				copy[u][v] = 0;

				y = dfs_cut(nach, u, N, path_dlina, copy);
			}
			else if (u == nach && path_dlina > 2) {
				path_dlina--;
				return -1;
			}
		}
		if (y == -1)
			return y;
	}
	path_dlina--;
	return 0;
}

void dfs(int u, int** arr, vector<int> path, bool* versh, int& dlina, vector<vector<int>>& arrpath, int N) {
	path.push_back(u);  //������� � ������� �� ��������, � � �������
	dlina++;
	versh[u] = true;

	for (int v = 0; v < N; v++) {
		if (arr[u][v] > 0) {     //���� ����� ��������� ���� �����
			if (v != path[0] && !versh[v]) {  //�������� �� ���������� � ��������� �������� ����(�� 76 ������) � ����� versh ��� �� ����� ���
				dfs(v, arr, path, versh, dlina, arrpath, N);
			}
			else if (v == path[0] && dlina > 2) {    //���������� ��������� �������� � ����� �� �� ������ �� ������ � ���� �� �����(� � ������ ������������� ������ ����)
				path.push_back(v);     //��������� ��������� ������� �����
				arrpath.push_back(path);  //���� ���� ��������� � ������� arrpath
				path.pop_back();       //������� ������ ��� ��������� ����
			}
		}
	}

	path.pop_back();  //����� �� ����� ��� ��� �� ����� ������ ������ �����(������� �� ����� �����������), ������� �������
	dlina--;
	versh[u] = false;
}

void find_cycles(Graph g) {
	const int N = sqrt(g.A.size());
	int dlina = 0;
	int** arr;
	bool* versh;

	vector<int> path;
	vector<vector<int>> arrpath;
	/*-����������� ������������ ������� �-*/
	versh = new bool[N];
	arr = new int* [N];

	for (int i = 0; i < N; i++)
		versh[i] = false;

	for (int i = 0; i < N; i++)
		arr[i] = new int[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr[i][j] = g.A[i * N + j];
	/*------------------------------------*/


	/*-���������� �������-*/
	/* int arr[N][N] = {
		 {0, 1, 1, 0},
		 {1, 0, 1, 1},
		 {1, 1, 0, 1},
		 {0, 1, 1, 0}
	 };*/

	 /*int arr[N][N] = {
		 {0, 1, 1, 0, 0},
		 {1, 0, 1, 0, 0},
		 {1, 1, 0, 1, 1},
		 {0, 0, 1, 0, 1},
		 {0, 0, 1, 1, 0}
	 };
	 */
	 /*--------------------*/

	for (int i = 0; i < N; i++)
		dfs(i, arr, path, versh, dlina, arrpath, N);

	/*-���������� ������ �����-*/
	/*-�������� ������-*/
	vector<vector<vector<int>>> buf;

	/*-���������� �� ������� ������-*/
	for (int i = 0; i < arrpath.size() - 1; i++)
		for (int j = 0; j < arrpath.size() - i - 1; j++)
			if (arrpath[j].size() > arrpath[j + 1].size())
				arrpath[j].swap(arrpath[j + 1]);
	/*------------------------------*/

	/*-���������� ���������� ������� ������-*/
	buf.push_back(arrpath);
	/*--------------------------------------*/

	for (int i = 0; i < buf[0].size(); i++) {
		/*-��������� ������-*/
		buf[0][i].pop_back();

		/*-���������� ����� ��������-*/
		sort(buf[0][i].begin(), buf[0][i].end());
	}

	/*-���������� ���������� ��������-*/
	for (int i = 0; i < buf[0].size(); i++) {
		for (int j = 0; j < buf[0].size(); j++) {
			if (i != j && buf[0][i].size() == buf[0][j].size()) {
				bool flag = true;
				for (int k = 0; k < buf[0][i].size(); k++)
					if (buf[0][i][k] != buf[0][j][k])
						flag = false;

				if (flag)
					for (int k = 0; k < buf[0][j].size(); k++)
						buf[0][j][k] = -1;                      //���� �������� �����������
			}
		}
	}
	/* --------------------------------*/

		/*-����� - */
	for (int i = 0; i < buf[0].size(); i++) {
		for (int j = 0; j < buf[0][i].size(); j++)
			if (buf[0][i][j] == -1)
				break;
			else {
				cout << buf[0][i][j] << " ";
			}


		if (buf[0][i][0] != -1)
			cout << buf[0][i][0] << "\n";

	}
	//���������� ������� � ��������� �����
	int girth = buf[0][0].size(); //������
	int P = buf[0][buf[0].size() - 1].size();
	std::cout << "girth: " << girth << std::endl;
	std::cout << "perimetr: " << P << std::endl;  //TODO: ��������������!


}