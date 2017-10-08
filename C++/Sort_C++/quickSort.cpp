#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

#define CUTOFF 5

void insertSort(int arr[], int N);

int median3(int arr[], int left, int right)
{
    int middle=(left+right)/2;
    if(arr[left] > arr[middle])
    {
        swap<int>(arr[left],arr[middle]);
    }
    if (arr[left] > arr[right])
    {
        swap<int>(arr[left], arr[middle]);
    }
    if (arr[middle] > arr[right])
    {
        swap<int>(arr[middle], arr[right]);
    }
    swap<int>(arr[middle], arr[right-1]);
    return right-1;
}

void quickSort(int arr[], int left, int right)
{
    if (right > left )   // 若待排序的规模在UTOFF所定义的值之下，则采用插入排序
    {
        int pivot = arr[median3(arr, left, right)];
        int i=left, j=right;
        while (true)
        {
            while (arr[++i] < pivot);
            while (arr[--j] > pivot);
            if (i<j)
            {
                swap<int>(arr[i], arr[j]);
            }
            else
            {
                break;
            }
        }
        swap<int>(arr[i], arr[right-1]);

        // 递归处理剩余的小规模的问题
        quickSort(arr,left,i-1);
        quickSort(arr, i+1, right);
    }
}

void quickSort2(int arr[], int left, int right)
{
    if(right > left)
    {
        int pivot = arr[left];
        int i=left, j=right;
        while (i<j)
        {
            while (i<j && arr[j] >= pivot) j--;
            arr[i]=arr[j];
            while (i<j && arr[i] <= pivot) i++;
            arr[j]=arr[i];
        }
        arr[i]=pivot;
        // 递归处理剩余的小规模的问题
        quickSort2(arr,left,i-1);
        quickSort2(arr, i+1, right);
    }
}
