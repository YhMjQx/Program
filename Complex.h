//#pragma once
#include<iostream>
using namespace std;
#ifndef _COMPLEX_H_
#define _COMPLEX_H_
//����һ��������
class Complex
{
public:
	Complex(int real,int imag);
	Complex();
	~Complex();
	Complex& Add(const Complex& other);
	void Display();

	//���Գ�Ա��������ʽ���صĻ�����ô�������ڵĵ�һ�������Ĳ�����ʵ�����������
	Complex operator+(const Complex& other);
	//������Ԫ������ʽ����,������Ԫ����������ĳ�Ա������������Ԫ����ʽ��ȳ�Ա��������ʽ��һ������
	friend Complex operator+(const Complex& other1, const Complex& other2);
private:
	int real_;//ʵ��
	int imag_;//�鲿
};

#endif _COMPLEX_H_