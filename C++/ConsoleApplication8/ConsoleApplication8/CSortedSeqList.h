#include "CSeqLis.h"

template<class T>
class CSortedSeqList :public CSeqList<T>{
public:
	CSortedSeqList(){}            //����յ�����˳���
	CSortedSeqList(T values[], size_t n);    //������values�ṩ��������������˳���
	CSortedSeqList(CSeqList<T> &list);       //�������캯������˳�������������˳���

	size_t search(T key, size_t start = 0);   //���ǻ�����Һ���
	void insert(T x);        //����Ԫ�صĴ�С������Ԫ��
	void removeFirst(T key);      //ɾ��ͷԪ��
	void insertUnrepeatable(T x);     //���벻�ظ���Ԫ��

	//ostream & operator<< <>(ostream &,CSortedSeqList<T> &);
};

/***********************��ĳ�Ա�����Ķ���**********************************/
template<class T>
CSortedSeqList<T>::CSortedSeqList(T values[], size_t n):CSeqList(n*2)    //������values�ṩ��������������˳���
{
	for (size_t i = 0; i < n; ++i)
	{
		this->insert(values[i]);
	}
}

template<class T>
CSortedSeqList<T>::CSortedSeqList(CSeqList<T> &list):CSeqList(2 * list->length)       //�������캯������˳�������������˳���
{
	for (size_t i = 0; i < n; ++i)
	{
		this->insert(list->element[i]);
	}
}

template<class T>
void CSortedSeqList<T>::insert(T x)        //����Ԫ�صĴ�С������Ԫ��
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
void CSortedSeqList<T>::removeFirst(T key)      //ɾ��ͷԪ��
{
	CSeqList<T>::removeFirst(key);
}

template<class T>
void CSortedSeqList<T>::insertUnrepeatable(T x)     //���벻�ظ���Ԫ��
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
size_t CSortedSeqList<T>::search(T key, size_t start = 0)   //���ǻ�����Һ���
{
	return CSeqList<T>::search(key, start);
}

