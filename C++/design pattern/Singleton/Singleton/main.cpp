#include "CSingleton.h"
#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
	CSingleton * sgn = CSingleton::Instance();  //��ȡ��CSington��ʵ��

	system("pause");
	return 0;
}