#define pr(x) if(x<=n)printf("%d\n", x);
#include <stdio.h>

/** \brief ����n����������ֵ�˳�������1-n֮����
 *
 * \param
 * \param
 * \return
 *
 */

void test6()
{
    int i,j;
    int n;
    scanf("%d",&n);
    for(i = 1; i < 10; i ++)
    {
        j = 1;
        while(j*i<=n)
        {
            for(int k=j*i; k<j*(i+1); k++)
                pr(k);
            j*=10;
        }
    }
}
