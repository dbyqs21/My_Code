//Product.cpp

#include "CProduct.h"
#include <iostream>
using namespace std;

CProduct::CProduct()
{
	producePart();
	cout << "return a product" << endl;
}

CProduct::~CProduct()
{

}

void CProduct::producePart()
{
	cout << "build part of product" << endl;
}

CProductPart::~CProductPart()
{

}

CProductPart::CProductPart()
{
	cout << "bulid product part" << endl;
}

CProductPart * CProductPart::bulidPart()
{
	return new CProductPart();
}
