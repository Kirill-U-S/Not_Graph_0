#include "SDL.h"
#include <iostream>
#include "Class_Graph.h"

int main(int argc, char* argv[])
{
    Graph g = Graph();
    for (int i = 0; i < 5; i++)
        std::cout << g.A[i]<<"\n";

    return EXIT_SUCCESS;
}