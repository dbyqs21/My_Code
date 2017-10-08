template <class T>
class CNode{
public:
	T data;
	CNode<T> * pNext;

	CNode()   //构造节点，data域未初始化
	{
		this->pNext = nullptr;
	}

	//构造函数，data域已给定值初始化
	CNode(T data, CNode<T> *pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
};