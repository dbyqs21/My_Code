#ifndef BINARY_SEARCH_H_
#define BINARY_SEARCH_H_

#include <iostream>
#include <algorithm>
using namespace std;


/**< f非递归版本的二分查找 */
template<typename T>
int binary_search(T arr[], int n, T target)
{
    // 在arr[l,r]中寻找target
    int l=0;
    int r=n-1;
    while (l<=r)
    {
        // int mid = (l+r)/2; // 有bug，l+r可能会溢出
        int mid = l+(r-l)/2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (target < arr[mid])
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    // 出循环，说明没有找到target
    return -1;
}

/**< 递归版本的二分查找 */
template<typename T>
int binary_search(T arr[], int l, int r, T target)
{
    int index=-1;
    // 在arr[l,r]中寻找target
    if (l<=r)
    {
        // int mid = (l+r)/2; // 有bug，l+r可能会溢出
        int mid = l+(r-l)/2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (target < arr[mid])
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }

        index = binary_search(T arr[], int l, int r, T target);
    }
    // 出循环，说明没有找到target
    return index;
}


#endif // BINARY_SEARCH_H_
