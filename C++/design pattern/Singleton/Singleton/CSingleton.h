#ifndef CSINGLETON_H_
#define CSINGLETON_H_

#include <iostream>
using namespace std;

class CSingleton{
public:
	static CSingleton * Instance();  //定义用于外部函数获取单例实例的函数接口

protected:
	

private:
	static CSingleton * _instance;
	CSingleton();  //私有化构造函数
};

#endif