
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

/**< ����һ��ָ������ָ�룬���ҽ�����ָ����Ϊ�������ݸ�һ����������Ϊ�β� */

double f(double num)// �˴���f��Ϊһ��ָ����double f(double num)��ָ�롣
{
    return 2*num;
}

/**< ����һ�������β�Ϊ����ָ��ĺ��� */
double sum(double (*pFun)(double), int N, int M)
{
    double result=0;
    for (int k=N;k<M;++k)
    {
        result+=(*pFun)(k);
    }
    return result;
}
void test4()
{
    cout<<(*f)(8)<<endl; // �˴�Ϊ���ú���ָ�������ú���
    cout<<sum(f,3,6)<<endl;   // �˴�Ϊ���ݺ���������ָ�룬�ں����е��ú���ָ������������
}
