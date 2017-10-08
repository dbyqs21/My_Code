// CAbstraction.h

#ifndef _CABSTRACTION_H_
#define _CABSTRACTION_H_

class CAbstractionImp;

class CAbstraction {
public:
	virtual ~CAbstraction();
	virtual void Operation();

protected:
	CAbstraction();

};

class CRefineAbstraction :public CAbstraction {
public:
	CRefineAbstraction(CAbstractionImp * imp);
	~CRefineAbstraction();

	void Operation();

private:
	CAbstractionImp * _imp;
};
#endif