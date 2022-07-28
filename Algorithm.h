#include "Class_Graph.h"

void deg(Graph g);
void simple_cycles(Graph g);
void prima(Graph g);
void pq_adjacency(Graph g);
void adtograph(Graph g);
void complete(Graph g);
void psevdo(Graph g);
void multi(Graph g);
void find_cycles(Graph g);
int find_cycles_fact(Graph g);
void dfs(int u, int** arr, std::vector<int> path, bool* versh, int& dlina, std::vector<std::vector<int>>& arrpath, int N);
void regular(Graph g);
void kraskala(Graph g);