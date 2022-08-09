#include "Libraries.h"


int main(int argc, char* argv[])
{
    int razmer = 0;
    std::cin >> razmer;
    Graph g = Graph(razmer);

    for (int i = 0; i < razmer; i++) {
        for (int j = 0; j < razmer; j++)
            std::cout<<g.A[i * razmer + j]<<" ";
        std::cout << "\n";
    }

    deg(g);

    return EXIT_SUCCESS;
}