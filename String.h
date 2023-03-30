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
	String(const String& other);//�Լ��Ŀ������캯��
	String& operator=(const String& other);//�Լ��ĵȺ������
private:
	char* AllocAndCpy(char* str);
	char* str_;
};

#endif //_STRING_H_
