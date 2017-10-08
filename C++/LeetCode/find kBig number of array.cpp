
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;
void partition(vector<int> &v, vector<int> &Sa, vector<int> &Sb);

/**< 寻找K个最大的数 */
vector<int> kBig(vector<int> arr, int k)
{
    vector<int> b;
    if (k <= 0) return b;
    if (arr.size() <= k) return arr;

    vector<int> Sa;
    vector<int> Sb;
    partition(arr, Sa, Sb);
    auto cnt=kBig(Sa,k);
    auto cnt2=kBig(Sb,k-Sa.size());
    for (auto i: cnt2)
        cnt.push_back(i);
    return cnt;
}

void partition(vector<int> &v, vector<int> &Sa, vector<int> &Sb)
{
    swap(v[0],v[rand()%v.size()]);
    auto p = v[0];
    for (int i = 1;i<v.size();++i)
    {
        v[i]>p?Sa.push_back(v[i]):Sb.push_back(v[i]);
    }
    Sa.size()<Sb.size()?Sa.push_back(p):Sb.push_back(p);
}

void test5()
{
    vector<int> v={1,2,3,4,5,6,7};
    auto result = kBig(v, 3);
    for (auto k :result)
    {
        cout<<k<<" ";
    }
    cout<<endl;
}

