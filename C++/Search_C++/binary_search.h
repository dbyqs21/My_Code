#ifndef BINARY_SEARCH_H_
#define BINARY_SEARCH_H_

#include <iostream>
#include <algorithm>
using namespace std;


/**< f�ǵݹ�汾�Ķ��ֲ��� */
template<typename T>
int binary_search(T arr[], int n, T target)
{
    // ��arr[l,r]��Ѱ��target
    int l=0;
    int r=n-1;
    while (l<=r)
    {
        // int mid = (l+r)/2; // ��bug��l+r���ܻ����
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
    // ��ѭ����˵��û���ҵ�target
    return -1;
}

/**< �ݹ�汾�Ķ��ֲ��� */
template<typename T>
int binary_search(T arr[], int l, int r, T target)
{
    int index=-1;
    // ��arr[l,r]��Ѱ��target
    if (l<=r)
    {
        // int mid = (l+r)/2; // ��bug��l+r���ܻ����
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
    // ��ѭ����˵��û���ҵ�target
    return index;
}


#endif // BINARY_SEARCH_H_
