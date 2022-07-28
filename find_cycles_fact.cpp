//вывод не самих циклов, а только факт существовани€ их в графе
#include "Libraries.h"

int find_cycles_fact(Graph g) {                              
	const int N = sqrt(g.A.size());
	int dlina = 0;
	int** arr;
	bool* versh;

	std::vector<int> path;
	std::vector<std::vector<int>> arrpath;
	/*-копирование изначального массива ј-*/
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

	for (int i = 0; i < N; i++)
		dfs(i, arr, path, versh, dlina, arrpath, N);
	//cout << arrpath.size() << endl;
	if (arrpath.size() == 0)
		return 0;
	else
		return 1;
}