//CPrototype.h

#ifndef CPROTOTYPE_H_
#define CROTOTYPE_H_

class CPrototype{
public:
	virtual ~CPrototype();
	virtual CPrototype * clone() const = 0;

protected:
	CPrototype();
	
};

class CConcretePrototype : public CPrototype {
public:
	CConcretePrototype();
	~CConcretePrototype();

	CConcretePrototype(const CConcretePrototype & cp);
	CPrototype * clone() const;
};


#endif