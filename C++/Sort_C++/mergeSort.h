#ifndef MERGESORT_H_
#define MERGESORT_H_

#include "insertSort.h"
#include <iostream>
using namespace std;

/**< ��arr[l,mid]��arr[mid+1,r]���������������й鲢 */
template<typename T>
void __merge(T arr[], int l, int mid, int r)
{
    /**< ��������ʼ���鲢��������� */
    T aux[r-l+1];
    for (int i=l; i<=r; ++i)
    {
        aux[i-l]=arr[i];
    }

    /**< �鲢 */
    int i=l;
    int j=mid+1;
    for (int k=l; k<=r; ++k)
    {
        if (i > mid) /**< �ж��Ƿ�Խ�� */
        {
            arr[k] = aux[j-l];
            j++;
        }
        else if (j > r) /**< �ж��Ƿ�Խ�� */
        {
            arr[k] = aux[i-l];
            i++;
        }
        else /**< ��ʼ�鲢���� */
        {
            if(aux[i-l] < aux[j-l])
            {
                arr[k] = aux[i-l];
                i++;
            }
            else
            {
                arr[k] = aux[j-l];
                j++;
            }
        }


    }
}

template<typename T>
void __mergeSort(T arr[], int l, int r) /**< �Զ����µĹ鲢 */
{
//    if(l >= r)
//    {
//        return ;
//    }

    if(r-l <= 15)
    {
        insertSort(arr,l,r);
        return ;
    }

    int mid = (l+r)/2;//(l&r)+((l^r)>>1);
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);
    if (arr[mid] > arr[mid+1]);
    {
        __merge(arr,l,mid,r);
    }
}


template<typename T>
void mergeSort(T arr[], int n)
{
    __mergeSort(arr, 0, n-1);
}

template<typename T>
void mergeSortBU(T arr[], int n) /**< �Ե����ϵ������㷨 */
{
    for (int sz=1; sz<=n; sz+=sz)
    {
        for (int i=0; i+sz<n; i+=(sz+sz))
        {
            __merge(arr,i,i+sz-1,min(i+sz+sz-1,n-1));
        }
    }
}



#endif // MERGESORT_H_
