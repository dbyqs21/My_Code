#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 未完成
/** \brief 求出走出迷宫的最大步数（牛客网编程题）
 *
 * \param
 * \param
 * \return
 *
 */



bool compare(const pair<int,int> a, const pair<int,int> b)
{
    return a.first<b.first;
}


int dungeon()
{
    // read input
    int maxStep;
    int n,m,x0,y0,k;

     cin>>n>>m;
    vector<vector<char>> D;
    char c;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;++j)
        {
            cin>>c;
            D[i][j]=c;
        }
    }

    cin>>x0>>y0;
    cin>>k;

    vector<pair<int,int>> step;
    int dx,dy;
    for (int i=0;i<k;++i)
    {
        cin>>dx>>dy;
        step.push_back(make_pair(dx,dy));
    }

    // processing
    sort(step.begin(),step.end(),compare);
    int x,y;
    x=x0,y=y0;
    int cntStep=0;
    while (x!=n-1 || y !=m-1)
    {
        for (int i = 0;i<step.size();++i)
        {
            if (D[x+step[i].first][y+step[i].second] == '.')
            {
                cntStep++;
            }
        }
    }

}
