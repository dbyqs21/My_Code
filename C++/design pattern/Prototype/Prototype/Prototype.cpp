// Prototype.cpp

#include "CPrototype.h"
#include <iostream>
using namespace std;

CPrototype::CPrototype()
{
	cout << "CPrototype create function" << endl;
}

CPrototype::~CPrototype()
{

}

CPrototype * CPrototype::clone() const
{
	cout << "clone..." << endl;
	return 0;
}
CConcretePrototype::CConcretePrototype()
{
	cout << "CConcretePrototype create function" << endl;

}

CConcretePrototype::~CConcretePrototype()
{

}

CConcretePrototype::CConcretePrototype(const CConcretePrototype & cp)
{
	cout << "ConcretePrototype copy..." << endl;
}

CPrototype * CConcretePrototype::clone() const
{
	return new CConcretePrototype(*this);
}