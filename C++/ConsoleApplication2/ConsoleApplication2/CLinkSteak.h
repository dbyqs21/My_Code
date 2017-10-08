
template<class T>
class CSteak{
	class CNode {
	public:
		T Data;
		CNode * pNext;
	
		CNode(T t) :Data(t), pNext(nullptr){};
		~CNode(){};
	};
private:
	CNode *pHead;
	CNode *top;
	CNode *pPreTop;
	int count;

public:
	CSteak()
	{
		pHead = nullptr;
		top = pHead;
		pPreTop = pHead;
		count = 0;
	}

	bool isEmpty()
	{
		return top == pHead ? true : false;
	}
	
	void push(T value)
	{
		if (isEmpty())
		{
			CNode *p = new CNode(value);
			top = p;
			pHead = p;
			pPreTop = top;
		}
		CNode *p = new CNode(value);
		top->pNext = p;
		pPreTop = top;
		top = top->pNext;
		count++;
	}

	T pop()
	{
		if (!isEmpty())
		{
			T tmp = top->Data;
			pPreTop->pNext = nullptr;
			free(top);
			top = pPreTop;
			count--;
			if (count > 1) //�����ջ��ֻ����������������Ԫ��
			{
			pPreTop = pHead;
			while(pPreTop->pNext->pNext != nullptr)
				pPreTop = pPreTop->pNext;
			}
			else if (count == 1)  //�����ջ��ֻ��һ��Ԫ��
			{
				pPreTop = pHead;
			}
			else
			{
				free(pHead);
				pHead = nullptr;
				top = pHead;
				pPreTop = pHead;
			}
			return tmp;
		}
		else
		{
			cout << "ջ�ѿ�" << endl;
		}

	}
};