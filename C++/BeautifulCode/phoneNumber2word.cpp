// C++ source code
#include <stdio.h>
#include <stdlib.h>

#define TelLength 7

/** \brief �ҳ��ֻ������ּ����ϵĺ����Ӧ�ĵ��ʡ�����һ���ѭ���ķ�����ʵ��
 *
 * \param
 * \param
 * \return
 *
 */

void printWords()
{
    /**< ����洢��������ĸ������ */
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

    /**< �������������ܴ������ĸ�����洢�������� */
    int totalNum[10]={0,0,3,3,3,3,3,4,3,4};

    int number[TelLength];  /**< �洢�绰���� */
    char answer[TelLength]={0}; /**< �洢�ҵ��ĵ��ʴ� */

    /**< ��õ绰��������� */
    printf("������%dλ�绰���룺\n",TelLength);
    for (int k=0;k<TelLength;++k)
    {
        printf("�������%dλ���룺",k+1);
        scanf("%d",&number[k]);
        printf("\n");
    }

    while(true)
    {
        // TelLength Ϊ�绰����ĳ���
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

    /**< ������ */
    for (int k=0;k<TelLength;++k)
    {
        printf("%c",answer[k]);
    }
    printf("\n");
}


