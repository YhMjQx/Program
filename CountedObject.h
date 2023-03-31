//#pragma once
#ifndef _COUNTEDOBJECT_H_
#define _COUNTEDOBJECT_H_
#include<iostream>
using namespace std;

class CountedObject
{
public:
	CountedObject();
	~CountedObject();
	static int GetCount();
private:
	static int count_;	//静态成员引用性声明，此时在类生命的时候是不能直接初始化的，应该放在cpp文件里初始化
};

#endif //_COUNTEDOBJECT_H_