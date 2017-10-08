#include <iostream>
#include <string.h>
using namespace std;

class CMyString{

	friend ostream & operator<<(ostream & cout, CMyString &str);    //重载输出流<<运算符

private:
	char* element;   //动态字符数组的地址
	int length;   //动态字符数组的长度
	int N;   //串的长度

	void init(char * s = "", int lenght = 32);        //初始化串，参数指定初值和容量
	void getNext(int next[]);      //返回模式串pattern 改进的next数组

public:
	CMyString(char *s = "", int length = 32);    //构造串对象，参数为初值和容量
	CMyString(char ch);   
	CMyString(CMyString & str);
	CMyString & operator=(CMyString & str);       //深拷贝
	CMyString & operator=(char * str);     //支持将字符串常量复制给字符串变量
	~CMyString();

	bool isEmpty();    //判断字符串是否为空
	int count();    //返回有效字符串的长度
	char & operator[](int i);   //支持下标运算
	void printPrevious();   //反序输出
	bool operator==(CMyString &str);
	void reverse();    //将当前的串逆转
	
	CMyString subString(int i, int len);   //返回从第i个字符开始的长度为len的子串
	CMyString subString(int i);     //返回从i开始的子串
	void insert(int i, CMyString &str);    //从第i个位置插入子串
	void insert(int i, char ch);   //插入ch作为第i个字符
	void insert(int i, char* str);   //在第i个字符出插入str串
	void operator+=(CMyString & str);   //在*this之后接入str串
	void operator+=(char *str);    //在*this之后接入字符串str
	void operator+=(char ch);    //在*this之后接入字符ch
	void remove(int i, int len);    //删除从第i个字符开始的长度为len的子串
	void remove(int i);     //删除从第i个字符开始至结尾的所有字符。

	//以下返回从当前串开始，首个与模式串pattern匹配的子串，匹配失败时返回-1
	int search(CMyString & pattern, int start = 0);  //返回从start位置开始查找与模式串pattern匹配的子串位置
	void removeFirst(CMyString & pattern);      //删除第一次与pattern匹配的子串
	void removeAll(CMyString & pattern);     //删除所有与pattern匹配的子串
	void replaceFirst(CMyString & pattern, CMyString & str);    //替换首个与pattern匹配的子串为str
	void replaceAll(CMyString & pattern, CMyString & str);      //将所有与pattern匹配的子串为str
};

/*******************************成员函数的定义*******************************************************/
void CMyString::init(char * s, int lenght)        //初始化串，参数指定初值和容量
{
	this->N = strlen(s);
	this->length = (N * 2) > lenght ? (N * 2) : lenght;
	this->element = new char[this->length];

	for (int k = 0; s[k]!='\0'; ++k)
	{
		this->element[k] = s[k];
	}
	this->element[this->N] = '\0';
}

CMyString::~CMyString()
{
	this->N = 0;
	this->length = 0;
	char * p = this->element;
	this->element = nullptr;
	delete p;
}

CMyString::CMyString(char *s, int length)    //构造串对象，参数为初值和容量
{
	this->init(s, length);
}  

CMyString::CMyString(char ch)
{
	this->init("");
	this->N = 1;
	this->element[0] = ch;
	this->element[1] = '\n';
}

CMyString::CMyString(CMyString & str)
{
	this->init(str.element);
}

CMyString & CMyString::operator=(CMyString & str)       //深拷贝
{
	this->~CMyString();
	this->init(str.element);
	return *this;
}

void CMyString::reverse()    //将当前的串逆转
{
	if (isEmpty())
	{
		cout << "字符串是空的！！" << endl;
	}
	else
	{
		for (int k = 0; k < this->N / 2; ++k)
		{
			char tmp = this->element[k];
			this->element[k] = this->element[N - 1 - k];
			this->element[N - 1 - k] = tmp;
		}
	}
}

ostream & operator<<(ostream & cout, CMyString &str)    //重载输出流<<运算符
{
	cout << "\"" << str.element << "\""<<endl;
	return cout;
}

bool CMyString::isEmpty()    //判断字符串是否为空
{
	return this->N == 0 ? true : false;
}

int CMyString::count()    //返回有效字符串的长度
{
	return this->N;
}

char & CMyString::operator[](int i)   //支持下标运算
{
	if (i >= 0 && i < N)
	{
		return this->element[i];
	}
	else
	{
		throw out_of_range("参数i指定的字符序号超出范围！！");
	}
}

void CMyString::printPrevious()   //反序输出
{
	if (!this->isEmpty())
	{
		for (int k = this->N - 1; k >= 0; --k)
		{
			cout << this->element[k]<<' ';
		}
	}
}

CMyString CMyString::subString(int i, int len)   //返回从第i个字符开始的长度为len的子串
{
	if (i >= 0 && i < this->N && len >= 0)
	{
		if (len > this->N - i)
		{
			len = this->N - i;
		}

		CMyString subStr;
		subStr.N = len;

		for (int k = 0; k < len; ++k)
		{
			subStr.element[k] = this->element[i + k];
		}
		subStr.element[len] = '\0';
		return subStr;
	}
	else
	{
		throw out_of_range("参数i指定的符号或者len超出了范围");
	}
}

CMyString CMyString::subString(int i)    //返回从i开始的子串
{
	return subString(i, this->N - i + 1);
}

void CMyString::insert(int i, CMyString &str)    //从第i个位置插入子串
{
	if (str.N == 0)
		return;

	if (i < 0) i = 0;
	if (i>N) i = N;

	char *tmp = this->element;
	if (this->length < this->N + str.N)   //目标串的存储空间不够
	{
		this->length = (this->N + str.N) * 2;
		this->element = new char(this->length);
		for (int k = 0; k < N; ++k)
		{
			this->element[k] = tmp[k];
		}
	}

	for (int k = this->N; k >= i; --k)  //向后移动子串
	{
		this->element[k + str.N] = this->element[k];
	}
	if (tmp != this->element)  //释放旧空间
		delete tmp;
	for (int k = 0; k < str.N; ++k) // 将str中的元素，拷贝到当前子串中
	{
		this->element[i + k] = str.element[k];
	}
	this->N += str.N;
}

void CMyString::insert(int i, char ch)   //插入ch作为第i个字符
{
	this->insert(i, CMyString(ch));
}

void CMyString::insert(int i, char* str)   //在第i个字符出插入str串
{
	this->insert(i, CMyString(str));
}

void CMyString::operator+=(CMyString & str)   //在*this之后接入str串
{
	this->insert(this->N, str);
}

void CMyString::operator+=(char *str)    //在*this之后接入字符串str
{
	this->insert(this->N, str);
}

void CMyString::operator+=(char ch)    //在*this之后接入字符ch
{
	this->insert(this->N, ch);
}

void CMyString::remove(int i, int len)    //删除从第i个字符开始的长度为len的子串
{
	if (i < 0) i = 0;
	if (i>N)  return;

	if (i + len > N)
	{
		this->element[i] = '\0';
		this->N = i;
	}
	else
	{
		for (int k = 0; k < len; ++k)
		{
			this->element[i + k] = this->element[i + k + len];
			if (this->element[i + k + len] == '\0')
			{
				this->N = i + k-1;
				break;
			}
		}
	}
}

void CMyString::remove(int i)     //删除从第i个字符开始至结尾的所有字符。
{
	if (i < 0) i = 0;
	if (i < this->N)
	{
		this->element[i]='\0';
		this->N = N - i+1;
	}
}


void CMyString::getNext(int next[])     //返回模式串pattern 改进的next数组
{
	next[0] = -1;
	int j = 0;
	int k = -1;
	while (j < (this -> N - 1))
	{
		if ( (-1 == k)||element[j] == element[k])
		{
			j++;
			k++;
			//next[j] = k;    //有待改进
			if (element[j] != element[k])   //改进之处
			{
				next[j] = k;
			}
			else
			{
				next[j] = next[k];
			}

		}
		else
		{
			k = next[k];
		}
	}
}

int CMyString::search(CMyString & pattern, int start)  //返回从start位置开始查找与模式串pattern匹配的子串位置
{

	//KMP算法
	int * next = new int(pattern.N);
	pattern.getNext(next);
	int i = start;
	int j = 0;
	while (i < this->N)
	{
		if (j == -1 || this->element[i] == pattern.element[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
		if (j == pattern.N)
		{
			return i - j;
		}
	}
	return -1;

	//Brute-Force 算法
	/*int i = start;
	int j = 0;

	while (i < this->N)
	{
		if (this->element[i] == pattern[i])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
		if (j == pattern.N)
			return i - j;
	}
	return -1;*/
}

void CMyString::removeFirst(CMyString & pattern)      //删除第一次与pattern匹配的子串
{
	int k = search(pattern);
	if (-1 != k)
	{
		this->remove(k, pattern.N);
	}
}

void CMyString::removeAll(CMyString & pattern)     //删除所有与pattern匹配的子串
{
	int k = search(pattern);
	while (-1 != k)
	{
		this->remove(k, pattern.N);
		k = search(pattern);
	}
}

void CMyString::replaceFirst(CMyString & pattern, CMyString & str)    //替换首个与pattern匹配的子串为str
{
	int k = search(pattern);
	if (-1 != k)
	{
		this->remove(k, pattern.N);
		this->insert(k, str);
	}
}

void CMyString::replaceAll(CMyString & pattern, CMyString & str)      //将所有与pattern匹配的子串为str
{
	int k = search(pattern);
	while (-1 != k)
	{
		this->remove(k, pattern.N);
		this->insert(k, str);
		k = search(pattern);
	}
}







