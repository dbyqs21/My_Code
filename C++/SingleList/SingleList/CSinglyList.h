#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;
#include "CNode.h"

template<class T>
class CSinglyList {
public:
	CNode<T> *pHead;

	//���캯��
	CSinglyList();      //Ĭ�Ϲ��캯��
	CSinglyList(T values[], int N);     //�����鷽ʽ��ʼ��������
	CSinglyList(CSinglyList<T> & list);     //�������캯��
	~CSinglyList();    //��������

	/*********���ܳ�Ա����***************/
	bool empty();   //�жϵ������Ƿ�Ϊ��
	int count();    //ͳ�Ƶ������еĽڵ���
	T& get(int i);  //���ص�i���ڵ������
	virtual void set(int i, T value);    //����i��λ���ϵ�Ԫ�ص�ֵ��Ϊvalue
	friend ostream & operator<<<>(ostream & cout, CSinglyList<T> & list);
	CNode<T> * insert(int i, T value);   //����Ԫ��value��Ϊ��i���ڵ㣬���ز����ĵ�ַ
	void append(T value);         //�������β������ڵ�
	T remove(int i);     //ɾ����i��λ�õ�Ԫ��
	void removeAll();    //ɾ�����е��������������Ԫ��
	CNode<T> * search(T key);    //����Ԫ��key�ڵ��������λ�ã�������ָ������ڵ��ָ�룬��û���ҵ�������NULL
	void insertUnreaptable(T value);    //����������벻�ظ���Ԫ��value
	virtual void removeFirst(T key);    //ɾ����һ�γ���key�Ľڵ�

	bool operator==(CSinglyList<T> & list);   //����==�����
	bool operator!=(CSinglyList<T> & list);  //����!=�����
	CSinglyList<T> & operator=(CSinglyList<T> & list);  //���ظ�ֵ����������
	virtual void operator+=(CSinglyList<T> & list);    //��list�����ڵ�ǰ����֮��
};

/*****************��Ա�����Ķ���***************************************************/
template<class T>
CSinglyList<T>::CSinglyList()      //Ĭ�Ϲ��캯��
{
	this->pHead = new CNode<T>();
}

template<class T>
CSinglyList<T>::CSinglyList(T values[], int N)    //�����鷽ʽ��ʼ��������
{
	this->pHead = new CNode<T>();
	CNode<T> * pRear = this->pHead;    //pRearָ����������һ���ڵ�

	for (int k = 0; k < N; ++k)
	{
		//�����ڵ㲢�������β������ýڵ�
		pRear->pNext = new CNode<T>(values[k]);
		pRear = pRear->pNext;
	}
}

template<class T>
CSinglyList<T>::CSinglyList(CSinglyList<T> & list)     //�������캯��
{
	this->pHead = new CNode<T>();
	CNode<T> * pRear = this->pHead;    //pRearָ����������һ���ڵ�

	CNode<T> * q = list.pHead;
	for (; q != null; q = q->pNext)
	{
		//�����ڵ㲢�������β������ýڵ�
		pRear->pNext = new CNode<T>(q->data);
		pRear = pRear->pNext;
	}
}

template<class T>
CSinglyList<T>::~CSinglyList()    //��������
{
	this->removeAll();
	delete this->pHead;
}

template<class T>
bool CSinglyList<T>::empty()   //�жϵ������Ƿ�Ϊ��
{
	return this->pHead->pNext == nullptr ? true : false;
}

template<class T>
int CSinglyList<T>::count()    //ͳ�Ƶ������еĽڵ���
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
T& CSinglyList<T>::get(int i)  //���ص�i���ڵ������
{
	int count = 0;
	CNode<T> * q = this->pHead->pNext;
	for (; q != null; ++count, q = q->pNext)
	{
		if (count == i)
			return q->data;
	}
	cout << i << "�Ѿ������˵�����ķ�Χ" << endl;
}

template<class T>
void CSinglyList<T>::set(int i, T value)    //����i��λ���ϵ�Ԫ�ص�ֵ��Ϊvalue
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
	cout << i << "�Ѿ������˵�����ķ�Χ" << endl;
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
CNode<T> * CSinglyList<T>::insert(int i, T value)   //����Ԫ��value��Ϊ��i���ڵ�֮�󣬷��ز����ĵ�ַ
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
	cout << i << "�Ѿ������˵�����ķ�Χ,�޷����뵽��"<< i <<"��λ��" << endl;
}

template<class T>
void CSinglyList<T>::append(T value)         //�������β������ڵ�
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
T CSinglyList<T>::remove(int i)     //ɾ����i��λ�õ�Ԫ��
{
	int count = 0;
	CNode<T> * q = this->pHead->pNext;
	CNode<T> * pPre = q;
	for (; q != null ; ++count, pPre = q, q = q->pNext)
	{
		if (count == i)
		{
			pPre->pNext = q->pNext;  //ɾ���ڵ�
			T tmp = q->data;
			delete q;                //�ͷſռ�
			return tmp;
		}
	}
	cout << i << "�Ѿ������˵�����ķ�Χ" << endl;
}

template<class T>
void CSinglyList<T>::removeAll()    //ɾ�����е��������������Ԫ��
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
CNode<T> * CSinglyList<T>::search(T key)    //����Ԫ��key�ڵ��������λ�ã�������ָ������ڵ��ָ�룬��û���ҵ�������NULL
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
		cout << "����Ϊ��" << endl;
		return nullptr;
	}
}

template<class T>
void CSinglyList<T>::insertUnreaptable(T value)    //����������벻�ظ���Ԫ��value
{
	if (search(value) == nullptr)
		return;
	else
	{
		append(value);
	}
}

template<class T>
void CSinglyList<T>::removeFirst(T key)    //ɾ����һ�γ���key�Ľڵ�
{
	CNode<T> * q = this->pHead->pNext;
	CNode<T> * pPre = q;
	for (; q != nullptr ; pPre = q, q = q->pNext)
	{
		if (q->data == key)
		{
			pPre->pNext = q->pNext;  //ɾ���ڵ�
			delete q;                //�ͷſռ�
			return ;
		}
	}
	cout << "δ�ҵ�Ԫ��"<< key<< endl;
}

template<class T>
bool CSinglyList<T>::operator==(CSinglyList<T> & list)   //����==�����
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
bool CSinglyList<T>::operator != (CSinglyList<T> & list)  //����!=�����
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
CSinglyList<T> & CSinglyList<T>::operator=(CSinglyList<T> & list)  //���ظ�ֵ����������
{
	CNode<T> * p = this->pHead->pNext;
	CNode<T> * pPre = p;
	CNode<T> * q = list.pHead->pNext;
	for (; q != nullptr ;pPre=p, p - p->pNext, q = q->pNext)
	{
		if (empty())  //�������Ϊ��
		{
			p = new CNode<T>(q->data);
		}
		else  //�������ǿ�
		{
			if (p != nullptr)   //pָ����һ���ڵ�
				p->data = q->data;
			else   //pָ����nullptr
			{
				p = new CNode<T>(q->data);
				pPre->pNext = p;
			}
		}
	}
	return *this;
}

template<class T>
void CSinglyList<T>::operator+=(CSinglyList<T> & list)    //��list�����ڵ�ǰ����֮��
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