#ifndef _B_H_
#define _B_H_
//#include"A.h"//�����໥������ǲ�����ģ����Ǿ�Ҫ��ǰ������
class A;
class B
{
public:
	B();
	~B();

	//A a_;  - Error��Ȼ����ǰ�������������Ͳ�����ʵ�������󣬴�ʱֻ�ܶ���ָ���������
	A* a_;
	A& a_;
};

#endif; //_B_H_