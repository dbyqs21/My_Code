// C++source code
#include <iostream>
using namespace std;

/** \brief ���ݶ�������ǰ�����������������ؽ�������
 *
 * \param
 * \param
 * \return
 *
 */

 #define TREELEN 6

 /**< ���ڵ� */
 struct Node
 {
     Node * pLeft;
     Node * pRight;
     char chValue;
 };

void reBuild(char * pPreOrder, char * pInOrder, int nTreeLen, Node ** pRoot)
{
    /**< ���߽����� */
    if(pPreOrder == nullptr || pInOrder == nullptr)
        return;
    /**< ��ñ߽������ĵ�һ���ڵ� */
    Node * pTemp = new Node;
    pTemp -> chValue = *pPreOrder;
    pTemp -> pLeft =nullptr;
    pTemp -> pRight =nullptr;

    // ����ڵ�Ϊ�գ��ѵ�ǰ�ڵ㸴�Ƶ����ڵ�
    if (*pRoot == nullptr)
    {
        *pRoot = pTemp;
    }

    //�����ǰ���ĳ���Ϊ1����ô�Ѿ������һ���ڵ�
    if(nTreeLen == 1)
    {
        return;
    }

    //Ѱ�������ĳ���
    char * pOrgInOrder = pInOrder;
    char * pLeftEnd = pInOrder;
    int nTempLen =0;

    // �ҵ��������Ľ�β
    while (*pPreOrder != *pLeftEnd)
    {
        if(pPreOrder == nullptr || pLeftEnd == nullptr)
        {
            return;
        }
        nTempLen++;

        /**< ��¼��ʱ���ȣ�������� */
        if (nTempLen > nTreeLen)
        {
            break;
        }
        pLeftEnd++;
    }

    // Ѱ���������ĳ���
    int nLeftLen = 0;
    nLeftLen = (int)(pLeftEnd - pOrgInOrder);

    // Ѱ���������ĳ���
    int nRightLen = 0;
    nRightLen = nTreeLen - nLeftLen-1;

    // �ؽ�������
    if (nLeftLen > 0)
    {
        reBuild(pPreOrder+1,pInOrder,nLeftLen,&((*pRoot)->pLeft));
    }

    // �ؽ�������
    if (nRightLen > 0 )
    {
        reBuild(pPreOrder+pLeftLen+1, pInOrder+nLeftLen+1, nRightLen, &((*pRoot)->pRight));
    }
}

void reBuild_test()
{
    char szPreOrder[]={'a','b','c','d','e','f'};
    char szInOrder[]={'d','b','a','e','c','f'};

    Node * pRoot = null;
    reBuild(szPreOrder, szInOrder, TREELEN, &pRoot);
}

