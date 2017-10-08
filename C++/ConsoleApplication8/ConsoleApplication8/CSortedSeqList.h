#include "CSeqLis.h"

template<class T>
class CSortedSeqList :public CSeqList<T>{
public:
	CSortedSeqList(){}            //构造空的排序顺序表
	CSortedSeqList(T values[], size_t n);    //有数组values提供数据来构造排序顺序表
	CSortedSeqList(CSeqList<T> &list);       //拷贝构造函数，由顺序表来构造排序顺序表

	size_t search(T key, size_t start = 0);   //覆盖基类查找函数
	void insert(T x);        //根据元素的大小来插入元素
	void removeFirst(T key);      //删除头元素
	void insertUnrepeatable(T x);     //插入不重复的元素

	//ostream & operator<< <>(ostream &,CSortedSeqList<T> &);
};

/***********************类的成员函数的定义**********************************/
template<class T>
CSortedSeqList<T>::CSortedSeqList(T values[], size_t n):CSeqList(n*2)    //有数组values提供数据来构造排序顺序表
{
	for (size_t i = 0; i < n; ++i)
	{
		this->insert(values[i]);
	}
}

template<class T>
CSortedSeqList<T>::CSortedSeqList(CSeqList<T> &list):CSeqList(2 * list->length)       //拷贝构造函数，由顺序表来构造排序顺序表
{
	for (size_t i = 0; i < n; ++i)
	{
		this->insert(list->element[i]);
	}
}

template<class T>
void CSortedSeqList<T>::insert(T x)        //根据元素的大小来插入元素
{
	if (this->n == 0)
	{
		this->appendx(x);
		return;
	}
	else
	{
		for (size_t i = 0; i < this->n; ++i)
		{
			if (this->element[i]>x)
			{
				CSeqList<T>::insert(i, x);
				return;
			}
		}
		CSeqList<T>::appendx(x);
	}
}

template<class T>
void CSortedSeqList<T>::removeFirst(T key)      //删除头元素
{
	CSeqList<T>::removeFirst(key);
}

template<class T>
void CSortedSeqList<T>::insertUnrepeatable(T x)     //插入不重复的元素
{
	if (this->n == 0)
	{
		this->appendx(x);
	}
	else
	{
		for (sizt_t i = 0; i < this->n; ++i)
		{
			if (this->element[i] == x)
				return;

			if (this->element[i]>x)
			{
				insert(i, x);
			}
		}
	}
}

template<class T>
size_t CSortedSeqList<T>::search(T key, size_t start = 0)   //覆盖基类查找函数
{
	return CSeqList<T>::search(key, start);
}

