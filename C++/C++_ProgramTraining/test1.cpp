#include <stdio.h>
#include <iostream>
#include <vector>
#include <array>
#include <utility>
using namespace std;

//给定一个 n 行 m 列的地牢，其中 '.' 表示可以通行的位置，'X' 表示不可通行的障碍，牛牛从 (x0 , y0 ) 位置出发，遍历这个地牢，和一般的游戏所不同的是，他每一步只能按照一些指定的步长遍历地牢，要求每一步都不可以超过地牢的边界，也不能到达障碍上。地牢的出口可能在任意某个可以通行的位置上。牛牛想知道最坏情况下，他需要多少步才可以离开这个地牢。
//每个输入包含 1 个测试用例。每个测试用例的第一行包含两个整数 n 和 m（1 <= n, m <= 50），表示地牢的长和宽。接下来的 n 行，每行 m 个字符，描述地牢，地牢将至少包含两个 '.'。接下来的一行，包含两个整数 x0, y0，表示牛牛的出发位置（0 <= x0 < n, 0 <= y0 < m，左上角的坐标为 （0, 0），出发位置一定是 '.'）。之后的一行包含一个整数 k（0 < k <= 50）表示牛牛合法的步长数，接下来的 k 行，每行两个整数 dx, dy 表示每次可选择移动的行和列步长（-50 <= dx, dy <= 50）

//void maxSteps()
//{
//    /**< 读取地图的尺寸 */
//    int n,m;
//    cin>>n>>m;
//
//    array<char> Map[n][m];
//
//    /**< 读取输入的地图 */
//    for (int i=0; i<n; ++i)
//    {
//        for (int j=0; j<m++j)
//        {
//            cin>>Map[i][j];
//        }
//    }
//
//    /**< 读取牛牛出发的位置 */
//    pair<int,int> begin_position;
//    cin>>begin_position.first>>begin_position.second;
//
//    /**< 读取牛牛的合法步长 */
//    int step;
//    cin>>step;
//
//    pair<int, int> steps[step];/**< 表示每次可选择移动的行和列步长 */
//    for (int i=o;i<step;++i)
//    {
//        cin>>steps.first>>steps.second;
//    }
//
//    //*****************开始处理************************
//    int cnt=0;
//    for (int i=1;i<=step;++i)
//    {
//        for (int j=0;j<step;++j) // 扫描可走的每一步
//        {
//            if (Map[begin_position+steps[j].first][begin_position+steps[j].second] == '.')
//            {
//                break;
//            }
//        }
//    }
//
//}
