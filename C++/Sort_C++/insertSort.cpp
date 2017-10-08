#include <iostream>
using namespace std;

/**< 直接插入排序 */

void insertSort(int arr[], int N)
{
    if (!arr || N<2)
    {
        return;
    }
    else
    {
        for (int i=1;i<N;++i)  // 控制次数
        {
            if(arr[i]<arr[i-1])
            {
                int j=i-1;
                auto tmp=arr[i];
                arr[i]=arr[i-1];
                while(j>=0 && arr[j]>tmp)
                {
                    arr[j+1]=arr[j];
                    j--;
                }
                j<0?arr[0]=tmp:arr[j]=tmp;
            }
        }
    }

}
