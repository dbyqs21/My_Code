#ifndef CFACTORY_H_
#define CFACTORY_H_

class CProduct;

class CFactory{
public:
	virtual ~CFactory() = 0;
	virtual CProduct * CreateProduct() = 0;

protected:
	CFactory();
private:

};

class CConcreteFactory :public CFactory {
public:
	~CConcreteFactory();
	CConcreteFactory();

	CProduct * CreateProduct();
};

#endif