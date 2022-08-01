//нахождение компонент связности
#include "Libraries.h"

using namespace std;
void rs(int u, int** arr, bool* versh, vector<int>& spisok, int N) {
	spisok.push_back(u);
	versh[u] = true;

	for (int i = 0; i < N; i++) {
		if (arr[u][i] > 0 && !versh[i]) {
			arr[u][i] = 0;
			arr[i][u] = 0;
			rs(i, arr, versh, spisok, N);
		}
	}
}

void deg_of_connect(Graph g) {
	/*работающий пример*/
	//int arr[N][N]{
	//	{0, 1, 0, 0, 0, 0, 0, 0, 0},
	//	{1, 0, 1, 0, 0, 0, 0, 0, 0},
	//	{0, 1, 0, 1, 0, 0, 0, 0, 0},
	//	{0, 0, 1, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 1, 0, 0, 0},
	//	{0, 0, 0, 0, 1, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 1},
	//	{0, 0, 0, 0, 0, 0, 0, 1, 0},
	//};
	/*-----------------*/
	/*копирование изначального массива*/
	int N = sqrt(g.A.size());
	int** arr = new int* [N];
	for (int i = 0; i < N; i++)
		arr[i] = new int[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr[i][j] = g.A[i * N + j];
	/*--------------------------------*/

	vector<int> spisok;
	vector<vector<int>> obsh;

	bool* versh;
	versh = new bool[N];
	for (int i = 0; i < N; i++)
		versh[i] = false;

	for (int i = 0; i < N; i++) {
		if (!versh[i]) {
			rs(i, arr, versh, spisok, N);
			obsh.push_back(spisok);
			spisok.clear();
		}
	}

	for (int i = 0; i < obsh.size(); i++) {
		cout << obsh[i].size() << ": ";
		for (int j = 0; j < obsh[i].size(); j++)
			cout << obsh[i][j] << " ";
		cout << "\n";
	}

	cout << "count of: " << obsh.size();
}