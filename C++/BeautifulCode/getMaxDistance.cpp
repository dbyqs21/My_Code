// C++ source code

#include <iostream>
#include <stdlib.h>
#include <cstddef>

using namespace std;

/** \brief ����һ���������о�����Զ�������ڵ�ľ���
 *
 * \param
 * \param
 * \return
 *
 */

 struct Node
 {
    Node * pLeft; //������
    Node * pRight; //������
    int nMaxLeft; //�������е���Զ����
    int nMaxRight; //�������е���Զ����
    char Value; //�ýڵ��ֵ
 };

 int nMaxLen=0;

 void findMaxFind(Node * pRoot)
 {
     /**< ���������Ҷ�ӽڵ㣬�򷵻� */
     if (pRoot == nullptr)
     {
         return;
     }

     /**< ���������Ϊ�� */
     if (pRoot->pLeft == nullptr)
     {
         pRoot->nMaxLeft=0;
     }

     /**< ��������Ϊ�գ���ô�ýڵ��������������ұ��Ϊ0 */
     if (pRoot ->pRight == nullptr)
     {
         pRoot->nMaxRight =0;
     }
     /**< ���������ǿ� , ��ݹ�*/
     if (pRoot->pLeft != null)
     {
         findMaxFind(pRoot->nLeft);
     }
     /**< ���������ǿ� �� �ҵݹ�*/
    if (pRoot->pRight != null)
     {
         findMaxFind(pRoot->pRight);
     }

     /**< ������������ڵ� */
     if (pRoot->pLeft != nullptr)
     {
         int nTempMax=0;
         if (pRoot->pLeft->nMaxLeft > pRoot->pLeft->nMaxRight)
         {
             nTempMax=pRoot->pLeft->nMaxLeft;
         }
         else
        {
            nTempMax=pRoot->pLeft->nMaxRight;
        }
        pRoot->Value=nTempMax+1;
     }

     /**< ��������������ڵ� */
     if (pRoot->pRight != nullptr)
     {
         int nTempMax=0;
         if (pRoot->pRight->nMaxLeft > pRoot->pRight->nMaxRight)
         {
             nTempMax=pRoot->pRight->nMaxLeft;
         }
         else
         {
             nTempMax=pRoot->pRight->nMaxRight;
         }
         pRoot->pRight->Value=nTempMAX+1;
     }

     /**< �������Ľڵ���� */
     if (pRoot->pMaxRight + pRoot->nMaxLeft > nMaxLen)
     {
         nMaxLen=pRoot->nMaxLeft + pRoot->nMaxRight;
     }

 }


