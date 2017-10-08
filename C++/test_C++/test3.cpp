#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
/**< 测试函数，一个数按位与上比它自己小一的数，实际上就是计算该数的二进制表示中的1的个数 */
int func(int x)
{
    int count=0;
    while (x)
    {
        count++;
        x=x&(x-1);//与运算
    }
    return count;
}

void test3()
{
    cout<<func(1024)<<endl;
}
