// ConsoleApplication7.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "Ploynomial_.h"
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	ploy Headl;
	ploy Headr;

	Headl = ReadPloynomial(Headl);
	printNode(Headl);
	Headr = ReadPloynomial(Headr);
	printNode(Headr);
	
	//����ӷ�
	ploy Sum;
	Sum= ployAdd(Sum, Headl, Headr);
	cout << "����ʽ�ĺ�Ϊ��";
	printNode(Sum);
	//����˷�
	ploy Mult;
	Mult= ployMult(Mult, Headl, Headr);
	cout << "����ʽ�Ļ�Ϊ��";
	printNode(Mult);


	system("pause");
	return 0;
}

