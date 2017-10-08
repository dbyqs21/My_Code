#include "CProduct.h"
#include <iostream>
using namespace std;

CAbstractProductA::CAbstractProductA()
{
}
CAbstractProductA::~CAbstractProductA()
{
}
CAbstractProductB::CAbstractProductB()
{
}
CAbstractProductB::~CAbstractProductB()
{
}
CProductA1::CProductA1()
{
	cout << "ProductA1..." << endl;
}
CProductA1::~CProductA1()
{
}
CProductA2::CProductA2()
{
	cout << "ProductA2..." << endl;
}
CProductA2::~CProductA2()
{
}
CProductB1::CProductB1()
{
	cout << "CProductB1..." << endl;
}
CProductB1::~CProductB1()
{
}
CProductB2::CProductB2()
{
	cout << "CProductB2..." << endl;
}
CProductB2::~CProductB2()
{
}