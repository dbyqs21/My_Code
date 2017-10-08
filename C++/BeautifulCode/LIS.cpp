// C++ source file

// 给定一个数组，求出这个数组中的最长递增序列

#include <iostream>
using namespace std;

int min(int num[], int N)
{
    int min=num[0];
    for (int k=0; k<N; ++k)
    {
        if (min>num[k])
            min=num[k];
    }
    return min;
}


int LIS(int arr[],int N)
{
    int * MaxV=new int[N];    // 记录数组中的递增序列信息

    MaxV[1]=arr[0];
    MaxV[0]=min(arr,N)-1;   // 数组中的最小值，也是边界值
    int * LIS=new int[N];

    //  初始化最长递增序列的信息
    for(int k=0;k<N;++k)
    {
        LIS[k]=1;
    }

    int nMaxLIS=1;

    for (int k=1;k<N;++k)
    {
        // 遍历历史上最长递增序列信息
        int j;
        for (j=nMaxLIS;j>=0;++j)
        {
            if (arr[k] > MaxV[j])
            {
                LIS[k]=j+1;
                break;
            }
        }
        // 如果当前序列的长度大于最长递增序列的长度，更新最长信息
        if (LIS[k] > nMaxLIS)
        {
            nMaxLIS=LIS[k];
            MaxV[LIS[k]]=arr[k];
        }
        else if (MaxV[j] < arr[k] && arr[k] < MaxV[j+1])
        {
            MaxV[j+1]=arr[k];
        }
    }
    return nMaxLIS;
}
