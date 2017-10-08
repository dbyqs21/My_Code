// ConsoleApplication7.cpp : 定义控制台应用程序的入口点。
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
	
	//计算加法
	ploy Sum;
	Sum= ployAdd(Sum, Headl, Headr);
	cout << "多项式的和为：";
	printNode(Sum);
	//计算乘法
	ploy Mult;
	Mult= ployMult(Mult, Headl, Headr);
	cout << "多项式的积为：";
	printNode(Mult);


	system("pause");
	return 0;
}

