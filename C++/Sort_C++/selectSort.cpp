#include <iostream>
#include <utility>
//#include <algorithm>
using namespace std;

template<typename T>
void selectSort(T  arr[], int n)
{
    for (int i=0; i < n; ++i)
    {
        // 从未排序的序列中寻找出一个最小或者最大的元素，并与当前序列元素交换
        int index_min=i;
        for (int j=i+1; j<n; ++j)
        {
            if (arr[j] < arr[index_min])
            {
                index_min = j;
            }
        }
        swap(arr[i], arr[index_min]);
    }
}


void selectSort(int arr[], int n)
{
    for (int i=0; i < n; ++i)
    {
        // 从未排序的序列中寻找出一个最小或者最大的元素，并与当前序列元素交换
        int index_min=i;
        for (int j=i+1; j<n; ++j)
        {
            if (arr[j] < arr[index_min])
            {
                index_min = j;
            }
        }
        swap(arr[i], arr[index_min]);
    }
}

