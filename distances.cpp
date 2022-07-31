//эксцентриситет, радиус, диаметр, центр и в комментариях кратчайшие маршруты 
#include "Libraries.h"
using namespace std;
void marshrutiki(int u, int** arr, vector<int> path, bool* versh, vector<vector<int>>& arrpath, int N) {
	path.push_back(u); 
	versh[u] = true;

	for (int v = 0; v < N; v++) {
		if (arr[u][v] > 0) {    
			if (!versh[v]) {  
				marshrutiki(v, arr, path, versh, arrpath, N);
			}
			else {   
				path.push_back(v);   
				arrpath.push_back(path);  
				path.pop_back();     
			}
		}
	}

	path.pop_back();  
	versh[u] = false;
}

void distances(Graph g) {
	const int N = sqrt(g.A.size());
	int max = 0, min = INT_MAX, dlina = 0;
	int** arr;
	bool* versh;
	int* ver;

	vector<int> path;
	vector<vector<int>> arrpath;
	/*-копирование изначального массива А-*/
	versh = new bool[N];
	arr = new int* [N];
	ver = new int [N];

	for (int i = 0; i < N; i++) {
		versh[i] = false;
		ver[i] = 0;
		arr[i] = new int[N];
		for (int j = 0; j < N; j++)
			arr[i][j] = g.A[i * N + j];
	}
	/*------------------------------------*/


	/*-работающие примеры-*/
	//    int arr[N][N] = {
	//		{0, 1, 1, 0, 0},
	//		{1, 0, 1, 0, 0},
	//		{1, 1, 0, 1, 1},
	//		{0, 0, 1, 0, 1},
	//		{0, 0, 1, 1, 0}
	//	};
	/*int arr[N][N] = {
		{0,1,0,0,0},
		{1,0,1,1,0},
		{0,1,0,1,0},
		{0,1,1,0,1},
		{0,0,0,1,0}
	};*/
	 /*--------------------*/
	for (int i = 0; i < N; i++)
		marshrutiki(i, arr, path, versh, arrpath, N);

	/*-сортировка верных путей-*/
	/*-буферный массив-*/
	vector<vector<vector<int>>> buf;

	/*-добавление имеющегося массива циклов-*/
	buf.push_back(arrpath);
	/*--------------------------------------*/

	for (int i = 0; i < buf[0].size(); i++) {
		/*-отрезание концов-*/
		buf[0][i].pop_back();

		/*-сортировка путей векторов-*/
		sort(buf[0][i].begin(), buf[0][i].end());
	}

	/*-исключение одинаковых векторов-*/
	for (int i = 0; i < buf[0].size(); i++) {
		for (int j = 0; j < buf[0].size(); j++) {
			if (i != j && buf[0][i].size() == buf[0][j].size()) {
				bool flag = true;
				for (int k = 0; k < buf[0][i].size(); k++)
					if (buf[0][i][k] != buf[0][j][k])
						flag = false;

				if (flag)
					for (int k = 0; k < buf[0][j].size(); k++)
						buf[0][j][k] = -1;                      //если элементы повторяются
			}
		}
	}
	/* --------------------------------*/
	//исключение маршрутов, которые по размеру больше простых(которые мы и ищем)
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
	//эксцентриситет
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < buf[0].size(); j++) {
			if (buf[0][j][0] == i || buf[0][j][buf[0][j].size() - 1] == i)
				if (ver[i] < buf[0][j].size())
					ver[i] = buf[0][j].size() - 1;
		}
	}

	/*-вывод минимальных расстояний*/
	/*for (int i = 0; i < buf[0].size(); i++) {
		for (int j = 0; j < buf[0][i].size(); j++)
			if (buf[0][i][j] == -1)
				break;
			else {
				cout << buf[0][i][j] << " ";
			}
		if (buf[0][i][0] != -1)
			cout << "\n";
	}*/
	
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
