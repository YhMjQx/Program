#ifndef _B_H_
#define _B_H_
//#include"A.h"//两个类互相包含是不允许的，于是就要用前向声明
class A;
class B
{
public:
	B();
	~B();

	//A a_;  - Error既然用了前向声明，则该类就不能再实例化对象，此时只能定义指针或者引用
	A* a_;
	A& a_;
};

#endif; //_B_H_