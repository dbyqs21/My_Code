// C++ source code

#include <iostream>
#include <stdlib.h>
#include <cstddef>

using namespace std;

/** \brief 计算一个二叉树中距离最远的两个节点的距离
 *
 * \param
 * \param
 * \return
 *
 */

 struct Node
 {
    Node * pLeft; //左子树
    Node * pRight; //右子树
    int nMaxLeft; //左子树中的最远距离
    int nMaxRight; //右子树中的最远距离
    char Value; //该节点的值
 };

 int nMaxLen=0;

 void findMaxFind(Node * pRoot)
 {
     /**< 如果遍历到叶子节点，则返回 */
     if (pRoot == nullptr)
     {
         return;
     }

     /**< 如果左子树为空 */
     if (pRoot->pLeft == nullptr)
     {
         pRoot->nMaxLeft=0;
     }

     /**< 若右子树为空，那么该节点下面右子树的右边最长为0 */
     if (pRoot ->pRight == nullptr)
     {
         pRoot->nMaxRight =0;
     }
     /**< 若左子树非空 , 左递归*/
     if (pRoot->pLeft != null)
     {
         findMaxFind(pRoot->nLeft);
     }
     /**< 若右子树非空 ， 右递归*/
    if (pRoot->pRight != null)
     {
         findMaxFind(pRoot->pRight);
     }

     /**< 计算左子树最长节点 */
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

     /**< 计算右子树的最长节点 */
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

     /**< 更新最大的节点距离 */
     if (pRoot->pMaxRight + pRoot->nMaxLeft > nMaxLen)
     {
         nMaxLen=pRoot->nMaxLeft + pRoot->nMaxRight;
     }

 }


