#include <iostream>
#include <vector>
#include "Class_Graph.h"

Graph::Graph(/*�����-�� ��������*/) {
	//���������� ������������ �������
}

/*������� ����� ������� �������������*/
Graph::Graph(int V) {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
		{
			int v = 0;
			std::cin >> v;
			A.push_back(v);
		}
	}
}

///*������� ����� <V, E>*/
//Graph(double sv/*�����-�� ��������*/) {
//	//�����-�� ����������
//}
