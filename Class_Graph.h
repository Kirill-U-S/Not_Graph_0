#include "Libraries.h"

class Graph {
public:
	//TODO: ��������� ��������� ���� ������� ������
	std::vector<int> V;
	std::vector<int> E;

	std::vector<int> A;
	std::vector<int> D;
	Graph();
	Graph(int V);
	Graph(int V, int reb);
};