//регулярный ли граф(все вершины имеют одинаковую степень)
#include <iostream>
#include <cmath>
#include "Class_Graph.h"
#include "Algorithm.h"

void regular(Graph g) {
	const int N = sqrt(g.A.size());
	/*копирование изначального массива А*/
	int** smezh = new int* [N];
	int* degr = new int[N];
	for (int i = 0; i < N; i++)
		smezh[i] = new int[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			smezh[i][j] = g.A[i * N + j];
	int flag = 1;
	for (int i = 0; i < N; i++) {
		degr[i] = 0;
		for (int j = 0; j < N; j++)
			degr[i] += smezh[i][j]; //массив со степенями вершин
	}
	for (int k = 1; k < N; k++)
	{
		if (degr[k - 1] != degr[k])
		{
			flag = 0;
			break;
		}
	}
	if (flag)
		std::cout << "regular";
	else
		std::cout << "unregular";
}
