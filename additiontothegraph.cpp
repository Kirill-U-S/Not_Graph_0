//#include <iostream>
//
//int main()
//{
//    const int N = 6;
//    int smezh[N][N] =
//    {
//        {0,1,1,0,0,1},
//        {1,0,1,1,1,0},
//        {1,1,0,0,0,0},
//        {0,1,0,0,0,1},
//        {0,1,0,0,0,1},
//        {1,0,0,1,1,0}
//    };
//    int dop[N][N];
//    for (int i = 0; i < N; i++)
//    {
//        for (int j = 0; j < N; j++)
//        {
//            if (smezh[i][j] == 0)
//                dop[i][j] = 1;
//            else
//                dop[i][j] = 0;
//            dop[i][i] = 0;
//            std::cout << dop[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//}
//const int N = 6;
//
//void dop(int smezh[5][5], const int N)
//{
//    int dop[N][N];
//    for (int i = 0; i < N; i++)
//    {
//        for (int j = 0; j < N; j++)
//        {
//            if (smezh[i][j] == 0)
//                dop[i][j] = 1;
//            else
//                dop[i][j] = 0;
//            dop[i][i] = 0;
//            std::cout << dop[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//}