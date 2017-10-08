#ifndef SORTTESTHELPER_H_
#define SORTTESTHELPER_H_

#include <ctime>
#include <random>
#include <cassert>

using namespace std;
namespace SortTestHelper
{
    int* generateRandomArray(int n, int rangeL, int rangeR)
    {
        assert(rangeL <= rangeR);
        int * arr = new int[n];
        srand(time(NULL));
        for (int i=0; i<n; ++i)
        {
            arr[i] = rand() % (rangeR- rangeL +1) + rangeL;
        }
        return arr;
    }

    int* genertNearlyOrderArray(int n, int swaptimes)
    {
        int * arr = new int[n];
        for (int i=0; i<n ;++i)
        {
            arr[i]=i;
        }

        srand(time(nullptr));

        for (int i=0;i<swaptimes;++i)
        {
            int xPos = rand()%n;
            int yPos = rand()%n;
            swap(arr[xPos],arr[yPos]);
        }
    }

    int* copyIntArray(int arr[], int n)
    {
        int * arr2 = new int[n];
        for (int i=0; i<n; i++)
        {
            arr2[i]=arr[i];
        }
        return arr2;
    }

    void showSortedArray(auto arr[], int N)
    {
        for (int i=0; i<N; ++i)
        {
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }

    template<typename T>
    bool isSorted(T arr[], int n)
    {
        for (int i=0; i<n-1; ++i)
        {
            if (arr[i] >arr[i+1])
                return false;
        }
        return true;
    }

    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int) ,T arr[], int n)
    {
        clockid_t start_time  = clock();
        sort(arr, n);
        clockid_t end_time = clock();
        assert(isSorted(arr, n));
        cout<<sortName<<" : "<<double(end_time - start_time)/CLOCKS_PER_SEC<<" s"<<endl;
        return ;
    }
}
#endif // SORTTESTHELP_H_
