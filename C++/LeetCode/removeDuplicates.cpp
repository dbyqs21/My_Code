#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/** \brief 删除数组中的重复元素
 *
 * \param  int A[] 数组的地址
 * \param  int N 数组中元素的个数
 * \return int 删除重复元素后的数组中的元素的个数
 *
 */

int removeDuplicates(int A[], int N)
{
    set<int> a;
    for (int i=0;i<N;++i)
    {
        a.insert(A[i]);
    }
    return a.size();
}

int removeDuplicates2(int A[], int N)
{
    vector<int > b;
    for (int i=0;i<N;++i)
    {
        b.push_back(A[i]);
    }
    sort(b.begin(),b.end());
    auto itor = unique(b.begin(),b.end());   // unique函数，是删除相邻的重复元素，所以使用之前一般需要排序

    return itor-b.begin();
}

void test2()
{
    int A[]={1,1,2};
    int N = sizeof(A)/sizeof(A[0]);
    cout<<removeDuplicates(A,N)<<endl;
}
