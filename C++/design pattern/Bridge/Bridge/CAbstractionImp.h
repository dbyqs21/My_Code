// CAbstraction.h

#ifndef _CABSTRACTIONIMP_H_
#define _CABSTRACTIONIMP_H_

class CAbstractionImp{
public:
	virtual ~CAbstractionImp();

	virtual void Operation() = 0;

protected:
	CAbstractionImp();
};

class CConcreteAbstractionImpA :public CAbstractionImp{
public:
	virtual ~CConcreteAbstractionImpA();
	CConcreteAbstractionImpA();

	virtual void Operation();
};

class CConcreteAbstractionImpB :public CAbstractionImp{
public:
	virtual ~CConcreteAbstractionImpB();
	CConcreteAbstractionImpB();

	virtual void Operation();
};

class CConcreteAbstractionImpC :public CAbstractionImp{
public:
	virtual ~CConcreteAbstractionImpC();
	CConcreteAbstractionImpC();

	virtual void Operation();
};

#endif