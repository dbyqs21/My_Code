#include <iostream>
#include <exception>
using namespace std;

template<class T>
class CSeqList{
public :
	friend ostream& operator<< <>(ostream&, CSeqList<T>&);   //输出列表所有元素

protected:
	T *element;   //指动数组存储顺序表的数据元素
	size_t length;   //顺序表的数组容量
	size_t n;        //顺序表中元素的个数

private:
	void init(T values[], size_t n);

public:
	CSeqList(size_t length = 32);  //有一个默认值的构造函数
	CSeqList(size_t length, T x);  //构造顺序表，length个元素由x初始化
	CSeqList(T values[], size_t n); //构造顺序表，由values提供数据
	~CSeqList();                 //析构函数

	bool empty();   //判断顺序表是否为空
	size_t count();    //返回顺序表中元素的个数
	T& operator[](size_t i);  //重载下标运算符
	void printPrevious();     //反向输出顺序表
	void insert(size_t i, T x);  //插入元素
	virtual void appendx(T x);    //在顺序表的最后插入元素
	T remove(size_t i);          //删除第i个元素，返回被删除的元素
	void removeAll();            //删除所有元素
	virtual size_t search(T key, size_t start = 0);   // 从start开始查找key元素。返回查找到的元素序号
	virtual void removeFirst(T key);   //删除首次出现关键字为key的元素，虚函数

	CSeqList(CSeqList<T> &List);      //拷贝构造函数
	CSeqList<T> & operator=(CSeqList<T> &list);    //重载拷贝运算符

	bool operator==(CSeqList<T> &list);            //重载相等判断运算符
	bool operator!=(CSeqList<T> &list);            //重载不等判断运算符
	void operator+=(CSeqList<T> &list);            //重载加号复合运算符
	CSeqList<T> operator+(CSeqList<T> &list);      //重载加号运算符

};

/***********类成员的实现**********/
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
void CSeqList<T>::init(T values[], size_t n)        //初始化顺序表
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
bool CSeqList<T>::empty()      //返回顺序表是否为空
{
	return this->n == 0;
}


template<class T>
size_t CSeqList<T>::count()     //返回顺序表中元素的个数
{
	return this->n;
}

template<class T>
T&  CSeqList<T>:: operator[](size_t i)  //重载下标运算符
{
	if (i >= 0 && i < this->n)
	{
		return this->element[i];
	}
	throw out_of_range("下标超出有效元素所在范围");
}


template<class T>
ostream& operator<< <>(ostream& cout, CSeqList<T>& list)   //输出列表所有元素
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
void CSeqList<T>::insert(size_t i, T x)  //插入元素
{
	if (i < 0) i = 0;
	if (i>this->n) i = this->n;

	T * temp = this->element;
	//判断顺序表是否已满
	if (this->n == this->length)
	{
		this->length *= 2;
		this->element = new T[this->length];
		for (size_t j = 0; j < i; ++j)
		{
			this->element[j] = temp[j];     //复制数组i-1个元素
		}
	}

	for (size_t j = this->n; j>0 && j >= i; --j)  //将i及i之后的元素后挪一位
	{
		this->element[j] = temp[j-1];
	}

	if (temp != this->element)   //判断是否重新分配了空间
	{
		delete[]temp;
	}

	this->element[i] = x;     //插入
	this->n++;
}


template<class T>
void CSeqList<T>::appendx(T x)    //在顺序表的末尾插入一个元素
{
	insert(this->n, x);
}


template<class T>
T CSeqList<T>::remove(size_t i)    //在顺序表中删除第i个个元素
{
	if (this->n > 0 && i >= 0 && i < this->n)
	{
		T old = this->element[i];
		for (size_t j = i; j < this->n-1; ++j)
			this->element[j] = this->element[j + 1];
		this->n--;
		return old;
	}
	throw out_of_range("要删除的元素不在有效元素范围");
}

template<class T>
void CSeqList<T>::removeAll()    //在顺序表中所有元素
{
	this->n = 0;
}

template<class T>
size_t CSeqList<T>::search(T key,size_t start=0)    //在顺序表查找元素
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
void CSeqList<T>::removeFirst(T key)   //删除首次出现关键字为key的元素，虚函数
{
	remove(search(key,0));
}

template<class T>
bool CSeqList<T>::operator==(CSeqList<T> &list)            //重载相等判断运算符
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
bool CSeqList<T>::operator!=(CSeqList<T> &list)            //重载相等判断运算符
{
	return !(this->operator==(list));
}

template<class T>
CSeqList<T> CSeqList<T>::operator+(CSeqList<T> &list)      //重载加号运算符
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
void CSeqList<T>::operator+=(CSeqList<T> &list)           //重载加号复合运算符
{
	return this->operator+(list);
}