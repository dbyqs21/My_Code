#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
using namespace std;

int searchInRotatedSortedArray(int arr[], int N, int key)
{
    vector<int> s;
    for (int i=0; i<N; ++i)
    {
        s.push_back(arr[i]);
    }

    auto itor = find(s.begin(),s.end(),key);
    return itor != s.end()?distance(s.begin(),itor):-1;

}

int searchInRotatedSortedArray1(int A[], int n, int target)
{
    int first = 0, last = n;
    while (first != last)
    {
        const int mid = (first + last) / 2;
        if (A[mid] == target)
            return mid;
        if (A[first] <= A[mid])
        {
            if (A[first] <= target && target < A[mid])
                last = mid;
            else
                first = mid + 1;
        }
        else
        {
            if (A[mid] < target && target <= A[last-1])
                first = mid + 1;
            else
                last = mid;
        }
    }
    return -1;
}

void test3()
{
    int a[]={5,4,3,2,1,0,7,8,9};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<"从旋转的有序数组中找到的元素的索引为： "<<searchInRotatedSortedArray(a,n,3)<<endl;
}
