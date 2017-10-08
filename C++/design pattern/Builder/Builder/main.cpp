//main.cpp

#include "CBuilder.h"
#include "CDirector.h"
#include "CProduct.h"

#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
	CDirector * d = new CDirector(new CConcreteBuilder());
	d->constructor();

	system("pause");
	return 0;
}