#include "CFactory.h"
#include "CProduct.h"

#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
	CFactory * fac = new CConcreteFactory();
	CProduct * p = fac->CreateProduct();
	system("pause");
	return 0;
}