#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

/**< ������������new��������ķ�ʽ���������е�Ԫ���Ƿ��ʼ�� */
void test1()
{
    int *p1 = new int[10];
    int *p2 = new int[10]();
    for (int k=0; k<10; ++k)
    {
        cout<<"p1:"<<p1[k]<<endl;
    }

    for (int k=0; k<10; ++k)
    {
        cout<<"p2:"<<p2[k]<<endl;
    }
}

