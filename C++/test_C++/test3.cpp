#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
/**< ���Ժ�����һ������λ���ϱ����Լ�Сһ������ʵ���Ͼ��Ǽ�������Ķ����Ʊ�ʾ�е�1�ĸ��� */
int func(int x)
{
    int count=0;
    while (x)
    {
        count++;
        x=x&(x-1);//������
    }
    return count;
}

void test3()
{
    cout<<func(1024)<<endl;
}
