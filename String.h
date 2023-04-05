//#pragma once
#ifndef _STRING_H_
#define _STRING_H_
#include<string.h>
#include<iostream>
using namespace std;

class String
{
public:
	/*explicit*/ String(char* str = ""); //加了explicit是为了防止构造函数的隐式转化,当然一些情况下隐式转换也是可以的，比较方便

	String(const String& other);//自己的拷贝构造函数

	String& operator=(const String& other);//自己的等号运算符重载
	String& operator=(const char* str);//另一种形式的等号运算符重载

	bool operator!() const;//!号运算符重载

	char& operator[](unsigned int index) ;//[]号运算符重载
	const char& operator[](unsigned int index) const;
		//如果在前面加上了const，那么所有的对s1[index]进行的赋值操作都是错的

	friend String operator+(const String& s1, const String& s2);
		//为什么要以友元的形式重载呢？好处是什么？
		//因为如果是以成员函数的形式重载的话，那么该函数就只有一个参数，其中第一个参数是this指针，是指向对象自己的一个指针
		//这样我们就无法实现String s6 = "YhMjQx " + s5 + "1314";这样的操作了
		//这种操作时是将字符串先转换为对象，然后在调用operator+()这个函数

	String& operator+=(const String& other);//+=第一个参数应该是对象自身，所以选择用成员函数的形式重载

	friend ostream& operator<<(ostream& os,const String& str);
	//1.友元的形式，2.<< 是双目操作符 3.返回类型是ostream& ，ostream - 流类
	//1.因为<<可能会直接访问类的数据成员,并且它的第一个对象是cout
	//2.双目操作符，第一个参数是cout，cout其实就是一个ostream流对象
	//3.是为了能够在一行代码中多次输出，即多次使用<<(插入符)

	friend istream& operator>>(istream& is,String str);// >>(提取符)

	~String();

	void Display() const;//加了const说明该函数不能对私有成员做出改变

private:
	String& Assign(const char* str);
	char* AllocAndCpy(const char* str);
	char* str_;
};

#endif //_STRING_H_
