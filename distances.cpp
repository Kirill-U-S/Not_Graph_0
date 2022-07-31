#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int u, int arr[5][5], vector<int> path, bool* versh, vector<vector<int>>& arrpath, int N) {
	path.push_back(u);  //вершина с которой мы работаем, т е нулевая
	versh[u] = true;

	for (int v = 0; v < N; v++) {
		if (arr[u][v] > 0) {     //если между вершинами есть ребро
			if (!versh[v]) {  //вершинку мы сравниваем с начальной вершиной пути(см 76 строка) и чтобы versh был не равен тру
				dfs(v, arr, path, versh, arrpath, N);
			}
			else {    //используем начальную вершинку и чтобы мы не ходили по одному и тому же ребру(т е вершин задействовано больше двух)
				path.push_back(v);     //добавляем начальную вершину снова
				arrpath.push_back(path);  //весь путь добавляем к вектору arrpath
				path.pop_back();       //удаляем только что найденный путь
			}
		}
	}

	path.pop_back();  //вышли из цикла так как не можем больше никуда пойти(вершины не могут повторяться), поэтому удаляем
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
	/*-копирование изначального массива А-*/

	for (int i = 0; i < N; i++)
		versh[i] = false;


	/*------------------------------------*/


	/*-работающие примеры-*/
	/* int arr[N][N] = {
		 {0, 1, 1, 0},
		 {1, 0, 1, 1},
		 {1, 1, 0, 1},
		 {0, 1, 1, 0}
	 };*/



	 /*--------------------*/

	for (int i = 0; i < N; i++)
		dfs(i, arr, path, versh, arrpath, N);

	/*-сортировка верных путей-*/
	/*-буферный массив-*/
	vector<vector<vector<int>>> buf;

	/*-сортировка по размеру циклов-*/
	for (int i = 0; i < arrpath.size() - 1; i++)
		for (int j = 0; j < arrpath.size() - i - 1; j++)
			if (arrpath[j].size() > arrpath[j + 1].size())
				arrpath[j].swap(arrpath[j + 1]);
	/*------------------------------*/

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
	//все элементы маршрутов, которые по размеру больше простых(которые мы и ищем), в -1
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

	/*-вывод - */
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
