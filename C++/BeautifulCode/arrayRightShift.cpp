// C++ source file
// 求一个数组循环移位后的结果
void reverse(int num[], int begin, int end)
{
    int cnt=0;
    while(end > begin)
    {
        cnt=num[begin];
        num[begin]=num[end];
        num[end]=cnt;
        begin++;
        end--;
    }
}

void arrayLeftShift(int arr[], int N, int K)
{
    // 对移位位数K做一些处理，使得程序可以处理K>N的情况
    K%=N;
    reverse(arr,0,K-1);
    reverse(arr,K,N-1);
    reverse(arr,0,N-1);
}

void arrayRightShift(int arr[], int N, int K)
{
    // 对移位位数K做一些处理，使得程序可以处理K>N的情况
    K%=N;
    reverse(arr,0,N-K-1);
    reverse(arr,N-K,N-1);
    reverse(arr,0,N-1);
}
