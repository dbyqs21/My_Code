//Abstraction.cpp

#include "CAbstraction.h"
#include "CAbstractionImp.h"

#include <iostream>
using namespace std;

CAbstraction::CAbstraction()
{

}

CAbstraction::~CAbstraction()
{

}

CRefineAbstraction::CRefineAbstraction(CAbstractionImp * imp)
{
	_imp = imp;
}

CRefineAbstraction::~CRefineAbstraction()
{

}

void CRefineAbstraction::Operation()
{
	_imp->Operation();
}




//CAbstraction::operation()
//{
//	cout << "Abstracion "
//}