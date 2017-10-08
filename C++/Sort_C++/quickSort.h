#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <iostream>
#include <vector>
using namespace std;

/**< 使得arr[l, p-1]<arr[p],arr[p+1, r]>arr[p] */
template <typename T>
int __partition(T arr[], int l, int r)
{
    swap(arr[l], arr[rand()%(r-l+1)+l]);  // 随机选择主元
    int p = l;
    int j = l;
    for (int i =l+1; i<=r; ++i)
    {
        if (arr[i] < arr[p])
        {
            swap(arr[i], arr[++j]);
        }
    }
    swap(arr[p],arr[j]);
    return j;
}

/**< 对arr[l, r] 这样的数组进行快速排序 */
template <typename T>
void __quickSort(T arr[],int l, int r)
{
//    if(l >= r)
//    {
//        return;
//    }

    if(r-l <= 15)
    {
        insertSort(arr, l, r);
        return;
    }

    int p = __partition(arr, l, r);
    __quickSort(arr,l,p-1);
    __quickSort(arr,p+1,r);
}


template <typename T>
void quickSort(T arr[], int n)
{
    srand(time(nullptr));
    __quickSort(arr,0,n-1);
}




/**< 使得arr[l, p-1]<arr[p],arr[p+1, r]>arr[p] */
template <typename T>
int __partition2(T arr[], int l, int r)
{
    swap(arr[l], arr[rand()%(r-l+1)+l]);  // 随机选择主元
    int p = l; // 主元所对应的索引

    /**< arr[l+1,i)<=arr[p],arr(j,r]>arr[p] */
    int i=l+1, j=r;
    while (true)
    {
        while (i <= r && arr[i] < arr[p])
        {
            ++i;
        }
        while (j >= l+1 && arr[j] > arr[p])
        {
            --j;
        }
        if(i > j)
        {
            break;
        }
        //cout<<"i= "<<i<<"j= "<<j<<endl;

        swap(arr[i] , arr[j]);
        i++;
        j--;
    }
    swap(arr[p], arr[j]);
    return j;
}
/**< 对arr[l, r] 这样的数组进行快速排序 */
template <typename T>
void __quickSort2(T arr[],int l, int r)
{
//    if(l >= r)
//    {
//        return;
//    }

    if(r-l <= 15)
    {
        insertSort(arr, l, r);
        return;
    }

    int p = __partition2(arr, l, r);
    __quickSort2(arr,l,p-1);
    __quickSort2(arr,p+1,r);
}

template <typename T>
void quickSort2(T arr[], int n)
{
    srand(time(nullptr));
    __quickSort2(arr,0,n-1);
}

#endif // QUICKSORT_H_
