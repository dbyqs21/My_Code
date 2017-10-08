#ifndef _CProduct_H_
#define _CProduct_H_

class CProduct{
public:
	virtual ~CProduct() = 0;

protected:
	CProduct();

private:

};

class CConcreteProduct : public CProduct {
public:
	~CConcreteProduct();
	CConcreteProduct();

};

#endif