//CBuilder.h

#ifndef CBUILDER_H_
#define CBUILDER_H_

#include <string>
using namespace std;

class CProduct;

class CBuilder{
public:
	virtual ~CBuilder();
	virtual void builderPartA(const string & BuildPara) = 0;
	virtual void builderPartB(const string & BuildPara) = 0;
	virtual void builderPartC(const string & BuildPara) = 0;
	virtual void builderPartD(const string & BuildPara) = 0;

	virtual CProduct * getProduct() = 0;

protected:
	CBuilder();

};

class CConcreteBuilder :public CBuilder {
public:
	CConcreteBuilder();
	~CConcreteBuilder();

	void builderPartA(const string & BuildPara);
	void builderPartB(const string & BuildPara);
	void builderPartC(const string & BuildPara);
	void builderPartD(const string & BuildPara);

	CProduct * getProduct();

};
#endif