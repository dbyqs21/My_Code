// ConsoleApplication3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


//void method(string &s, string &oldVal, string &newVal);

int _tmain(int argc, _TCHAR* argv[])
{
	ostream_iterator<int> out_iter(cout, "是个傻逼 ");
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	auto ta = find(vec.begin(), vec.end(),3);
	cout << *ta << endl;
	for (auto e : vec)
	{
		*out_iter++ = e;
	}

	
	/*string s = "some string ";
	string s2 = "some other string ";
	s.insert(0, s2);
	cout << s << endl;
	string s3 = "hellow";
	method(s, s2, s3);*/
	system("pause");
	return 0;
}

//void method(string &s, string &oldVal, string &newVal)
//{
//	cout << s << endl;
//	s.insert(s.begin, oldVal);
//	cout << s << endl;
//}