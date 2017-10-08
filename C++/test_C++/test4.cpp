
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

/**< 定义一个指向函数的指针，并且将函数指针作为参数传递给一个函数，作为形参 */

double f(double num)// 此处的f就为一个指向函数double f(double num)的指针。
{
    return 2*num;
}

/**< 定义一个函数形参为函数指针的函数 */
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
    cout<<(*f)(8)<<endl; // 此处为利用函数指针来调用函数
    cout<<sum(f,3,6)<<endl;   // 此处为传递函数给函数指针，在函数中调用函数指针来计算结果。
}
