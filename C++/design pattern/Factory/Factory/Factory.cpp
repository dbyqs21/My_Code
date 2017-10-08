#include "CFactory.h"
#include "CProduct.h"
#include <iostream>
using namespace std;

CFactory::CFactory()
{
	cout << "Factory is created" << endl;
}

CFactory::~CFactory()
{

}

CConcreteFactory::CConcreteFactory()
{
	cout << "ConcreteFactory..." << endl;
}

CConcreteFactory::~CConcreteFactory()
{

}

CProduct * CConcreteFactory::CreateProduct()
{
	return new CConcreteProduct();
}
