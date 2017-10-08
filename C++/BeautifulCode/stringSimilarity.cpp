// C++ source code
#include <iostream>
using namespace std;

/** \brief 计算两个字符串之间的距离
 *
 * \param
 * \param
 * \return
 *
 */

 int calculateStringDistance(string strA, int pABegin, int pAEnd,
                             string strB, int pBBegin, int pBEnd)
    {
        if (pABegin > pAEnd)
        {
            if (pBBegin > pBEnd)
            {
                return 0;
            }
            else
            {
                return pBEnd-pBBegin+1;
            }
        }

        if (pBBegin > pBEnd)
        {
            if (pABegin > pAEnd)
            {
                return 0;
            }
            else
            {
                return pAEnd-pABegin+1;
            }
        }

        if (strA[pABegin] == strB[pBBegin])
        {
            return calculateStringDistance(strA, pABegin+1,pAEnd,strB,pBBegin+1,pBEnd);
        }
        else
        {
            int t1=calculateStringDistance(strA, pABegin,pAEnd,strB,pBBegin+1,pBEnd);
            int t2=calculateStringDistance(strA, pABegin+1,pAEnd,strB,pBBegin,pBEnd);
            int t3=calculateStringDistance(strA, pABegin+1,pAEnd,strB,pBBegin+1,pBEnd);
            /**< 返回最小的那个距离 */
            int minValue=t1<t2?t1:t2;
            return minValue<t3?minValue:t3;
        }
    }

