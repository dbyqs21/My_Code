// ConsoleApplication4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

/*������������������ʵ����ĿҪ��Ĺ���*/
/*��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^ */
/******************************��ʼд����******************************/
double StockGod(int n, int m, double p, const vector<vector<double>>& prices)
{
	double money = 1.0;
	vector<vector<double>> priceOffset;
	for (int k = 0; k < m; ++k)
	{
		for (int k1 = 0; k1 < n; ++k1)
		{
			priceOffset[k].push_back(prices[k + 1][k1] - prices[k + 1][k1]);
		}				
	}

	for (int k = 0; k < m-1; ++k)
	{
		vector<double>::iterator high = max_element(priceOffset[k].begin, priceOffset[k].end);
		
		money = (money / prices[k][high - prices.begin])*prices[k + 1][high - prices.begin] * (1 - p);
	}
	return money;


	//vector<double>::iterator low = min_element(std::begin(prices), std::end(prices));
}
/******************************����д����******************************/


//int main()
//{
//	int n = 0;
//	int m = 0;
//	double p = 0;
//	cin >> n >> m >> p;
//
//	vector<vector<double>> prices;
//	for (int i = 0; i < m; ++i) {
//		prices.push_back(vector<double>());
//		for (int j = 0; j < n; ++j) {
//			double x = 0;
//			cin >> x;
//			prices.back().push_back(x);
//		}
//	}
//
//	double final = StockGod(n, m, p, prices);
//	printf("%.1f\n", final);
//
//	return 0;
//}



int _tmain(int argc, _TCHAR* argv[])
{
	int n = 0;
	int m = 0;
	double p = 0;
	cin >> n >> m >> p;

	vector<vector<double>> prices;
	for (int i = 0; i < m; ++i) {
		prices.push_back(vector<double>());
		for (int j = 0; j < n; ++j) {
			double x = 0;
			cin >> x;
			prices.back().push_back(x);
		}
	}

	double final = StockGod(n, m, p, prices);
	printf("%.1f\n", final);
	return 0;
}

