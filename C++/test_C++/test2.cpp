#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

/**< ���ö�ٱ�����ֵ */
void test2()
{
        enum string
    {
        x1,
        x2,
        x3=10,
        x4,
        x5,
    } x;
    cout<<x<<endl;

    char str[]="Hello";
    cout<<sizeof(str)<<endl;
}
