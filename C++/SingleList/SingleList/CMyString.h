#include <iostream>
#include <string.h>
using namespace std;

class CMyString{

	friend ostream & operator<<(ostream & cout, CMyString &str);    //���������<<�����

private:
	char* element;   //��̬�ַ�����ĵ�ַ
	int length;   //��̬�ַ�����ĳ���
	int N;   //���ĳ���

	void init(char * s = "", int lenght = 32);        //��ʼ����������ָ����ֵ������
	void getNext(int next[]);      //����ģʽ��pattern �Ľ���next����

public:
	CMyString(char *s = "", int length = 32);    //���촮���󣬲���Ϊ��ֵ������
	CMyString(char ch);   
	CMyString(CMyString & str);
	CMyString & operator=(CMyString & str);       //���
	CMyString & operator=(char * str);     //֧�ֽ��ַ����������Ƹ��ַ�������
	~CMyString();

	bool isEmpty();    //�ж��ַ����Ƿ�Ϊ��
	int count();    //������Ч�ַ����ĳ���
	char & operator[](int i);   //֧���±�����
	void printPrevious();   //�������
	bool operator==(CMyString &str);
	void reverse();    //����ǰ�Ĵ���ת
	
	CMyString subString(int i, int len);   //���شӵ�i���ַ���ʼ�ĳ���Ϊlen���Ӵ�
	CMyString subString(int i);     //���ش�i��ʼ���Ӵ�
	void insert(int i, CMyString &str);    //�ӵ�i��λ�ò����Ӵ�
	void insert(int i, char ch);   //����ch��Ϊ��i���ַ�
	void insert(int i, char* str);   //�ڵ�i���ַ�������str��
	void operator+=(CMyString & str);   //��*this֮�����str��
	void operator+=(char *str);    //��*this֮������ַ���str
	void operator+=(char ch);    //��*this֮������ַ�ch
	void remove(int i, int len);    //ɾ���ӵ�i���ַ���ʼ�ĳ���Ϊlen���Ӵ�
	void remove(int i);     //ɾ���ӵ�i���ַ���ʼ����β�������ַ���

	//���·��شӵ�ǰ����ʼ���׸���ģʽ��patternƥ����Ӵ���ƥ��ʧ��ʱ����-1
	int search(CMyString & pattern, int start = 0);  //���ش�startλ�ÿ�ʼ������ģʽ��patternƥ����Ӵ�λ��
	void removeFirst(CMyString & pattern);      //ɾ����һ����patternƥ����Ӵ�
	void removeAll(CMyString & pattern);     //ɾ��������patternƥ����Ӵ�
	void replaceFirst(CMyString & pattern, CMyString & str);    //�滻�׸���patternƥ����Ӵ�Ϊstr
	void replaceAll(CMyString & pattern, CMyString & str);      //��������patternƥ����Ӵ�Ϊstr
};

/*******************************��Ա�����Ķ���*******************************************************/
void CMyString::init(char * s, int lenght)        //��ʼ����������ָ����ֵ������
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

CMyString::CMyString(char *s, int length)    //���촮���󣬲���Ϊ��ֵ������
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

CMyString & CMyString::operator=(CMyString & str)       //���
{
	this->~CMyString();
	this->init(str.element);
	return *this;
}

void CMyString::reverse()    //����ǰ�Ĵ���ת
{
	if (isEmpty())
	{
		cout << "�ַ����ǿյģ���" << endl;
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

ostream & operator<<(ostream & cout, CMyString &str)    //���������<<�����
{
	cout << "\"" << str.element << "\""<<endl;
	return cout;
}

bool CMyString::isEmpty()    //�ж��ַ����Ƿ�Ϊ��
{
	return this->N == 0 ? true : false;
}

int CMyString::count()    //������Ч�ַ����ĳ���
{
	return this->N;
}

char & CMyString::operator[](int i)   //֧���±�����
{
	if (i >= 0 && i < N)
	{
		return this->element[i];
	}
	else
	{
		throw out_of_range("����iָ�����ַ���ų�����Χ����");
	}
}

void CMyString::printPrevious()   //�������
{
	if (!this->isEmpty())
	{
		for (int k = this->N - 1; k >= 0; --k)
		{
			cout << this->element[k]<<' ';
		}
	}
}

CMyString CMyString::subString(int i, int len)   //���شӵ�i���ַ���ʼ�ĳ���Ϊlen���Ӵ�
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
		throw out_of_range("����iָ���ķ��Ż���len�����˷�Χ");
	}
}

CMyString CMyString::subString(int i)    //���ش�i��ʼ���Ӵ�
{
	return subString(i, this->N - i + 1);
}

void CMyString::insert(int i, CMyString &str)    //�ӵ�i��λ�ò����Ӵ�
{
	if (str.N == 0)
		return;

	if (i < 0) i = 0;
	if (i>N) i = N;

	char *tmp = this->element;
	if (this->length < this->N + str.N)   //Ŀ�괮�Ĵ洢�ռ䲻��
	{
		this->length = (this->N + str.N) * 2;
		this->element = new char(this->length);
		for (int k = 0; k < N; ++k)
		{
			this->element[k] = tmp[k];
		}
	}

	for (int k = this->N; k >= i; --k)  //����ƶ��Ӵ�
	{
		this->element[k + str.N] = this->element[k];
	}
	if (tmp != this->element)  //�ͷžɿռ�
		delete tmp;
	for (int k = 0; k < str.N; ++k) // ��str�е�Ԫ�أ���������ǰ�Ӵ���
	{
		this->element[i + k] = str.element[k];
	}
	this->N += str.N;
}

void CMyString::insert(int i, char ch)   //����ch��Ϊ��i���ַ�
{
	this->insert(i, CMyString(ch));
}

void CMyString::insert(int i, char* str)   //�ڵ�i���ַ�������str��
{
	this->insert(i, CMyString(str));
}

void CMyString::operator+=(CMyString & str)   //��*this֮�����str��
{
	this->insert(this->N, str);
}

void CMyString::operator+=(char *str)    //��*this֮������ַ���str
{
	this->insert(this->N, str);
}

void CMyString::operator+=(char ch)    //��*this֮������ַ�ch
{
	this->insert(this->N, ch);
}

void CMyString::remove(int i, int len)    //ɾ���ӵ�i���ַ���ʼ�ĳ���Ϊlen���Ӵ�
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

void CMyString::remove(int i)     //ɾ���ӵ�i���ַ���ʼ����β�������ַ���
{
	if (i < 0) i = 0;
	if (i < this->N)
	{
		this->element[i]='\0';
		this->N = N - i+1;
	}
}


void CMyString::getNext(int next[])     //����ģʽ��pattern �Ľ���next����
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
			//next[j] = k;    //�д��Ľ�
			if (element[j] != element[k])   //�Ľ�֮��
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

int CMyString::search(CMyString & pattern, int start)  //���ش�startλ�ÿ�ʼ������ģʽ��patternƥ����Ӵ�λ��
{

	//KMP�㷨
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

	//Brute-Force �㷨
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

void CMyString::removeFirst(CMyString & pattern)      //ɾ����һ����patternƥ����Ӵ�
{
	int k = search(pattern);
	if (-1 != k)
	{
		this->remove(k, pattern.N);
	}
}

void CMyString::removeAll(CMyString & pattern)     //ɾ��������patternƥ����Ӵ�
{
	int k = search(pattern);
	while (-1 != k)
	{
		this->remove(k, pattern.N);
		k = search(pattern);
	}
}

void CMyString::replaceFirst(CMyString & pattern, CMyString & str)    //�滻�׸���patternƥ����Ӵ�Ϊstr
{
	int k = search(pattern);
	if (-1 != k)
	{
		this->remove(k, pattern.N);
		this->insert(k, str);
	}
}

void CMyString::replaceAll(CMyString & pattern, CMyString & str)      //��������patternƥ����Ӵ�Ϊstr
{
	int k = search(pattern);
	while (-1 != k)
	{
		this->remove(k, pattern.N);
		this->insert(k, str);
		k = search(pattern);
	}
}







