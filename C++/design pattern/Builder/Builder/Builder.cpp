//Builder.cpp

#include "CBuilder.h"
#include "CProduct.h"

#include <iostream>
#include <string>
using namespace std;

CBuilder::CBuilder()
{

}

CBuilder::~CBuilder()
{

}

CConcreteBuilder::CConcreteBuilder()
{

}

CConcreteBuilder::~CConcreteBuilder()
{

}

void CConcreteBuilder::builderPartA(const string & BuildPara)
{
	cout << "Setp1:Build PartA..." << BuildPara << endl;
}

void CConcreteBuilder::builderPartB(const string & BuildPara)
{
	cout << "Setp2:Build PartB..." << BuildPara << endl;
}

void CConcreteBuilder::builderPartC(const string & BuildPara)
{
	cout << "Setp1:Build PartC..." << BuildPara << endl;
}

void CConcreteBuilder::builderPartD(const string & BuildPara)
{
	cout << "Setp1:Build PartD..." << BuildPara << endl;
}



CProduct * CConcreteBuilder::getProduct()
{
	builderPartA("Pre-defined");
	builderPartB("Pre-defined");
	builderPartC("Pre-defined");
	builderPartD("Pre-defined");
	return new CProduct();
}
