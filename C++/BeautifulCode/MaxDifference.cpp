#include <iostream>
#include <climits>
#include <stdlib.h>
using namespace std;
/*
*functional：find the max difference between two number
*/
int maxDifference(int num[], int N)
{
    if (N<2)
    {
        cout<<"you must input a array with more than two numbers!!"<<endl;
        return INT_MAX;
    }

    // 将数组中的元素两两分组，每组左边的数较小，右边的数较大
    const int Size=N;
    int arr[Size];
    for (int k=0;k<N;k++) arr[k]=0;
    for (int k=0;k<N;k+=2)
    {
        if (num[k]>num[k+1])
        {
            arr[k]=num[k+1];
            arr[k+1]=num[k];
        }
        else
            arr[k]=num[k];
    }

    // 遍历这些大数，找出一个最大的数
    int max=arr[1];
    for (int k=1;k<N;k+=2)
    {
        if (max<arr[k])
            max=arr[k];
    }
    // 遍历这些小数，找出一个最小的数
    int min=arr[0];
    for (int k=1;k<N;k+=2)
    {
        if (min>arr[k])
            min=arr[k];
    }
    return max-min;

}

int maxBehindDiffer(int num[], int N)
{
    if (N<2)
    {
        cout<<"you must input an array with numbers more than two!!"<<endl;
        return INT_MAX;
    }

    // 开始找出两个相邻元素的最大间距
    const int Size=N;
    int diff[Size];
    for (int k=0;k<N;k++) diff[k]=0;
    for (int k=0;k<N;k++)
    {
        diff[k]=abs(num[k+1]-num[k]);
    }
    // 找出最的差值
    int max=diff[0];
    for (int k=1;k<N-1;++k)
    {
        if (max < diff[k])
            max=diff[k];
    }
    return max;
}
