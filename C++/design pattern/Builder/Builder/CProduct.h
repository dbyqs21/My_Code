//CProduct.h

#ifndef CPRODUCT_H_
#define CPRODUCT_H_

class CProduct {
public:
	CProduct();
	~CProduct();

	void producePart();
};

class CProductPart
{
public:
	CProductPart();
	~CProductPart();

	CProductPart * bulidPart();
};

#endif