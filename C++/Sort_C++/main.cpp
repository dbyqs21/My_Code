#include <iostream>
#include "SortTestHelper.h"
#include "selectSort.h"
#include "insertSort.h"
#include "bubbleSort.h"
#include "mergeSort.h"
#include <algorithm>
#include "quickSort.h"
#include "heapSort.h"
using namespace std;


//void quickSort(int arr[], int left, int right);
//void quickSort2(int arr[], int left, int right);
void selectSort(int arr[], int n);

int main()
{
    int n=10000;
    int * arr=SortTestHelper::generateRandomArray(n,0,n);
    int * arr2 =SortTestHelper::copyIntArray(arr, n);
    int  * arr3 = SortTestHelper::copyIntArray(arr, n);
    int  * arr4 = SortTestHelper::copyIntArray(arr, n);
    int  * arr5 = SortTestHelper::copyIntArray(arr, n);

//    int A[]={3,2,4,1,7,4,9,5};
//    insertSort(arr,0,n-1);
//    SortTestHelper::showSortedArray(arr, n);
//    cout<<SortTestHelper::isSorted(arr, n)<<endl;

    SortTestHelper::testSort("selectSort",selectSort,arr,n);
    SortTestHelper::testSort("insertSort",insertSort,arr2,n);
    SortTestHelper::testSort("quickSort",quickSort2,arr3,n);
    SortTestHelper::testSort("mergeSort",mergeSort,arr4,n);
    SortTestHelper::testSort("heapSort",heapsort,arr5,n);

    //SortTestHelper::showSortedArray(arr, n);
    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    return 0;
}
