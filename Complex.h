//#pragma once
#include<iostream>
using namespace std;
#ifndef _COMPLEX_H_
#define _COMPLEX_H_
//创建一个复数类
class Complex
{
public:
	Complex(int real,int imag);
	Complex();
	~Complex();
	Complex& Add(const Complex& other);
	void Display();

	//若以成员函数的形式重载的话，那么参数表内的第一个隐含的参数其实是类对象自身
	Complex operator+(const Complex& other);
	//若以友元函数形式重载,由于友元函数不是类的成员函数，所以友元的形式会比成员函数的形式多一个参数
	friend Complex operator+(const Complex& other1, const Complex& other2);
private:
	int real_;//实部
	int imag_;//虚部
};

#endif _COMPLEX_H_