#include <iostream>
#include <climits>
#include <stdlib.h>
using namespace std;
/*
*functional��find the max difference between two number
*/
int maxDifference(int num[], int N)
{
    if (N<2)
    {
        cout<<"you must input a array with more than two numbers!!"<<endl;
        return INT_MAX;
    }

    // �������е�Ԫ���������飬ÿ����ߵ�����С���ұߵ����ϴ�
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

    // ������Щ�������ҳ�һ��������
    int max=arr[1];
    for (int k=1;k<N;k+=2)
    {
        if (max<arr[k])
            max=arr[k];
    }
    // ������ЩС�����ҳ�һ����С����
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

    // ��ʼ�ҳ���������Ԫ�ص������
    const int Size=N;
    int diff[Size];
    for (int k=0;k<N;k++) diff[k]=0;
    for (int k=0;k<N;k++)
    {
        diff[k]=abs(num[k+1]-num[k]);
    }
    // �ҳ���Ĳ�ֵ
    int max=diff[0];
    for (int k=1;k<N-1;++k)
    {
        if (max < diff[k])
            max=diff[k];
    }
    return max;
}
