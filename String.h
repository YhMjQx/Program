//#pragma once
#ifndef _STRING_H_
#define _STRING_H_
#include<string.h>
#include<iostream>
using namespace std;

class String
{
public:
	String(char* str = "");
	~String();
	void Display();
	String(const String& other);//自己的拷贝构造函数
	String& operator=(const String& other);//自己的等号运算符
private:
	char* AllocAndCpy(char* str);
	char* str_;
};

#endif //_STRING_H_
