//#include <iostream>
/*
int main()
{
    const int N = 4;
    int smezh[N][N] =
    {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };
    int arr[N][N]{}, versh[N] = { 1 }, y = 0, x = 0, sum = 0, k = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (smezh[i][j] && !arr[i][j])
            {
                arr[i][j] = 1;
                x = i;
                y = j;
                for (int z = y + 1; z < N; z++)
                {
                    if (smezh[y][z])
                    {
                        arr[y][z] = arr[z][y] = 1;
                        std::cout << x << " - " << y << " - " << z << " - " << x << std::endl;
                    }

                }
            }
        }
    }
}

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

}*/