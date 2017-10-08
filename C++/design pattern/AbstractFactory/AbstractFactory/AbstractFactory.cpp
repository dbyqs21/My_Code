#include "CAbstractFactory.h"
#include "CProduct.h"
#include <iostream>
using namespace std;

CAbstractFactory::CAbstractFactory()
{
	//构造函数的实现

}

CAbstractFactory::~CAbstractFactory()
{
	//析构函数的实现
}

CConcreteFactory1::CConcreteFactory1()
{

}

CConcreteFactory1::~CConcreteFactory1()
{

}

CAbstractProductA * CConcreteFactory1::CreateProductA()
{
	return new CProductA1();
}

CAbstractProductA * CConcreteFactory2::CreateProductA()
{
	return new CProductA2();
}

CAbstractProductB * CConcreteFactory1::CreateProductB()
{
	return new CProductB1();
}

CAbstractProductB * CConcreteFactory2::CreateProductB()
{
	return new CProductB2();
}

