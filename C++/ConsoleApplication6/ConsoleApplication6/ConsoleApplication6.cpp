// ConsoleApplication6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <bitset>
#include <regex>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern);
	smatch results;

	string test_str = "receipt friend theif receive";

	if (regex_search(test_str, results, r))
		cout << results.str() << endl;

/*
	bitset<16> bits;
	cin >> bits;
	bits.set();
	cout << bits<<endl;
	bits.reset();
	cout << bits << endl;
*/


	/*int k = (69 2 3 + - 8 4 / >>) ;
	cout << k<< endl;*/

	system("pause"); 
	return 0;
}

