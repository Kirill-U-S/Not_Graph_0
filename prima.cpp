#include <iostream>
int main() {
    const int N = 10;
    int smezh[N][N] =
    {
        {0,10,0,0,20,0,0,15,0,0},
        {10,0,5,0,0,0,0,2,8,9},
        {0,5,0,16,0,0,0,0,4,0},
        {0,0,16,0,28,25,0,0,11,9},
        {20,0,0,28,0,15,0,0,0,0},
        {0,0,0,25,15,0,10,0,7,5},
        {0,0,0,0,0,10,0,11,0,3},
        {15,2,0,0,0,0,11,0,4,14},
        {0,8,4,11,0,7,0,4,0,0},
        {0,9,0,9,0,5,3,14,0,0}
    };

    int arr[N][N]{}, versh[N] = { 1 }, y = 0, x = 0, sum = 0, k = 0;

    while (k++ < N - 1)
    {
        int minn = INT_MAX;
        for (int i = 0; i < N; i++)
            if (!versh[i])
                arr[x][i] = smezh[x][i]; //присваивание строки

        arr[y][x] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((arr[i][j] < minn) && arr[i][j] && !versh[j]) {
                    minn = arr[i][j];
                    y = i; // last
                    x = j; // найденная вершина
                }
            }
        }
        versh[x] = arr[y][x];
        sum += versh[x];
        std::cout << "Step " << k << ": edge " << y << " - " << x << ", weight " << versh[x] << ". sum: " << sum << std::endl;
    }
    return 0;
}
