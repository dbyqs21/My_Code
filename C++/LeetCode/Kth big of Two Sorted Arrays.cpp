#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

/**< 给定两个已经排序好的数组，找到两者所有元素中第 k 大的元素。 */
int kBig_of_two_array(vector<int> & A, vector<int> & B, int k)
{
    // 假设A的元素数量小于B的元素数量
    if(A.size() > B.size()) return kBig_of_two_array(B,A,k);
    if(A.size() == 0) return B[k-1];
    if(k == 1) return min<int>(A[0], B[0]);

    int pa=min<int>(k/2, A.size());
    int pb=k-pa;
    if(A[pa-1] < B[pb-1])
    {
        A.erase(A.begin(),A.begin()+pa);
        return kBig_of_two_array(A,B,k-pa);
    }
    else if (A[pa-1] > B[pb-1])
    {
        B.erase(B.begin(),B.begin()+pb);
        return kBig_of_two_array(A, B, k-pb);
    }
    else
    {
        return A[pa-1];
    }
}


void test4()
{
    vector<int> v={1,2,3,4,5,6,7};
    vector<int> v1={4,6,12,32,45,65,70};
    cout<<kBig_of_two_array(v,v1, 5);
    cout<<endl;
}

