// C++ source file
// ��һ������ѭ����λ��Ľ��
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
    // ����λλ��K��һЩ����ʹ�ó�����Դ���K>N�����
    K%=N;
    reverse(arr,0,K-1);
    reverse(arr,K,N-1);
    reverse(arr,0,N-1);
}

void arrayRightShift(int arr[], int N, int K)
{
    // ����λλ��K��һЩ����ʹ�ó�����Դ���K>N�����
    K%=N;
    reverse(arr,0,N-K-1);
    reverse(arr,N-K,N-1);
    reverse(arr,0,N-1);
}
