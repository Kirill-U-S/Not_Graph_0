#include <iostream>
#include <vector>
#include "Class_Graph.h"

Graph::Graph(/*какие-то свойства*/)
{
	//реализация графического задания
}

/*задание через матрицу инцидентности*/
Graph::Graph(int V)
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			int v = 0;
			std::cin >> v;
			A.push_back(v);
		}
	}
}

/*задание через <V, E>*/
Graph::Graph(int V, int reb)
{
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < reb; j++)
		{
			int w = 0;
			std::cin >> w;
			D.push_back(w);
		}
	}

	for (int j = 0; j < reb; j++)
	{
		int p = 0;
		int znach = 0;
		for (int i = 0; i < V; i++)
		{
			if (D[i * V + j] != 0)
			{
				p++;
				znach = D[i * V + j];
			}
		}
		if (p == 2)
			E.push_back(znach);
		else if (p > 0 && p != 2)
			std::cout << "ERROR: задание через <V, E>, ошибка в массиве\n";
	}
	//какая-то реализация
}
