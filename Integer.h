//#pragma once
//用来实现前置++运算符
#ifndef _INTEGER_H_
#define _INTEGER_H_
#include<iostream>
using namespace std;
class Integer
{
public:
	Integer(int n);
	~Integer();
	void Display();

	//前置++运算符重载
	Integer& operator++();
	//friend Integer& operator++(Integer& i);

	//后置++运算符重载
	Integer operator++(int i);//这里的int i并没有实际的作用，只是为了区分前置++和后置++的重载
	//friend Integer operator++(Integer& i, int n);
private:
	int n_;
};

#endif //_INTEGER_H_