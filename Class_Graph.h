#pragma once
#include <iostream>
#include <vector>

class Graph {
public:
	//TODO: правильно подобрать роль массиву вершин
	std::vector<int> V;
	std::vector<int> E;

	std::vector<int> A;
	std::vector<int> D;
	Graph();
	Graph(int V);
	Graph(int V, int reb);
};