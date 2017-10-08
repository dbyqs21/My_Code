#include <iostream>
#include <iomanip>
using namespace std;

/*
class C
{
public :
	C(int i) :m_Count(i){}
	int incr() const
	{
		return ++m_Count;
	}
	int decr() const
	{
		return--m_Count;
	}

private:
	mutable int m_Count;
};

int main()
{
	C c1(0), c2(10);
	for (int tmp, i = 0; i < 10; i++)
	{
		tmp = c1.incr();
		cout << setw(tmp) << setfill(' ') << tmp << endl;
		tmp = c2.decr();
        cout << setw(tmp) << setfill(' ') << tmp << endl;

	}
	return 0;
}
*/

#include <iostream>
using namespace std;

class A
{
	int a;
	int j;
	char k;
};

void main()
{
	cout << sizeof(A) << endl;

}