#include "CSinglyList.h"
using namespace std;

template<class T>
class CSortedSinglyList:public CSinglyList<T> {
private:
	bool asc;   //排序次序约定。（true）升序，（false）降序

public:
	CSortedSinglyList(bool asc = true);    //构造空的排序单链表，默认按照升序排序
	CSortedSinglyList(T values[], int N, bool asc = true);   //按照数组构造排序单链表
	CSortedSinglyList(CSortedSinglyList<T> & list, bool asc = true);   //根据给定的有序单链表，构造一个新的排序单链表

	CNode<T> * insert(T value);    //向有序单链表中插入一个新的节点
	void insertUnrepeatable(T value);   //向有序单链表中插入不重复的元素value
	CNode<T> * search(T key);    //查找元素key所在的位置，返回该节点的地址
	void removeFirst(T key);     //删除首次出现key的节点
};

/********************成员函数的定义******************************************************/
template<class T>
CSortedSinglyList<T>::CSortedSinglyList(bool asc = true)    //构造空的排序单链表，默认按照升序排序
{
	this->asc = asc;
}

template<class T>
CSortedSinglyList<T>::CSortedSinglyList(T values[], int N, bool asc = true)   //按照数组构造排序单链表
{
	this->asc = asc;
	for (int k = 0; k < N; ++k)
		this->insert(values[k]);
}

template<class T>
CSortedSinglyList<T>::CSortedSinglyList(CSortedSinglyList<T> & list, bool asc = true)   //根据给定的有序单链表，构造一个新的排序单链表
{
	this->asc = asc;
	CNode<T> * pFront = list.pHead;
	CNode<T> * p = pRront->pNext;
	for (; p != null;p=p->pNext)
		this->insert(p->data);
}

template<class T>
CNode<T> * CSortedSinglyList<T>::insert(T value)    //向有序单链表中插入一个新的节点
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
void CSortedSinglyList<T>::removeFirst(T key)     //删除首次出现key的节点
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
CNode<T> * CSortedSinglyList<T>::search(T key)    //查找元素key所在的位置，返回该节点的地址
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
void CSortedSinglyList<T>::insertUnrepeatable(T value)   //向有序单链表中插入不重复的元素value
{
	if (search(value) == nullptr)
		insert(value);
}

