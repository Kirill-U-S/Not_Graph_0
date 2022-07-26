#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int u, int arr[5][5], vector<int> path, int versh[5], int& dlina, vector<vector<int>>& arrpath){
	path.push_back(u);
	dlina++;
	versh[u] = true;
	
	for(int v = 0; v < 5; v++){
		if(arr[u][v] > 0){
			if(v != path[0] && !versh[v]){
				dfs(v, arr, path, versh, dlina, arrpath);
			}
			else if(v == path[0] && dlina > 2){
				path.push_back(v);
				arrpath.push_back(path);
				path.pop_back();
			}
		}
	}
	
	path.pop_back();
	dlina--;
	versh[u] = false;
}

int main(){
	const int N =5;
	// int arr[N][N] = {
		// {0, 1, 1, 0},
		// {1, 0, 1, 1},
		// {1, 1, 0, 1},
		// {0, 1, 1, 0}
	// };
	
	int arr[N][N] = {
		{0, 1, 1, 0, 0},
		{1, 0, 1, 0, 0},
		{1, 1, 0, 1, 1},
		{0, 0, 1, 0, 1},
		{0, 0, 1, 1, 0}
	};
	
	int dlina = 0;
	int versh[N] = {false, false, false, false};
	vector<int> path;
	vector<vector<int>> arrpath;
	
	for(int i = 0; i < N; i++){
		dfs(i, arr, path, versh, dlina, arrpath);
	}
	
	// for(int i = 0; i < arrpath.size(); i++){
		// for(int j = 0; j < arrpath[i].size(); j++)
			// cout << arrpath[i][j] << " ";
		
		// cout<<"\n";
	// }
	/*-сортировка верных путей-*/
	/*-буферный массив-*/
	vector<vector<vector<int>>> buf;

	/*-сортировка по размеру циклов-*/
	for(int i = 0; i < arrpath.size() - 1; i++)
		for(int j = 0; j < arrpath.size() - i - 1; j++)
			if(arrpath[j].size() > arrpath[j+1].size())
				arrpath[j].swap(arrpath[j+1]);	
	/*------------------------------*/
	
	/*-добавление имеющегося массива циклов-*/
	buf.push_back(arrpath);	
	/*--------------------------------------*/
	
	for(int i = 0; i < buf[0].size(); i++){
		/*-отрезание концов-*/
		buf[0][i].pop_back();
		
		/*-сортировка путей векторов-*/
		sort(buf[0][i].begin(), buf[0][i].end());
	}
	
	/*-исключение одинаковых векторов-*/
	for(int i = 0; i < buf[0].size(); i++){
		for(int j = 0; j < buf[0].size(); j++){
			if(buf[0][i].size() == buf[0][j].size()){
				bool flag = true;
				for(int k = 0; k < buf[0][i].size(); k++)
					if(buf[0][i][k] != buf[0][j][k])
						flag = false;
				
				if(flag)
					buf[0].erase(buf[0].begin()+j);				
			}
		}
	}
	/*--------------------------------*/
	
	/*-вывод-*/
	for(int i = 0; i < buf[0].size(); i++){
		for(int j = 0; j < buf[0][i].size(); j++)
			cout<<buf[0][i][j]<<" ";	
		cout<<"\n";
	}
}