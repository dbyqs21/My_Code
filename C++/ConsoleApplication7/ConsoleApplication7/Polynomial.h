#include <iostream>
using namespace std;

struct PloyNode{
	int coef = 0;
	int index = 0;
	PloyNode * pNode = NULL;
};


//按从小到大的方式插入链表
PloyNode * insertNode(PloyNode *pHead, PloyNode * pNewNode)
{

	PloyNode * q = pHead;
	//如果仅有头结点
	if (pHead->pNode == NULL)
	{
		pHead->pNode = pNewNode;
		return pHead;
	}
	// 如果有一个以及一个以上数据节点
	for (PloyNode * p = pHead->pNode; p != NULL; p = p->pNode, q = q->pNode)
	{
		if (p->index > pNewNode->index)
		{
			pNewNode->pNode = p;
			q->pNode = pNewNode;
			return pHead;
		}

		//如果节点指数相等
		if (p->index == pNewNode->index)
		{
			p->coef += pNewNode->coef;
			return pHead;
		}
		//如果遇到尾节点
		if (p->pNode == NULL)
		{
			p->pNode = pNewNode;
			return pHead;
		}
	}

	return pHead;
}

//读入多项式，存入链表中
PloyNode* ReadPloynomial(PloyNode * pHead)
{
	cout << "请输入多项式的项数以及对应各项的系数和指数：" << endl;
	int N = 0;

	if (cin >> N)
	{
		//创建头结点
		PloyNode *pEnd = (PloyNode *)malloc(sizeof(PloyNode));
		pEnd->coef = N;
		pEnd->index = 0;
		pEnd->pNode = NULL;
		pHead = pEnd;

		while (N--)
		{
			int coef = 0;
			int index = 0;
			PloyNode *p = NULL;
			if (cin >> coef)
			{
			    p = (PloyNode *)malloc (sizeof(PloyNode));
				p->coef = coef;
				
			}
			if (cin >> index)
			{
				if (index < 0)
				{
					cout << "指数不能为负数" << endl;
					return pHead;
				}
				p->index = index;
				p->pNode = NULL;
			}
			//将节点加入链表
			pHead=insertNode(pHead, p);
		}

	}
	return pHead;
}

//输出节点内容
void printNode(PloyNode * pHead)
{
	for (PloyNode *p = pHead->pNode; p!= NULL; p = p->pNode)
	{
		cout << p->coef <<" "<< p->index<<" ";
	}
	cout << endl;
}

//计算多项式的和
PloyNode * ployAdd(PloyNode * pHeadl, PloyNode *pHeadr)
{
	//创建多项式的和的头结点
	PloyNode *pSum = (PloyNode *)malloc(sizeof(PloyNode));
	pSum->coef = 0;
	pSum->index = 0;
	pSum->pNode = NULL;

	//计算多项式的和
	PloyNode * q = pHeadr->pNode;
	PloyNode * p = pHeadl->pNode;
	for (; p != NULL && q!=NULL; p = p->pNode)
	{
		if (p->index < q->index)
		{
			pSum=insertNode(pSum, p);
		}
		else if (p->index > q->index)
		{
			pSum = insertNode(pSum, q);
			q = q->pNode;
		}
		else
		{
			PloyNode *pNewNode = (PloyNode *)malloc(sizeof(PloyNode));
			pNewNode->coef = p->coef + q->coef;
			pNewNode->index = p->index;
			pNewNode->pNode = NULL;
			//将节点插入到和链表中
			pSum = insertNode(pSum, pNewNode);
			q = q->pNode;
		}
	}

	//把没有参与计算的多项式节点复制到和多项式节点中
	while (p != NULL)
	{
		PloyNode *pNewNode = (PloyNode *)malloc(sizeof(PloyNode));
		pNewNode->coef = p->coef;
		pNewNode->index = p->index;
		pNewNode->pNode = NULL;
		//将节点插入到和链表中
		pSum = insertNode(pSum, pNewNode);
		p = p->pNode;
	}

	while (q != NULL)
	{
		PloyNode *pNewNode = (PloyNode *)malloc(sizeof(PloyNode));
		pNewNode->coef = q->coef;
		pNewNode->index = q->index;
		pNewNode->pNode = NULL;
		//将节点插入到和链表中
		pSum = insertNode(pSum, pNewNode);
		q = q->pNode;
	}
	return pSum;
}

//计算多项式的积
PloyNode * ployMult(PloyNode * pHeadl, PloyNode *pHeadr)
{
	//创建多项式的和的头结点
	PloyNode *pMult = (PloyNode *)malloc(sizeof(PloyNode));
	pMult->coef = 0;
	pMult->index = 0;
	pMult->pNode = NULL;

	//计算多项式的和
	for (PloyNode * p = pHeadl->pNode; p != NULL ; p = p->pNode)
	{
		for (PloyNode * q = pHeadr->pNode; q != NULL; q = q->pNode)
		{
			PloyNode *pNewNode = (PloyNode *)malloc(sizeof(PloyNode));
			pNewNode->coef = p->coef*q->coef;
			pNewNode->index = p->index+q->index;
			pNewNode->pNode = NULL;
			//将节点插入到和链表中
			pMult = insertNode(pMult, pNewNode);
		}
	}
	return pMult;
}

//删除链表
PloyNode * deletelink(PloyNode * pHead)
{
	for (PloyNode * p = pHead->pNode; p != NULL; p = pHead->pNode)
	{
		pHead = p->pNode;
		free(p);
	}
	return pHead;
}