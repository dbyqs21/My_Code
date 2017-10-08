//main.cpp

#include "CAbstraction.h"
#include "CAbstractionImp.h"

#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
	CAbstractionImp * imp = new CConcreteAbstractionImpA();
	CAbstraction * abs = new CRefineAbstraction(imp);
	abs->Operation();

	system("pause");
	return 0;
}