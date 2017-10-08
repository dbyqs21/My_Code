// C++ source file

// ����һ�����飬�����������е����������

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
    int * MaxV=new int[N];    // ��¼�����еĵ���������Ϣ

    MaxV[1]=arr[0];
    MaxV[0]=min(arr,N)-1;   // �����е���Сֵ��Ҳ�Ǳ߽�ֵ
    int * LIS=new int[N];

    //  ��ʼ����������е���Ϣ
    for(int k=0;k<N;++k)
    {
        LIS[k]=1;
    }

    int nMaxLIS=1;

    for (int k=1;k<N;++k)
    {
        // ������ʷ�������������Ϣ
        int j;
        for (j=nMaxLIS;j>=0;++j)
        {
            if (arr[k] > MaxV[j])
            {
                LIS[k]=j+1;
                break;
            }
        }
        // �����ǰ���еĳ��ȴ�����������еĳ��ȣ��������Ϣ
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
