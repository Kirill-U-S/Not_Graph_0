#include "Libraries.h"

using namespace std;

//TODO: ������ ������ �������� (�� ������� ���� �� ����� �������) - � ������ ������ ��� ����, �� ������ � ���, ��� � ������� �� �� ��������� ��������))

void DA(int V_O, int v, int arr[4][4], bool versh[4], vector<int> path, vector<int> weigth_path, vector<vector<int>>& arrpath) {
	path.push_back(v);
	versh[v] = true;

	for (int i = 0; i < V_O; i++) {
		if (!versh[i] && arr[v][i] > 0) {
			weigth_path.push_back(arr[v][i]);

			DA(4, i, arr, versh, path, weigth_path, arrpath);
		}
	}

	/*-�������� �� ����������� ����-*/
	bool flag = true;
	for (int i = 0; i < V_O; i++)
		if (!versh[i])
			flag = false;

	/*-���� ���� ��������� - ��������� ��� ��������-*/
	if (flag) {
		// for(int i = 0; i < path.size(); i++)
			// cout<<path[i]<< " ";

		arrpath.push_back(path);
		arrpath.push_back(weigth_path);
	}

	/*-�������� ����� - ��� �����-*/
	versh[v] = false;
	path.pop_back();
	weigth_path.pop_back();
}
/*������*/
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
//	/*-��������-*/
//	DA(4, 0, arr, versh, path, weigth_path, arrpath);
//	
//	/*-�����-*/
//	for(int i = 0; i < arrpath.size(); i++){
//		for(int j = 0; j < arrpath[i].size(); j++){
//			cout<<arrpath[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//}