template<class T>
class CNode{
public:
	T data;
	CNode<T> *pNext;

	CNode()
	{
		this->pNext = NULL:
	}

	CNode(T data, CNode<T> *pNext = NULL)
	{
		this.data = data;
		this.pNext = pNext;
	}

	void headInsert(CNode * pHead);    //���ڵ��ͷ����ڵ�
	void tailInsert(CNode * pHead);    //���ڵ��β������ڵ�
	void middleInsert(CNode * pHead);  //���м����ڵ�

	void sort();        //����data�Ĵ�С��С�����˳������
};

/*****************��Ա�����Ķ���****************************/

template<class T>
void CNode<T>::headInsert(CNode * pHead)    //���ڵ��ͷ����ڵ�
{
	CNode * p = pHead;
	pHead = this;
	this->pNext = p;
}

template<class T>
void CNode<T>::tailInsert(CNode * pHead)    //���ڵ��β������ڵ�
{
	CNode * p = pHead;
	while (p->pNext)
		p = p->pNext;
	p->pNext = this;
}

template<class T>
void CNode<T>::middleInsert(CNode * pHead)  //���м����ڵ�
{
	CNode * q = pHead;
	for (CNode * p = pHead; p->pNext != NULL; q=p,p = p->pNext)
	{
		if (p->data > this->data)
		{
			q->pNext = this;
			this->pNext = p;
		}
	}
	if (q->pNext == NULL)
	{
		tailInsert(pHead);
	}
}

template<class T>
void CNode<T>::sort()        //����data�Ĵ�С��С�����˳������
{
	CNode * PMax = this;
	while (PMax)
	{
		CNode * pPreMax = PMax;
		CNode *q = pPreMax;
		for (CNode * p = pMaxNext; p->pNext != NULL; q=p,p = p->pNext)
		{
			if (p->data > pPreMax->pNext->data)
			{
				pPreMax = q;
			}
		}
		// ȡ��ֵ���Ľڵ�
		q = pPreMax->pNext;
		pPreMax = q->pNext; 
		//�����ֵ�ڵ�
		q->pNext = this;
		this = q;    


		PMax = PMax->pNext;
	}
	

}