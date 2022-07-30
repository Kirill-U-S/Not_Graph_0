class Graph {
public:
	//TODO: правильно подобрать роль массиву вершин
	std::vector<int> V;//массив вершин
	std::vector<int> E;//массив ребер

	std::vector<int> A;//матрица смежности
	std::vector<int> D;//матрица pq
	Graph();
	Graph(int V);
	Graph(int V, int reb);
};