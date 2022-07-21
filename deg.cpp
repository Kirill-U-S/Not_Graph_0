#include <iostream>

int main()
{
    const int N = 6;
    int smezh[N][N] =
    {
        {0,1,1,0,0,1},
        {1,0,1,1,1,0},
        {1,1,0,0,0,0},
        {0,1,0,0,0,1},
        {0,1,0,0,0,1},
        {1,0,0,1,1,0}
    };
    int deg[N], max = 0, min = N, Sum = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < N; j++)
            sum += smezh[i][j];
        deg[i] = sum;
        if (deg[i] > max)
            max = deg[i];
        if (deg[i] < min)
            min = deg[i];
        Sum += deg[i];
    }
    std::cout << "max deg: " << max << "\nmin deg: " << min << "\nsred deg: " << (double)Sum / N << std::endl;
    return 0;
}