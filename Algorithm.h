#include "Class_Graph.h"

void deg(Graph g);
void simple_cycles(Graph g);
void prima(Graph g);
void pq_pp(Graph g);
void pp_pq(Graph g);
void adtograph(Graph g);
void complete(Graph g);
void psevdo(Graph g);
void multi(Graph g);
void find_cycles(Graph g);
void dfs(int u, int** arr, std::vector<int> path, bool* versh, int& dlina, std::vector<std::vector<int>>& arrpath, int N);
int dfs_cut(int nach, int u, int N, int dlina, bool* versh, vector<vector<int>>& arr);
void regular(Graph g);
int kraskal();
//void kraskala(Graph g);
int** reachability_m(Graph g);
void reachability(Graph g);
void deg_of_connect(Graph g);
void distances(Graph g);
void marshrutiki(int u, int** arr, vector<int> path, bool* versh, vector<vector<int>>& arrpath, int N);