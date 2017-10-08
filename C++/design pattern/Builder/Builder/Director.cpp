// Director.cpp

#include "CDirector.h"
#include "CBuilder.h"

CDirector::CDirector(CBuilder * bld)
{
	_bld = bld;
}

CDirector::~CDirector()
{

}

void CDirector::constructor()
{
	_bld->builderPartA("user-defined");
	_bld->builderPartB("user-defined");
	_bld->builderPartC("user-defined");
}