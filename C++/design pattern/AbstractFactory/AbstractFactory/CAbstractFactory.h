#ifndef CABSTRACTFACTORY_H_
#define CABSTRACTFACTORY_H_

class CAbstractProductA;  //类的声明
class CAbstractProductB;

class CAbstractFactory{
public:
	virtual ~CAbstractFactory();
	virtual CAbstractProductA * CreateProductA() = 0;
	virtual CAbstractProductB * CreateProductB() = 0;

protected:
	CAbstractFactory();   //构造函数

};

class CConcreteFactory1 :public CAbstractFactory {
public:
	CConcreteFactory1();
	~CConcreteFactory1();

	CAbstractProductA * CreateProductA(); //子类实现CreateProductA函数
	CAbstractProductB * CreateProductB();

};

class CConcreteFactory2 :public CAbstractFactory {
public :
	~CConcreteFactory2();
	CConcreteFactory2();

	CAbstractProductA * CreateProductA(); //子类实现CreateProductA函数
	CAbstractProductB * CreateProductB();
};

#endif