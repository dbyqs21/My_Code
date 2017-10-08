#include <iostream>
using namespace std;

struct PloyNode{
	int coef = 0;
	int index = 0;
	PloyNode * pNode = NULL;
};


//����С����ķ�ʽ��������
PloyNode * insertNode(PloyNode *pHead, PloyNode * pNewNode)
{

	PloyNode * q = pHead;
	//�������ͷ���
	if (pHead->pNode == NULL)
	{
		pHead->pNode = pNewNode;
		return pHead;
	}
	// �����һ���Լ�һ���������ݽڵ�
	for (PloyNode * p = pHead->pNode; p != NULL; p = p->pNode, q = q->pNode)
	{
		if (p->index > pNewNode->index)
		{
			pNewNode->pNode = p;
			q->pNode = pNewNode;
			return pHead;
		}

		//����ڵ�ָ�����
		if (p->index == pNewNode->index)
		{
			p->coef += pNewNode->coef;
			return pHead;
		}
		//�������β�ڵ�
		if (p->pNode == NULL)
		{
			p->pNode = pNewNode;
			return pHead;
		}
	}

	return pHead;
}

//�������ʽ������������
PloyNode* ReadPloynomial(PloyNode * pHead)
{
	cout << "���������ʽ�������Լ���Ӧ�����ϵ����ָ����" << endl;
	int N = 0;

	if (cin >> N)
	{
		//����ͷ���
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
					cout << "ָ������Ϊ����" << endl;
					return pHead;
				}
				p->index = index;
				p->pNode = NULL;
			}
			//���ڵ��������
			pHead=insertNode(pHead, p);
		}

	}
	return pHead;
}

//����ڵ�����
void printNode(PloyNode * pHead)
{
	for (PloyNode *p = pHead->pNode; p!= NULL; p = p->pNode)
	{
		cout << p->coef <<" "<< p->index<<" ";
	}
	cout << endl;
}

//�������ʽ�ĺ�
PloyNode * ployAdd(PloyNode * pHeadl, PloyNode *pHeadr)
{
	//��������ʽ�ĺ͵�ͷ���
	PloyNode *pSum = (PloyNode *)malloc(sizeof(PloyNode));
	pSum->coef = 0;
	pSum->index = 0;
	pSum->pNode = NULL;

	//�������ʽ�ĺ�
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
			//���ڵ���뵽��������
			pSum = insertNode(pSum, pNewNode);
			q = q->pNode;
		}
	}

	//��û�в������Ķ���ʽ�ڵ㸴�Ƶ��Ͷ���ʽ�ڵ���
	while (p != NULL)
	{
		PloyNode *pNewNode = (PloyNode *)malloc(sizeof(PloyNode));
		pNewNode->coef = p->coef;
		pNewNode->index = p->index;
		pNewNode->pNode = NULL;
		//���ڵ���뵽��������
		pSum = insertNode(pSum, pNewNode);
		p = p->pNode;
	}

	while (q != NULL)
	{
		PloyNode *pNewNode = (PloyNode *)malloc(sizeof(PloyNode));
		pNewNode->coef = q->coef;
		pNewNode->index = q->index;
		pNewNode->pNode = NULL;
		//���ڵ���뵽��������
		pSum = insertNode(pSum, pNewNode);
		q = q->pNode;
	}
	return pSum;
}

//�������ʽ�Ļ�
PloyNode * ployMult(PloyNode * pHeadl, PloyNode *pHeadr)
{
	//��������ʽ�ĺ͵�ͷ���
	PloyNode *pMult = (PloyNode *)malloc(sizeof(PloyNode));
	pMult->coef = 0;
	pMult->index = 0;
	pMult->pNode = NULL;

	//�������ʽ�ĺ�
	for (PloyNode * p = pHeadl->pNode; p != NULL ; p = p->pNode)
	{
		for (PloyNode * q = pHeadr->pNode; q != NULL; q = q->pNode)
		{
			PloyNode *pNewNode = (PloyNode *)malloc(sizeof(PloyNode));
			pNewNode->coef = p->coef*q->coef;
			pNewNode->index = p->index+q->index;
			pNewNode->pNode = NULL;
			//���ڵ���뵽��������
			pMult = insertNode(pMult, pNewNode);
		}
	}
	return pMult;
}

//ɾ������
PloyNode * deletelink(PloyNode * pHead)
{
	for (PloyNode * p = pHead->pNode; p != NULL; p = pHead->pNode)
	{
		pHead = p->pNode;
		free(p);
	}
	return pHead;
}