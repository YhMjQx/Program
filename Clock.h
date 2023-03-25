//#pragma once  - Ϊ�˷�ֹͷ�ļ��ظ�����
#include<assert.h>
#ifndef _CLOCK_H_
#define _CLOCK_H_

//����һ���࣬��������Ҫ�أ�һ�������ݳ�Ա�����ǳ�Ա����
class Clock{
public:
	void Init(int hour,int minute,int second);
	void Display();
	void Update();

	int GetHour();
	int GetMinute();
	int GetSecond();

	void SetHour(int hour);
	void SetMinute(int minute);
	void SetSecond(int second);
private:
	int hour_;
	int minute_;
	int second_;
};
#endif


