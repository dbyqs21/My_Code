#include "CSingleton.h"
#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
	CSingleton * sgn = CSingleton::Instance();  //获取类CSington的实例

	system("pause");
	return 0;
}