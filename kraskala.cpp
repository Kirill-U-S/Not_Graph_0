//должно быть 59
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

    int arr[N][N]{}, vershx[N]{}, vershy[N]{}, sum = 0;
    int min = INT_MAX;
    std::vector<int> minn;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (smezh[i][j] > 0) {
                min = smezh[i][j];
                minn.push_back(min);
            }
        }
    }
    sort(minn.begin(), minn.end());

    for (int z = 0; z < minn.size(); z++) {
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (minn[z] == smezh[i][j] && (vershx[i] == 0 || vershy[j] == 0) && (vershx[i] == 0 || vershx[j] == 0)) {
                    sum += minn[z];
                    std::cout << i << " - " << j << " Weight: " << minn[z] << ". Interim amount: " << sum << std::endl;
                    vershx[i] = 1;
                    vershy[j] = 1;
                }
            }
        }
    }

    return 0;
}
//(vershx[i] == 0 || vershy[j] == 0) && (vershx[i]==0 || vershx[j]==0))
//dfs
//bool mark[100]{};
//void DFS(int start)
//{
//    stack<int> s;  //создали стек с
//    s.push(start);  //добавили вершину старт
//    while (!s.empty()) //пока не пуст с
//    {
//        int v = s.top();  //вершина самая последняя в стеке
//        s.pop();          //удалили вершину в стеке, но все еще работаем с ее данными
//        for (int i = 0; i < N; ++i) //до количества элементов в строке
//        {
//            if (mark[smezh[v][i]] == 0)  // если в массиве элементов с метками нашего ребра нет, то идем в иф
//            {
//                s.push(smezh[v][i]);   //добавляем в с наше ребро
//                mark[smezh[v][i]] = 1;  //и метку делаем
//            }
//        }
//    }
//}