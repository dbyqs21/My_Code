#ifndef CSINGLETON_H_
#define CSINGLETON_H_

#include <iostream>
using namespace std;

class CSingleton{
public:
	static CSingleton * Instance();  //���������ⲿ������ȡ����ʵ���ĺ����ӿ�

protected:
	

private:
	static CSingleton * _instance;
	CSingleton();  //˽�л����캯��
};

#endif