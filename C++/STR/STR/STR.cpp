// STR.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "assert.h"
#include "cctype"
//#include "string.h"
#include "cstring"
using namespace std


int mystrcmp(const char* str1, const char* str2);
int _tmain(int argc, _TCHAR* argv[])
{
	string s("Hellow world!!!");
	for (auto &c : s)
	{
		c = toupper(c);
	}
	cout << s << endl;
	return 0;
}



int _tmain2(int argc, _TCHAR* argv[])
{
	char str1[] = "abfe";
	char str2[] = "abd";
	printf("%d",mystrcmp(str1, str2));
	getchar();
	return 0;
}


int mystrcmp(const char* str1 , const char* str2)
{
	assert((NULL != str1) && (NULL != str2));
	int cnt = 0;
	while (!(cnt = *(unsigned char*)str1 - *(unsigned char*)str2) && *str2)
	{
		str1++;
		str2++;
	}

	if (cnt > 0)
	{
		cnt = 1;
	}
	else if (cnt < 0)
	{
		cnt = -1;
	}

	return cnt;

}
