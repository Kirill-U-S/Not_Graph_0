#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int u, int arr[5][5], vector<int> path, bool* versh, vector<vector<int>>& arrpath, int N) {
	path.push_back(u);  //������� � ������� �� ��������, � � �������
	versh[u] = true;

	for (int v = 0; v < N; v++) {
		if (arr[u][v] > 0) {     //���� ����� ��������� ���� �����
			if (!versh[v]) {  //�������� �� ���������� � ��������� �������� ����(�� 76 ������) � ����� versh ��� �� ����� ���
				dfs(v, arr, path, versh, arrpath, N);
			}
			else {    //���������� ��������� �������� � ����� �� �� ������ �� ������ � ���� �� �����(� � ������ ������������� ������ ����)
				path.push_back(v);     //��������� ��������� ������� �����
				arrpath.push_back(path);  //���� ���� ��������� � ������� arrpath
				path.pop_back();       //������� ������ ��� ��������� ����
			}
		}
	}

	path.pop_back();  //����� �� ����� ��� ��� �� ����� ������ ������ �����(������� �� ����� �����������), ������� �������
	versh[u] = false;
}

int main() {
	const int N = 5;
	//    int arr[N][N] = {
	//		{0, 1, 1, 0, 0},
	//		{1, 0, 1, 0, 0},
	//		{1, 1, 0, 1, 1},
	//		{0, 0, 1, 0, 1},
	//		{0, 0, 1, 1, 0}
	//	};
	bool* versh;
	int arr[N][N] = {
		{0,1,0,0,0},
		{1,0,1,1,0},
		{0,1,0,1,0},
		{0,1,1,0,1},
		{0,0,0,1,0}
	};
	versh = new bool[N];
	vector<int> path;
	vector<vector<int>> arrpath;
	/*-����������� ������������ ������� �-*/

	for (int i = 0; i < N; i++)
		versh[i] = false;


	/*------------------------------------*/


	/*-���������� �������-*/
	/* int arr[N][N] = {
		 {0, 1, 1, 0},
		 {1, 0, 1, 1},
		 {1, 1, 0, 1},
		 {0, 1, 1, 0}
	 };*/



	 /*--------------------*/

	for (int i = 0; i < N; i++)
		dfs(i, arr, path, versh, arrpath, N);

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
	//��� �������� ���������, ������� �� ������� ������ �������(������� �� � ����), � -1
	for (int i = 0; i < buf[0].size(); i++) {
		for (int j = 0; j < buf[0].size(); j++) {
			if (buf[0][i][0] == buf[0][j][0] && buf[0][i][buf[0][i].size() - 1] == buf[0][j][buf[0][j].size() - 1] && i != j) {
				if (buf[0][i].size() < buf[0][j].size())
					for (int k = 0; k < buf[0][j].size(); k++)
						buf[0][j][k] = -1;
				else
					for (int k = 0; k < buf[0][i].size(); k++)
						buf[0][i][k] = -1;
			}
		}
	}
	int ver[N]{};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < buf[0].size(); j++) {
			if (buf[0][j][0] == i || buf[0][j][buf[0][j].size() - 1] == i)
				if (ver[i] < buf[0][j].size())
					ver[i] = buf[0][j].size() - 1;
		}
	}

	/*-����� - */
	for (int i = 0; i < buf[0].size(); i++) {
		for (int j = 0; j < buf[0][i].size(); j++)
			if (buf[0][i][j] == -1)
				break;
			else {
				cout << buf[0][i][j] << " ";
			}
		if (buf[0][i][0] != -1)
			cout << "\n";
	}
	int max = 0, min = INT_MAX;
	for (int i = 0; i < N; i++) {
		cout << "for " << i << ": " << ver[i] << endl;
		if (ver[i] > max)
			max = ver[i];
		else if (ver[i] < min)
			min = ver[i];
	}
	cout << "Center: ";
	for (int i = 0; i < N; i++) {
		if (ver[i] == min)
			cout << i << " ";
	}
	cout << "\nDiameter: " << max;
	cout << "\nRadius: " << min;

}
