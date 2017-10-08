#ifndef CABSTRACTFACTORY_H_
#define CABSTRACTFACTORY_H_

class CAbstractProductA;  //�������
class CAbstractProductB;

class CAbstractFactory{
public:
	virtual ~CAbstractFactory();
	virtual CAbstractProductA * CreateProductA() = 0;
	virtual CAbstractProductB * CreateProductB() = 0;

protected:
	CAbstractFactory();   //���캯��

};

class CConcreteFactory1 :public CAbstractFactory {
public:
	CConcreteFactory1();
	~CConcreteFactory1();

	CAbstractProductA * CreateProductA(); //����ʵ��CreateProductA����
	CAbstractProductB * CreateProductB();

};

class CConcreteFactory2 :public CAbstractFactory {
public :
	~CConcreteFactory2();
	CConcreteFactory2();

	CAbstractProductA * CreateProductA(); //����ʵ��CreateProductA����
	CAbstractProductB * CreateProductB();
};

#endif