//#pragma once  - 为了防止头文件重复包含
#include<assert.h>
#ifndef _CLOCK_H_
#define _CLOCK_H_

//这是一个类，类有两个要素，一个是数据成员，二是成员函数
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


