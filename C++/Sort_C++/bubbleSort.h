#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_

#include <iostream>
using namespace std;

template<typename T>
void bubbleSort(T arr[], int n)
{
    for (int i = 0 ; i < n; ++i)  //¿ØÖÆ´ÎÊý
    {
        bool flag=false;
        for (int j =n-1; j > i; --j)
        {
            if(arr[j-1] > arr[j])
            {
                swap(arr[j-1], arr[j]);
                flag=true;
            }
        }

        if(!flag)
        {
            break;
        }
    }
}

#endif // BUBBLESORT_H_
