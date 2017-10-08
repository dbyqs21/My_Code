#include <iostream>
#include "CMyString.h"
using namespace std;


int main()
{
	CMyString string1 = "hellow Andy!!";
	cout << string1;

	//string1.insert(0, "$$$$$");
	//cout << string1;

	string1.replaceFirst(CMyString("Andy"), CMyString("^^^^^"));
	cout << string1;
	system("pause");
	return 0;
}


//int main1()
//{
//	int A[] = { 10, 2, 3, 4, 5, 6 };
//	CSinglyList<int> singlylist(A,sizeof(A)/sizeof(A[0]));
//	cout << singlylist<<endl;
//	singlylist.insert(0, 7);
//	cout << singlylist << endl;
//	CSinglyList<int> singlylist2;
//	singlylist2.append(5);
//	cout << singlylist2 << endl;
//	//singlylist += singlylist2;
//	cout << singlylist << endl;
//	singlylist.set(0, 111);
//	cout << singlylist << endl;
//	
//	if (singlylist != singlylist2)
//		cout << "不等" << endl;
//	cout << "singlylist2 "<< singlylist2 << endl;
//	CSinglyList<int> singlylist3;
//	singlylist3 = singlylist2;
//
//	if (singlylist3 == singlylist2)
//		cout << "相等" << endl;
//
//	singlylist.removeFirst(4);
//	cout << singlylist << endl;
//
//	CSortedSinglyList<int> sortedList(A, sizeof(A) / sizeof(A[0]));
//	cout << sortedList << endl;
//
//	system("pause");
//	return 0;
//}
