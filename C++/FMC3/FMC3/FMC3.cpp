#include<afxcoll.h>
#include<afxtempl.h>
#include<iostream>
using namespace std;
class A
{
	int age;
public:
	A(){}
	A(int x) :age(x){}
	void operator!(){ cout << age << endl; }
	void operator=(int x){ age = x; }
};
void main()
{
	A *p;
	int l, c[5];
	CArray<A, A> array;
	for (int i = 0; i<5; i++)
	{
		cout << "Please input Age data:";
		cin >> l;
		p = new A(l);
		c[i] = array.Add(*p);//��������ֵ
	}
	cout << "The current total number is " << array.GetSize() << endl << "The second item is ";
	!array.GetAt(c[2]);//���ر�����Ķ���
	array.InsertAt(0, *new A(100), 2);//���������ǰ�˲��������¶���
	cout << "The current total number is " << array.GetSize() << endl << "The second item is ";
	!array[2];
	array[2] = 99;
	cout << "The second item modified is ";
	!array[2];
	cout << flush;
	cin.get();
	cin.get();
	array.RemoveAll();
}
