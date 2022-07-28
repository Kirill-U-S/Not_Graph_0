#include <iostream>
#include <vector>

class Graph {
public:
	std::vector<int> V;
	std::vector<int> A;

	Graph(int V)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				int v = 0;
				A.push_back(v);
			}
		}
	};
};