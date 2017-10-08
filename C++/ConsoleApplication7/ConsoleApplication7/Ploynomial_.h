#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<pair<int, int>>  ploy;
typedef pair<int, int> Node;
//����С����ķ�ʽ��������
ploy  insertNode(ploy & Head, Node & pNewNode)
{

	ploy q = Head;
	//�������ͷ���
	if (Head.size == 0)
	{
		Head.push_back(pNewNode);
		return Head;
	}
	// �����һ���Լ�һ���������ݽڵ�
	for (auto p = Head.begin; p != Head.end; ++p)
	{
		if (Head.at(p).first > pNewNode.first)
		{
			Head.insert(p - 1, pNewNode);
		}

		//����ڵ�ָ�����
		if (Head.at(p).first == pNewNode.first)
		{
			Head.at(p).second += pNewNode.second;
			return Head;
		}
		//�������β�ڵ�
		if (p + 1 == Head.end)
		{
			Head.push_back(pNewNode);
			return Head;
		}
	}

	return Head;
}

//�������ʽ
ploy  ReadPloynomial(ploy & Head)
{
	cout << "���������ʽ�������Լ���Ӧ�����ϵ����ָ����" << endl;
	int N = 0;
	if (cin >> N)
	{
		while (N--)
		{
			int coef = 0;
			int index = 0;
			if (cin >> coef && cin>> index)
			{
				//���ڵ��������
				Head.push_back(pair<int, int>(index, coef));
			}
		}
	}
	sort(Head.begin, Head.end);
	return Head;
}

//����ڵ�����
void printNode(ploy & Head)
{
	for (auto node:Head)
	{
		cout << node.second << " " <<node.first << " ";
	}
	cout << endl;
}

//�������ʽ�ĺ�
ploy  ployAdd(ploy & Sum, ploy  & Headl, ploy & Headr)
{
	//��������ʽ�ĺ͵�ͷ���
	auto p = Headl.begin;
	auto q = Headr.begin;
	//�������ʽ�ĺ�
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

	//��û�в������Ķ���ʽ�ڵ㸴�Ƶ��Ͷ���ʽ�ڵ���
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

//�������ʽ�Ļ�
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