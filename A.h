#ifndef _A_H_
#define _A_H_
#include"B.h"
class A
{
public:
	A();
	~A();

	B b_;//这个操作势必需要包含B的头文件
};

#endif; // _A_H_