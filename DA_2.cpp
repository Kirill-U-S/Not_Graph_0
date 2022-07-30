#include "Libraries.h"

using namespace std;

//TODO: данный способ работает (по крайней мере на одном примере) - я нахожу вообще все пути, но вопрос в том, что я немного не по алгоритму действую))

void DA(int V_O, int v, int arr[4][4], bool versh[4], vector<int> path, vector<int> weigth_path, vector<vector<int>>& arrpath){
	path.push_back(v);
	versh[v] = true;
	
	for(int i = 0; i < V_O; i++){
		if(!versh[i] && arr[v][i] > 0){
			weigth_path.push_back(arr[v][i]);
			
			DA(4, i, arr, versh, path, weigth_path, arrpath);
		}
	}
	
	/*-проверка на целостность пути-*/
	bool flag = true;
	for(int i = 0; i < V_O; i++)
		if(!versh[i])
			flag = false;
	
	/*-если путь целостный - записываю его значения-*/
	if(flag){
		// for(int i = 0; i < path.size(); i++)
			// cout<<path[i]<< " ";
		
		arrpath.push_back(path);
		arrpath.push_back(weigth_path);
	}
	
	/*-удаление путей - шаг назад-*/
	versh[v] = false;
	path.pop_back();
	weigth_path.pop_back();
}
/*пример*/
//int main(){
//	int N;
//	int arr[4][4] = {
//		{0, 2, 1, 0},
//		{1, 0, 3, 1},
//		{1, 1, 0, 1},
//		{0, 4, 1, 0}
//	};
//	bool versh[4] = {false, false, false, false};
//	vector<int> path;
//	vector<int> weigth_path;
//	vector<vector<int>> arrpath;
//	
//	/*-алгоритм-*/
//	DA(4, 0, arr, versh, path, weigth_path, arrpath);
//	
//	/*-вывод-*/
//	for(int i = 0; i < arrpath.size(); i++){
//		for(int j = 0; j < arrpath[i].size(); j++){
//			cout<<arrpath[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//}