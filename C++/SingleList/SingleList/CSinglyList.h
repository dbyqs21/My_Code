#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;
#include "CNode.h"

template<class T>
class CSinglyList {
public:
	CNode<T> *pHead;

	//构造函数
	CSinglyList();      //默认构造函数
	CSinglyList(T values[], int N);     //以数组方式初始化单链表
	CSinglyList(CSinglyList<T> & list);     //拷贝构造函数
	~CSinglyList();    //析构函数

	/*********功能成员函数***************/
	bool empty();   //判断单链表是否为空
	int count();    //统计单链表中的节点数
	T& get(int i);  //返回第i个节点的数据
	virtual void set(int i, T value);    //将第i个位置上的元素的值设为value
	friend ostream & operator<<<>(ostream & cout, CSinglyList<T> & list);
	CNode<T> * insert(int i, T value);   //插入元素value作为第i个节点，返回插入点的地址
	void append(T value);         //向链表的尾部插入节点
	T remove(int i);     //删除第i个位置的元素
	void removeAll();    //删除所有单向链表里的所有元素
	CNode<T> * search(T key);    //查找元素key在单链表里的位置，并返回指向这个节点的指针，若没有找到，返回NULL
	void insertUnreaptable(T value);    //向单链表里插入不重复的元素value
	virtual void removeFirst(T key);    //删除第一次出现key的节点

	bool operator==(CSinglyList<T> & list);   //重载==运算符
	bool operator!=(CSinglyList<T> & list);  //重载!=运算符
	CSinglyList<T> & operator=(CSinglyList<T> & list);  //重载赋值运算符，深拷贝
	virtual void operator+=(CSinglyList<T> & list);    //将list链接在当前链表之后
};

/*****************成员函数的定义***************************************************/
template<class T>
CSinglyList<T>::CSinglyList()      //默认构造函数
{
	this->pHead = new CNode<T>();
}

template<class T>
CSinglyList<T>::CSinglyList(T values[], int N)    //以数组方式初始化单链表
{
	this->pHead = new CNode<T>();
	CNode<T> * pRear = this->pHead;    //pRear指向链表的最后一个节点

	for (int k = 0; k < N; ++k)
	{
		//创建节点并在链表的尾部插入该节点
		pRear->pNext = new CNode<T>(values[k]);
		pRear = pRear->pNext;
	}
}

template<class T>
CSinglyList<T>::CSinglyList(CSinglyList<T> & list)     //拷贝构造函数
{
	this->pHead = new CNode<T>();
	CNode<T> * pRear = this->pHead;    //pRear指向链表的最后一个节点

	CNode<T> * q = list.pHead;
	for (; q != null; q = q->pNext)
	{
		//创建节点并在链表的尾部插入该节点
		pRear->pNext = new CNode<T>(q->data);
		pRear = pRear->pNext;
	}
}

template<class T>
CSinglyList<T>::~CSinglyList()    //析构函数
{
	this->removeAll();
	delete this->pHead;
}

template<class T>
bool CSinglyList<T>::empty()   //判断单链表是否为空
{
	return this->pHead->pNext == nullptr ? true : false;
}

template<class T>
int CSinglyList<T>::count()    //统计单链表中的节点数
{
	int count = 0;
	if (!empty())
	{
		CNode<T> * q = this->pHead->pNext;
		for (; q != nullptr ; count++, q = q->pNext);
	}
	return count;
}

template<class T>
T& CSinglyList<T>::get(int i)  //返回第i个节点的数据
{
	int count = 0;
	CNode<T> * q = this->pHead->pNext;
	for (; q != null; ++count, q = q->pNext)
	{
		if (count == i)
			return q->data;
	}
	cout << i << "已经超出了单链表的范围" << endl;
}

template<class T>
void CSinglyList<T>::set(int i, T value)    //将第i个位置上的元素的值设为value
{
	int count = 0;
	CNode<T> * q = this->pHead->pNext;
	for (; q != nullptr ; ++count, q = q->pNext)
	{
		if (count == i)
		{
			q->data = value;
			return;
		}
	}
	cout << i << "已经超出了单链表的范围" << endl;
}

template<class T>
ostream & operator<<<>(ostream & cout, CSinglyList<T> & list)
{
	cout << "(";
	CNode<T> * q = list.pHead->pNext;
	for (; q != nullptr; q = q->pNext)
	{
		if (q->pNext == nullptr)
			cout << q->data;
		else
		{
			cout << q->data << ", ";
		}
	}
	cout << ")" << endl;
	return cout;
}

template<class T>
CNode<T> * CSinglyList<T>::insert(int i, T value)   //插入元素value作为第i个节点之后，返回插入点的地址
{
	int count = 0;
	CNode<T> * q = this->pHead->pNext;
	for (; q != nullptr ; ++count, q = q->pNext)
	{
		if (count == i)
		{
			CNode<T> *p = q->pNext;
			q->pNext = new CNode<T>(value);
			q->pNext->pNext = p;
			return q->pNext;
		}
	}
	cout << i << "已经超出了单链表的范围,无法插入到第"<< i <<"个位置" << endl;
}

template<class T>
void CSinglyList<T>::append(T value)         //向链表的尾部插入节点
{
	if (this->empty())
	{
		this->pHead->pNext = new CNode<T>(value);
	}
	else
	{
		CNode<T> * q = this->pHead->pNext;
		while (q != nullptr)
			q = q->pNext;
		q->pNext = new CNode<T>(value);
	}
}

template<class T>
T CSinglyList<T>::remove(int i)     //删除第i个位置的元素
{
	int count = 0;
	CNode<T> * q = this->pHead->pNext;
	CNode<T> * pPre = q;
	for (; q != null ; ++count, pPre = q, q = q->pNext)
	{
		if (count == i)
		{
			pPre->pNext = q->pNext;  //删除节点
			T tmp = q->data;
			delete q;                //释放空间
			return tmp;
		}
	}
	cout << i << "已经超出了单链表的范围" << endl;
}

template<class T>
void CSinglyList<T>::removeAll()    //删除所有单向链表里的所有元素
{
	if (!empty())
	{
		CNode<T> * p = this->pHead->pNext;
		while (this->pHead)
		{
			p = this->pHead;
			this->pHead = this->pHead->pNext;
			delete p;
		}
	}
}

template<class T>
CNode<T> * CSinglyList<T>::search(T key)    //查找元素key在单链表里的位置，并返回指向这个节点的指针，若没有找到，返回NULL
{
	if (!empty)
	{
		CNode<T> * q = this->pHead->pNext;
		for (; q != null ; q = q->pNext)
		{
			if (q->data == key)
				return q;
		}
	}
	else
	{
		cout << "链表为空" << endl;
		return nullptr;
	}
}

template<class T>
void CSinglyList<T>::insertUnreaptable(T value)    //向单链表里插入不重复的元素value
{
	if (search(value) == nullptr)
		return;
	else
	{
		append(value);
	}
}

template<class T>
void CSinglyList<T>::removeFirst(T key)    //删除第一次出现key的节点
{
	CNode<T> * q = this->pHead->pNext;
	CNode<T> * pPre = q;
	for (; q != nullptr ; pPre = q, q = q->pNext)
	{
		if (q->data == key)
		{
			pPre->pNext = q->pNext;  //删除节点
			delete q;                //释放空间
			return ;
		}
	}
	cout << "未找到元素"<< key<< endl;
}

template<class T>
bool CSinglyList<T>::operator==(CSinglyList<T> & list)   //重载==运算符
{
	if (this->count() == list.count())
	{
		CNode<T> * p = this->pHead->pNext;
		CNode<T> * q = list.pHead->pNext;
		for (; p!=nullptr ; p - p->pNext, q = q->pNext)
		{
			if (p->data != q->data)
				return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
bool CSinglyList<T>::operator != (CSinglyList<T> & list)  //重载!=运算符
{
	if (this->count() == list.count())
	{
		CNode<T> * p = this->pHead->pNext;
		CNode<T> * q = list.pHead->pNext;
		for (; p!=nullptr ; p - p->pNext, q = q->pNext)
		{
			if (p->data != q->data)
				return true;
		}
		return false;
	}
	else
	{
		return true;
	}
}

template<class T>
CSinglyList<T> & CSinglyList<T>::operator=(CSinglyList<T> & list)  //重载赋值运算符，深拷贝
{
	CNode<T> * p = this->pHead->pNext;
	CNode<T> * pPre = p;
	CNode<T> * q = list.pHead->pNext;
	for (; q != nullptr ;pPre=p, p - p->pNext, q = q->pNext)
	{
		if (empty())  //如果链表为空
		{
			p = new CNode<T>(q->data);
		}
		else  //如果链表非空
		{
			if (p != nullptr)   //p指向了一个节点
				p->data = q->data;
			else   //p指向了nullptr
			{
				p = new CNode<T>(q->data);
				pPre->pNext = p;
			}
		}
	}
	return *this;
}

template<class T>
void CSinglyList<T>::operator+=(CSinglyList<T> & list)    //将list链接在当前链表之后
{
	CNode<T> * q = this->pHead->pNext;
	if (empty())
		this->pHead = list.pHead->pNext;
	else
	{
		while (q->pNext != nullptr)
			q = q->pNext;
		q->pNext = list.pHead;
	}
	list.pHead=nullptr;
}