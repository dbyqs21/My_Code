#include <iostream>
#include <exception>
using namespace std;

template<class T>
class CSeqList{
public :
	friend ostream& operator<< <>(ostream&, CSeqList<T>&);   //����б�����Ԫ��

protected:
	T *element;   //ָ������洢˳��������Ԫ��
	size_t length;   //˳������������
	size_t n;        //˳�����Ԫ�صĸ���

private:
	void init(T values[], size_t n);

public:
	CSeqList(size_t length = 32);  //��һ��Ĭ��ֵ�Ĺ��캯��
	CSeqList(size_t length, T x);  //����˳���length��Ԫ����x��ʼ��
	CSeqList(T values[], size_t n); //����˳�����values�ṩ����
	~CSeqList();                 //��������

	bool empty();   //�ж�˳����Ƿ�Ϊ��
	size_t count();    //����˳�����Ԫ�صĸ���
	T& operator[](size_t i);  //�����±������
	void printPrevious();     //�������˳���
	void insert(size_t i, T x);  //����Ԫ��
	virtual void appendx(T x);    //��˳����������Ԫ��
	T remove(size_t i);          //ɾ����i��Ԫ�أ����ر�ɾ����Ԫ��
	void removeAll();            //ɾ������Ԫ��
	virtual size_t search(T key, size_t start = 0);   // ��start��ʼ����keyԪ�ء����ز��ҵ���Ԫ�����
	virtual void removeFirst(T key);   //ɾ���״γ��ֹؼ���Ϊkey��Ԫ�أ��麯��

	CSeqList(CSeqList<T> &List);      //�������캯��
	CSeqList<T> & operator=(CSeqList<T> &list);    //���ؿ��������

	bool operator==(CSeqList<T> &list);            //��������ж������
	bool operator!=(CSeqList<T> &list);            //���ز����ж������
	void operator+=(CSeqList<T> &list);            //���ؼӺŸ��������
	CSeqList<T> operator+(CSeqList<T> &list);      //���ؼӺ������

};

/***********���Ա��ʵ��**********/
template<class T>
CSeqList<T>::CSeqList(size_t length)
{
	this->element = new T[length];
	this->length = length;
	this->n = 0;
}

template<class T>
CSeqList<T>::CSeqList(size_t length,T x)
{
	this->element = new T[length];
	this->length = length;
	this->n = length;
	for (int i = 0; i < length; ++i)
	{
		this->element[i] = x;
	}
}

template<class T>
CSeqList<T>::CSeqList(T values[], size_t n)
{
	this->init(values, n);
}

template<class T>
void CSeqList<T>::init(T values[], size_t n)        //��ʼ��˳���
{
	this->length = 2 * n;
	this->element = new T[this->length];
	this->n = n;
	for (int i = 0; i < n; ++i)
	{
		this->element[i] = values[i];
	}
}

template<class T>
CSeqList<T>::~CSeqList()
{
	delete []this->element;
}


template<class T>
bool CSeqList<T>::empty()      //����˳����Ƿ�Ϊ��
{
	return this->n == 0;
}


template<class T>
size_t CSeqList<T>::count()     //����˳�����Ԫ�صĸ���
{
	return this->n;
}

template<class T>
T&  CSeqList<T>:: operator[](size_t i)  //�����±������
{
	if (i >= 0 && i < this->n)
	{
		return this->element[i];
	}
	throw out_of_range("�±곬����ЧԪ�����ڷ�Χ");
}


template<class T>
ostream& operator<< <>(ostream& cout, CSeqList<T>& list)   //����б�����Ԫ��
{
	cout << "(";
	if (list.n > 0)
	{
		cout << list.element[0];
		for (size_t i = 1; i < list.n; ++i)
		{
			cout << "," << list.element[i];
		}
		cout << ")" << endl;
	}
	return cout;
}


template<class T>
void CSeqList<T>::insert(size_t i, T x)  //����Ԫ��
{
	if (i < 0) i = 0;
	if (i>this->n) i = this->n;

	T * temp = this->element;
	//�ж�˳����Ƿ�����
	if (this->n == this->length)
	{
		this->length *= 2;
		this->element = new T[this->length];
		for (size_t j = 0; j < i; ++j)
		{
			this->element[j] = temp[j];     //��������i-1��Ԫ��
		}
	}

	for (size_t j = this->n; j>0 && j >= i; --j)  //��i��i֮���Ԫ�غ�Ųһλ
	{
		this->element[j] = temp[j-1];
	}

	if (temp != this->element)   //�ж��Ƿ����·����˿ռ�
	{
		delete[]temp;
	}

	this->element[i] = x;     //����
	this->n++;
}


template<class T>
void CSeqList<T>::appendx(T x)    //��˳����ĩβ����һ��Ԫ��
{
	insert(this->n, x);
}


template<class T>
T CSeqList<T>::remove(size_t i)    //��˳�����ɾ����i����Ԫ��
{
	if (this->n > 0 && i >= 0 && i < this->n)
	{
		T old = this->element[i];
		for (size_t j = i; j < this->n-1; ++j)
			this->element[j] = this->element[j + 1];
		this->n--;
		return old;
	}
	throw out_of_range("Ҫɾ����Ԫ�ز�����ЧԪ�ط�Χ");
}

template<class T>
void CSeqList<T>::removeAll()    //��˳���������Ԫ��
{
	this->n = 0;
}

template<class T>
size_t CSeqList<T>::search(T key,size_t start=0)    //��˳������Ԫ��
{
	if (this->n > 0 && start >= 0 && start < this->n)
	{
		for (size_t j = 0; j < this->n; ++j)
		{
			if (this->element[j] == key)
			{
				return j;
			}
		}
	}
	return this->n;
}

template<class T>
void CSeqList<T>::removeFirst(T key)   //ɾ���״γ��ֹؼ���Ϊkey��Ԫ�أ��麯��
{
	remove(search(key,0));
}

template<class T>
bool CSeqList<T>::operator==(CSeqList<T> &list)            //��������ж������
{
	if (this->n == list->n)
	{
		for (size_t i = 0; i < this->n; ++i)
		{
			if (this->element[i] != list->element[i])
				return false;
		}
		return true;
	}
	return false;
}

template<class T>
bool CSeqList<T>::operator!=(CSeqList<T> &list)            //��������ж������
{
	return !(this->operator==(list));
}

template<class T>
CSeqList<T> CSeqList<T>::operator+(CSeqList<T> &list)      //���ؼӺ������
{
	if (this - n + list->n > this->length)
	{
		T * temp = this->element;
		this->length += list->length;
		this->element = new T[this->length];

		for (size_t i = 0; i < this->n; ++i)
		{
			this->element[i] = temp[i];
		}
	}

	for (size_t i = this->n; i < this->n + list->n; ++i)
	{
		this->element[i] = list->element[i - this->n];
	}
	this->n += list->n;
	return *this;
}

template<class T>
void CSeqList<T>::operator+=(CSeqList<T> &list)           //���ؼӺŸ��������
{
	return this->operator+(list);
}