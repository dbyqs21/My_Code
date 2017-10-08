//二叉搜索树
using namespace std;
template<class T>
class CBST{
private:
	//数的节点类
	class CTreeElement{
	public:
		T data;
		CTreeElement * pLeft;
		CTreeElement * pRight;

		CTreeElement(T t) :data(t), pLeft(nullptr), pRight(nullptr)；
	};

public:
	CTreeElement * pBST;

public:
	CBST()
	{
		pBST = nullptr;
	}

	void insertElement(T value);  //将一个元素插入BST
	bool deleteElement(T value);   //将一个元素从BST中删去

	CTreeElement * findPreNode(T value);  //从BST中返回要查找的元素所在的节点的根节点地址

	CTreeElement * find(T value);  //从BST中返回要查找的元素所在的节点的地址
	CTreeElement * findMin();    //返回BST中最小元素所在的节点的地址
	CTreeElement * findMax();    //返回BST中最大元素所在的节点的地址

};

/****************成员函数的定义***************************/
template<class T>
void CBST<T>::insertElement(T value)  //将一个元素插入BST
{
	CTreeElement * p = new CTreeElement(value);
	if (pBST != nullptr)
	{
		CTreeElement *q = pBST;
		CTreeElement *pPre = nullptr;

		while (q)   //控制树的深度
		{
			if (value > q->data) //value 大于当前节点的值
			{
				pPre = q;
				q = q->pRight;
			}
			else if (value < q->data) //value 小于当前节点的值
			{
				pPre = q;
				q = q->pLeft;
			}
			else  //value 与当前节点的值相等
			{
				return;
			}
		}
		//出while循环后的pPre值就是将要插入节点的根节点

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
CTreeElement * CBST<T>::findPreNode(T value)  //从BST中返回要查找的元素所在的节点的根节点地址
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
			return pPre; //遇到相等的元素
	}
	return nullptr;
}


template<class T>
bool CBST<T>::deleteElement(T value)   //将一个元素从BST中删去
{
	if (pBST != nullptr)
	{
		//找出value所在的位置，并删除
		
	}
	else
		return false;
}

template<class T>
CTreeElement * CBST<T>::find(T value)  //从BST中返回要查找的元素所在的节点的地址
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