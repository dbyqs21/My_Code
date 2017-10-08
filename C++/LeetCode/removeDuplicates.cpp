#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/** \brief ɾ�������е��ظ�Ԫ��
 *
 * \param  int A[] ����ĵ�ַ
 * \param  int N ������Ԫ�صĸ���
 * \return int ɾ���ظ�Ԫ�غ�������е�Ԫ�صĸ���
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
    auto itor = unique(b.begin(),b.end());   // unique��������ɾ�����ڵ��ظ�Ԫ�أ�����ʹ��֮ǰһ����Ҫ����

    return itor-b.begin();
}

void test2()
{
    int A[]={1,1,2};
    int N = sizeof(A)/sizeof(A[0]);
    cout<<removeDuplicates(A,N)<<endl;
}
