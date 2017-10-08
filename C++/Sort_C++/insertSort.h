#ifndef INSERTSORT_H_
#define INSERTSORT_H_

#include <iostream>
using namespace std;

template<typename T>
void insertSort(T arr[], int n)
{
    for (int i=1; i <n; ++i)
    {
        if (arr[i] < arr[i-1])
        {
            T tmp=arr[i];
            arr[i]=arr[i-1];
            int j=i-1;
            while (j>0 && arr[j-1] >= tmp)
            {
                arr[j]=arr[j-1];
                j--;
            }
            arr[j]=tmp;
        }
    }
}

template<typename T>
void insertSort(T arr[], int l, int r)/**< 对arr[l, r] 这个范围的元素进行插入排序 */
{
    for (int i=l+1; i <=r; ++i)
    {
        if (arr[i] < arr[i-1])
        {
            T tmp=arr[i];
            arr[i]=arr[i-1];
            int j=i-1;
            while (j>l && arr[j-1] > tmp)
            {
                arr[j]=arr[j-1];
                j--;
            }
            arr[j]=tmp;
        }
    }
}

#endif // INSERTSORT_H_

