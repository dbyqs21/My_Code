//����������
using namespace std;
template<class T>
class CBST{
private:
	//���Ľڵ���
	class CTreeElement{
	public:
		T data;
		CTreeElement * pLeft;
		CTreeElement * pRight;

		CTreeElement(T t) :data(t), pLeft(nullptr), pRight(nullptr)��
	};

public:
	CTreeElement * pBST;

public:
	CBST()
	{
		pBST = nullptr;
	}

	void insertElement(T value);  //��һ��Ԫ�ز���BST
	bool deleteElement(T value);   //��һ��Ԫ�ش�BST��ɾȥ

	CTreeElement * findPreNode(T value);  //��BST�з���Ҫ���ҵ�Ԫ�����ڵĽڵ�ĸ��ڵ��ַ

	CTreeElement * find(T value);  //��BST�з���Ҫ���ҵ�Ԫ�����ڵĽڵ�ĵ�ַ
	CTreeElement * findMin();    //����BST����СԪ�����ڵĽڵ�ĵ�ַ
	CTreeElement * findMax();    //����BST�����Ԫ�����ڵĽڵ�ĵ�ַ

};

/****************��Ա�����Ķ���***************************/
template<class T>
void CBST<T>::insertElement(T value)  //��һ��Ԫ�ز���BST
{
	CTreeElement * p = new CTreeElement(value);
	if (pBST != nullptr)
	{
		CTreeElement *q = pBST;
		CTreeElement *pPre = nullptr;

		while (q)   //�����������
		{
			if (value > q->data) //value ���ڵ�ǰ�ڵ��ֵ
			{
				pPre = q;
				q = q->pRight;
			}
			else if (value < q->data) //value С�ڵ�ǰ�ڵ��ֵ
			{
				pPre = q;
				q = q->pLeft;
			}
			else  //value �뵱ǰ�ڵ��ֵ���
			{
				return;
			}
		}
		//��whileѭ�����pPreֵ���ǽ�Ҫ����ڵ�ĸ��ڵ�

		if (value < pPre->data)
			pPre->pLeft = p;
		if (value > pPre->data)
			pPre->pRight = p;
	}
	else
	{
		pBST = p;
	}

}

template<class T>
CTreeElement * CBST<T>::findPreNode(T value)  //��BST�з���Ҫ���ҵ�Ԫ�����ڵĽڵ�ĸ��ڵ��ַ
{
	CTreeElement * q = pBST;
	CTreeElement *pPre = nullptr;
	while (q)
	{
		if (value < q->data)
		{
			pPre = q;
			q = q->pLeft;
		}
		else if (value > q->data)
		{
			pPre = q;
			q = q->pRight;
		}
		else
			return pPre; //������ȵ�Ԫ��
	}
	return nullptr;
}


template<class T>
bool CBST<T>::deleteElement(T value)   //��һ��Ԫ�ش�BST��ɾȥ
{
	if (pBST != nullptr)
	{
		//�ҳ�value���ڵ�λ�ã���ɾ��
		
	}
	else
		return false;
}

template<class T>
CTreeElement * CBST<T>::find(T value)  //��BST�з���Ҫ���ҵ�Ԫ�����ڵĽڵ�ĵ�ַ
{
	if (pBST)
	{
		CTreeElement * p = pBST;
		while (p)
		{
			if (value < p->data)
			{
				p = p->pLeft;
			}
			else if (value > p->data)
			{
				p = p->pRight;
			}
			else
				return true;
		}
	}
	else
		return false;
}