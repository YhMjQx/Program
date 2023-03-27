//#pragma once
//class Text
//{
//public:
//	Text();
//	~Text();
//};
//
#ifndef _TEXT_H_
#define _TEXT_H_
#include<iostream>
using namespace std;
class Text{
public:
	Text();
	Text(int num);
	//上面这不就是构造函数的重载嘛
	void Display();

	~Text();
		//这就是析构函数，在程序结束的时候，会自动调用析构函数
		//函数名和类名相似（前面多了字符“~”）
		//析构函数没有返回类型，没有参数
		//析构函数不能被重载
		//如果没有定义析构函数，编译器会自动生成一个默认析构函数，其格式如下：
		//默认析构函数是一个空函数
		//类名::~默认析构函数名(){
		//
		//}
private:
	int num_;
};
#endif // _TEXT_H_