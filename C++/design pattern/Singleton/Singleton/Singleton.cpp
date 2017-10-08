#include "CSingleton.h"

#include <iostream>
using namespace std;

CSingleton * CSingleton::_instance = 0;

CSingleton::CSingleton()
{
	cout << "creata CSingleton instance" << endl;
}

CSingleton * CSingleton::Instance()
{
	if (_instance == 0)
	{
		_instance = new CSingleton();
	}
	
	return _instance;
}

