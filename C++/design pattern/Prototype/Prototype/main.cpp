// Main.cpp


#include "CPrototype.h"
#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
	CPrototype * p = new CConcretePrototype();
	CPrototype * p1 = p->clone();

	system("pause");
	return 0;
}
