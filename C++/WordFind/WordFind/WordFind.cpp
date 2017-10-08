// WordFind.cpp : 定义控制台应用程序的入口点。
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
	shared_ptr<vector<string>> file; //保存输入文件
	map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
	string text;
	while (getline(is, text))
	{
		file->push_back(text); // 保存读取到的一行的数据

		istringstream line(text); //定义对内存IO的操作来提取单词
		int n = file->size()-1; //记录行号，从第0行开始
		string word;

		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines) //word第一次出现时，下标引用操作会返回一个空指针并将word插入到map中
			{
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
	}
}

void runQueries(ifstream &infile)
{
	// infile 是输入文件的对象。用来读取将要访问的文件
	TextQuery tq(infile);

	//设计与用户交互的内容，比如提示用户输入需要用户查找的单词

	while (true)
	{
		cout << "请输入需要查询的单词,或者输入q退出" << endl;
		string s; //保存用户输入的单词
		
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
	//如果没有找到sought，返回一个指向此set的指针
	static shared_ptr<set<line_no>> nodata(new set<line_no>);

	//使用find来查找单词
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
	// 如果找到了单词，打印出现次数和出现的行
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

