//AbstractionImp.cpp

#include "CAbstractionImp.h"

#include <iostream>
using namespace std;

CAbstractionImp::CAbstractionImp()
{

}

CAbstractionImp::~CAbstractionImp()
{

}

void CAbstractionImp::Operation()
{
	cout << "AbstractonImp ...Imp..." << endl;
}

CConcreteAbstractionImpA::CConcreteAbstractionImpA()
{

}
CConcreteAbstractionImpA::~CConcreteAbstractionImpA()
{

}
void CConcreteAbstractionImpA::Operation()
{
	cout << "CConcreteAbstractionImpA... " << endl;
}

CConcreteAbstractionImpB::CConcreteAbstractionImpB()
{

}
CConcreteAbstractionImpB::~CConcreteAbstractionImpB()
{

}
void CConcreteAbstractionImpB::Operation()
{
	cout << "CConcreteAbstractionImpB... " << endl;
}

CConcreteAbstractionImpC::CConcreteAbstractionImpC()
{

}
CConcreteAbstractionImpC::~CConcreteAbstractionImpC()
{

}
void CConcreteAbstractionImpC::Operation()
{
	cout << "CConcreteAbstractionImpC... " << endl;
}