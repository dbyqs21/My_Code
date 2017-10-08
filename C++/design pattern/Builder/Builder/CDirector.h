// CDirector.h

#ifndef CDIRECTOR_H_
#define CDIRECTOR_H_

class CBuilder;

class CDirector {
public:
	CDirector(CBuilder * bld);
	~CDirector();
	void constructor();

private:
	CBuilder * _bld;
};

#endif