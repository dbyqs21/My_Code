#include "CAbstractFactory.h"
#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
	CAbstractFactory * cf1 = new CConcreteFactory1();
	cf1->CreateProductA();
	cf1->CreateProductB();

	CAbstractFactory * cf2 = new CConcreteFactory2();
	cf2->CreateProductA();
	cf2->CreateProductB();

	system("pause");
	return 0;
}