template <class T>
class CNode{
public:
	T data;
	CNode<T> * pNext;

	CNode()   //����ڵ㣬data��δ��ʼ��
	{
		this->pNext = nullptr;
	}

	//���캯����data���Ѹ���ֵ��ʼ��
	CNode(T data, CNode<T> *pNext = nullptr)
	{
		this->data = data;
		this->pNext = pNext;
	}
};