#include "CSinglyList.h"
using namespace std;

template<class T>
class CSortedSinglyList:public CSinglyList<T> {
private:
	bool asc;   //�������Լ������true�����򣬣�false������

public:
	CSortedSinglyList(bool asc = true);    //����յ���������Ĭ�ϰ�����������
	CSortedSinglyList(T values[], int N, bool asc = true);   //�������鹹����������
	CSortedSinglyList(CSortedSinglyList<T> & list, bool asc = true);   //���ݸ�����������������һ���µ���������

	CNode<T> * insert(T value);    //�����������в���һ���µĽڵ�
	void insertUnrepeatable(T value);   //�����������в��벻�ظ���Ԫ��value
	CNode<T> * search(T key);    //����Ԫ��key���ڵ�λ�ã����ظýڵ�ĵ�ַ
	void removeFirst(T key);     //ɾ���״γ���key�Ľڵ�
};

/********************��Ա�����Ķ���******************************************************/
template<class T>
CSortedSinglyList<T>::CSortedSinglyList(bool asc = true)    //����յ���������Ĭ�ϰ�����������
{
	this->asc = asc;
}

template<class T>
CSortedSinglyList<T>::CSortedSinglyList(T values[], int N, bool asc = true)   //�������鹹����������
{
	this->asc = asc;
	for (int k = 0; k < N; ++k)
		this->insert(values[k]);
}

template<class T>
CSortedSinglyList<T>::CSortedSinglyList(CSortedSinglyList<T> & list, bool asc = true)   //���ݸ�����������������һ���µ���������
{
	this->asc = asc;
	CNode<T> * pFront = list.pHead;
	CNode<T> * p = pRront->pNext;
	for (; p != null;p=p->pNext)
		this->insert(p->data);
}

template<class T>
CNode<T> * CSortedSinglyList<T>::insert(T value)    //�����������в���һ���µĽڵ�
{
	CNode<T> *front = this->pHead, *p = pHead->pNext;
	while (p != nullptr && (this->asc ? value >= p->data : value <= p->data))
	{
		front = p;
		p = p->pNext;
	}
	CNode<T> *q = new CNode<T>(value, p);
	front->pNext = q;
	return q;
}

template<class T>
void CSortedSinglyList<T>::removeFirst(T key)     //ɾ���״γ���key�Ľڵ�
{
	CNode<T> *front = this->pHead, *p = pHead->pNext;
	while (p != nullptr && (this->asc ? key >= p->data : key <= p->data))
	{
		front = p;
		p = p->pNext;
	}
	if (p != nullptr && key == p->data)
	{
		front->pNext = p->pNext;
		delete p;
	}
}

template<class T>
CNode<T> * CSortedSinglyList<T>::search(T key)    //����Ԫ��key���ڵ�λ�ã����ظýڵ�ĵ�ַ
{
	CNode<T> *front = this->pHead, *p = pHead->pNext;
	while (p != nullptr)
	{
		if (key != p->data)
			p = p->pNext;
		else
			return p;
	}
	return nullptr;
}

template<class T>
void CSortedSinglyList<T>::insertUnrepeatable(T value)   //�����������в��벻�ظ���Ԫ��value
{
	if (search(value) == nullptr)
		insert(value);
}

