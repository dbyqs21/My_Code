 //ConsoleApplication9.cpp : 定义控制台应用程序的入口点。


#include "stdafx.h"
#include <utility>
#include <iostream>
using namespace std;


double distance(pair<double, double> A, pair<double, double> B)
{
	if (A.first > B.first)
		return distance(B, A);

	if (B.first >= A.second)  // 没有交集
		return 0;
	else if (B.second <= A.second)   //B在A内
	{
		return B.second - B.first;
	}
	else    //A和B只相交了一部分
	{
		return A.second - B.first;
	}
}

double mixArea(pair<double, double> Au, pair<double, double> Ab, pair<double, double> Bu, pair<double, double> Bb)
{
	double width = distance(make_pair(Au.first, Ab.first), make_pair(Bu.first, Bb.first));
	double height = distance(make_pair(Au.second, Ab.second), make_pair(Bu.second, Bb.second));
	return width*height;
}

int _tmain(int argc, _TCHAR* argv[])
{
	pair<double, double> Au = { 1.0, 2.0 };
	pair<double, double> Ab = { 2.0, 1.0 };
	pair<double, double> Bu = { 1.5, 3.0 };
	pair<double, double> Bb = { 3.0, 5.0 };

	cout << mixArea(Au, Ab, Bu, Bb)<<endl;

	return 0;
}


