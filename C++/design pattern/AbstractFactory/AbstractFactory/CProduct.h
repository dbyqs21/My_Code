#ifndef CFACTORY_H_
#define CFACTORY_H_

class CAbstractProductA{
public:
	virtual ~CAbstractProductA();

protected:
	CAbstractProductA();
};

class CAbstractProductB{
public:
	virtual ~CAbstractProductB();

protected:
	CAbstractProductB();
};

class CProductA1 :public CAbstractProductA{
public:
	CProductA1();
	~CProductA1();

};

class CProductA2 :public CAbstractProductA{
public:
	CProductA2();
	~CProductA2();

};
class CProductB1 :public CAbstractProductB{
public:
	CProductB1();
	~CProductB1();

};

class CProductB2 :public CAbstractProductB{
public:
	CProductB2();
	~CProductB2();

};
#endif 