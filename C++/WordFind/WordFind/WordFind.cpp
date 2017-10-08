// WordFind.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <memory>
#include <set>
#include <sstream>
using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending);

class QuerResult{
	friend ostream & print(ostream &os, const QuerResult &qr);
public:
	using line_no = vector<string>::size_type;
	QuerResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) :sought(s), lines(p), file(f){};
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};

class TextQuery{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream &);
	QuerResult query(const string&) const;

private:
	shared_ptr<vector<string>> file; //���������ļ�
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
	string text;
	while (getline(is, text))
	{
		file->push_back(text); // �����ȡ����һ�е�����

		istringstream line(text); //������ڴ�IO�Ĳ�������ȡ����
		int n = file->size()-1; //��¼�кţ��ӵ�0�п�ʼ
		string word;

		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines) //word��һ�γ���ʱ���±����ò����᷵��һ����ָ�벢��word���뵽map��
			{
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
	}
}

void runQueries(ifstream &infile)
{
	// infile �������ļ��Ķ���������ȡ��Ҫ���ʵ��ļ�
	TextQuery tq(infile);

	//������û����������ݣ�������ʾ�û�������Ҫ�û����ҵĵ���

	while (true)
	{
		cout << "��������Ҫ��ѯ�ĵ���,��������q�˳�" << endl;
		string s; //�����û�����ĵ���
		
		if (cin >> s && (s != "q" ))
		{
			print(cout, tq.query(s)) << endl;
		}

		if (s == "q")
			break;
	}
}

QuerResult TextQuery::query(const string& sought) const
{
	//���û���ҵ�sought������һ��ָ���set��ָ��
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	//ʹ��find�����ҵ���
	auto loc = wm.find(sought);

	if (loc == wm.end())
	{
		return QuerResult(sought, nodata, file);
	}
	else
	{
		return QuerResult(sought, loc->second, file);
	}
}

ostream & print(ostream &os, const QuerResult &qr)
{
	// ����ҵ��˵��ʣ���ӡ���ִ����ͳ��ֵ���
	os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;

	for (auto num : *qr.lines)
	{
		os << "(line" << num + 1 << ")\t" << *(qr.file->begin() + num) << endl;
	}
	return os;
}
string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream infile("E:\\My_Code\\a.txt");
	runQueries(infile);
	system("pause");
	return 0;
}

