#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<pair<int, int>>  ploy;
typedef pair<int, int> Node;
//按从小到大的方式插入链表
ploy  insertNode(ploy & Head, Node & pNewNode)
{

	ploy q = Head;
	//如果仅有头结点
	if (Head.size == 0)
	{
		Head.push_back(pNewNode);
		return Head;
	}
	// 如果有一个以及一个以上数据节点
	for (auto p = Head.begin; p != Head.end; ++p)
	{
		if (Head.at(p).first > pNewNode.first)
		{
			Head.insert(p - 1, pNewNode);
		}

		//如果节点指数相等
		if (Head.at(p).first == pNewNode.first)
		{
			Head.at(p).second += pNewNode.second;
			return Head;
		}
		//如果遇到尾节点
		if (p + 1 == Head.end)
		{
			Head.push_back(pNewNode);
			return Head;
		}
	}

	return Head;
}

//读入多项式
ploy  ReadPloynomial(ploy & Head)
{
	cout << "请输入多项式的项数以及对应各项的系数和指数：" << endl;
	int N = 0;
	if (cin >> N)
	{
		while (N--)
		{
			int coef = 0;
			int index = 0;
			if (cin >> coef && cin>> index)
			{
				//将节点加入链表
				Head.push_back(pair<int, int>(index, coef));
			}
		}
	}
	sort(Head.begin, Head.end);
	return Head;
}

//输出节点内容
void printNode(ploy & Head)
{
	for (auto node:Head)
	{
		cout << node.second << " " <<node.first << " ";
	}
	cout << endl;
}

//计算多项式的和
ploy  ployAdd(ploy & Sum, ploy  & Headl, ploy & Headr)
{
	//创建多项式的和的头结点
	auto p = Headl.begin;
	auto q = Headr.begin;
	//计算多项式的和
	for (; p != Headl.end && q != Headr.end; ++p)
	{
		if (Headl.at(p).first < Headr.at(q).first)
		{
			Sum = insertNode(Sum, p);
		}
		else if (Headl.at(p).first > Headr.at(q).first)
		{
			Sum = insertNode(Sum, Headr.at(q));
			q++;
		}
		else
		{
			Sum.push_back(Node(Headl.at(p).first, Headl.at(p).second + Headl.at(q).second));
			q++;
		}
	}

	//把没有参与计算的多项式节点复制到和多项式节点中
	while (p != Headl.end)
	{
		Sum.push_back(Node(Headl.at(p).first, Headl.at(p).second));
		p++;
	}

	while (q != Headr.end)
	{
		Sum.push_back(Node(Headr.at(q).first, Headr.at(q).second));
		q++;
	}
	return Sum;
}

//计算多项式的积
ploy & ployMult(ploy & Mult, ploy & Headl, ploy & Headr)
{
	for (auto p : Headl)
	{
		for (auto q : Headr)
		{
			Mult = insertNode(Mult, Node(Headl.at(p).first + Headr.at(q).first, Headl.at(p).second * Headr.at(q).second));
		}
	}
	return Mult;
}