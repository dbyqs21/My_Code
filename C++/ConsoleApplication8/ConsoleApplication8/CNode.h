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

	void headInsert(CNode * pHead);    //将节点从头插入节点
	void tailInsert(CNode * pHead);    //将节点从尾部插入节点
	void middleInsert(CNode * pHead);  //从中间插入节点

	void sort();        //按照data的大小从小到大的顺序排序
};

/*****************成员函数的定义****************************/

template<class T>
void CNode<T>::headInsert(CNode * pHead)    //将节点从头插入节点
{
	CNode * p = pHead;
	pHead = this;
	this->pNext = p;
}

template<class T>
void CNode<T>::tailInsert(CNode * pHead)    //将节点从尾部插入节点
{
	CNode * p = pHead;
	while (p->pNext)
		p = p->pNext;
	p->pNext = this;
}

template<class T>
void CNode<T>::middleInsert(CNode * pHead)  //从中间插入节点
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
void CNode<T>::sort()        //按照data的大小从小到大的顺序排序
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
		// 取出值最大的节点
		q = pPreMax->pNext;
		pPreMax = q->pNext; 
		//将最大值节点
		q->pNext = this;
		this = q;    


		PMax = PMax->pNext;
	}
	

}