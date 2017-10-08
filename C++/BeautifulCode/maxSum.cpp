#include <iostream>
#include <climits>
using namespace std;

int maxSum1(int arr[], int N)
{
    const int arrSize=N;
    int nStart=arr[N-1];
    int nAll=arr[N-1];

    for (int k=N-2;k>=0;--k)
    {
        if (nStart < 0)
            nStart=0;
        nStart+=arr[k];
        if (nStart>nAll)
            nAll=nStart;
    }
    return nAll;
}


int maxSum(int arr[], int N)
{
    int maxSum=INT_MIN;
    int sum=0;
    for (int k=0;k<N;++k)
    {
        sum=0;
        for (int k1=k;k1<N;++k1)
        {
            sum+=arr[k1];
            if (sum>maxSum)
                maxSum=sum;
        }
    }
    return maxSum;
}
