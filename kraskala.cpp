#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
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

    int arr[N][N]{}, versh[N], y = 0, x = 0, sum = 0, k = 0;
    int min = INT_MAX;
    std::vector<int> minn;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (min > smezh[i][j] && smezh[i][j]) {
                min = smezh[i][j];
                minn.push_back(min);
            }
        }
    }
    sort(minn.begin(), minn.end());
    //
    for (int z = 0; z < N; z++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < minn.size(); j++) {
                if (minn[z] == smezh[i][j]) {
                    std::cout << x << " - " << y << " Weight: " << minn[z] << std::endl;
                    x = i;
                    y = j;
                    versh[i] = minn[z];

                }


            }

        }
    }

    return 0;
}
