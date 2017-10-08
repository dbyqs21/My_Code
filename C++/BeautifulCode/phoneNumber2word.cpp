// C++ source code
#include <stdio.h>
#include <stdlib.h>

#define TelLength 7

/** \brief 找出手机上数字键盘上的号码对应的单词。采用一般的循环的方法来实现
 *
 * \param
 * \param
 * \return
 *
 */

void printWords()
{
    /**< 定义存储按键上字母的数组 */
    char c[10][10] = {
    "",                 //0
    "",                 //1
    "ABC",              //2
    "DEF",              //3
    "GHI",              //4
    "JKL",              //5
    "MNO",              //6
    "PQRS",             //7
    "TUV",              //8
    "WXYZ"              //9
    };

    /**< 将各个按键所能代表的字母个数存储在数组中 */
    int totalNum[10]={0,0,3,3,3,3,3,4,3,4};

    int number[TelLength];  /**< 存储电话号码 */
    char answer[TelLength]={0}; /**< 存储找到的单词答案 */

    /**< 获得电话号码的输入 */
    printf("请输入%d位电话号码：\n",TelLength);
    for (int k=0;k<TelLength;++k)
    {
        printf("请输入第%d位号码：",k+1);
        scanf("%d",&number[k]);
        printf("\n");
    }

    while(true)
    {
        // TelLength 为电话号码的长度
        for (int i=0;i<TelLength;++i)
        {
            printf("%c",c[number[i]][answer[i]]);
        }
        printf("\n");

        int k=TelLength-1;
        while(k>=0)
        {
            if (answer[k] < totalNum[number[k]]-1)
            {
                answer[k]++;
                break;
            }
            else
            {
                answer[k]=0;
                k--;
            }
        }

        if (k < 0)
            break;
    }

    /**< 输出结果 */
    for (int k=0;k<TelLength;++k)
    {
        printf("%c",answer[k]);
    }
    printf("\n");
}


