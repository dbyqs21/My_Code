// C++source code
#include <iostream>
using namespace std;

/** \brief 根据二叉树的前序遍历和中序遍历，重建二叉树
 *
 * \param
 * \param
 * \return
 *
 */

 #define TREELEN 6

 /**< 树节点 */
 struct Node
 {
     Node * pLeft;
     Node * pRight;
     char chValue;
 };

void reBuild(char * pPreOrder, char * pInOrder, int nTreeLen, Node ** pRoot)
{
    /**< 检查边界条件 */
    if(pPreOrder == nullptr || pInOrder == nullptr)
        return;
    /**< 获得边界条件的第一个节点 */
    Node * pTemp = new Node;
    pTemp -> chValue = *pPreOrder;
    pTemp -> pLeft =nullptr;
    pTemp -> pRight =nullptr;

    // 如果节点为空，把当前节点复制到根节点
    if (*pRoot == nullptr)
    {
        *pRoot = pTemp;
    }

    //如果当前树的长度为1，那么已经是最后一个节点
    if(nTreeLen == 1)
    {
        return;
    }

    //寻找子树的长度
    char * pOrgInOrder = pInOrder;
    char * pLeftEnd = pInOrder;
    int nTempLen =0;

    // 找到左子树的结尾
    while (*pPreOrder != *pLeftEnd)
    {
        if(pPreOrder == nullptr || pLeftEnd == nullptr)
        {
            return;
        }
        nTempLen++;

        /**< 记录临时长度，以免溢出 */
        if (nTempLen > nTreeLen)
        {
            break;
        }
        pLeftEnd++;
    }

    // 寻找左子树的长度
    int nLeftLen = 0;
    nLeftLen = (int)(pLeftEnd - pOrgInOrder);

    // 寻找右子树的长度
    int nRightLen = 0;
    nRightLen = nTreeLen - nLeftLen-1;

    // 重建左子树
    if (nLeftLen > 0)
    {
        reBuild(pPreOrder+1,pInOrder,nLeftLen,&((*pRoot)->pLeft));
    }

    // 重建右子树
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

