//#pragma once
//����ʵ��ǰ��++�����
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

	//ǰ��++���������
	Integer& operator++();
	//friend Integer& operator++(Integer& i);

	//����++���������
	Integer operator++(int i);//�����int i��û��ʵ�ʵ����ã�ֻ��Ϊ������ǰ��++�ͺ���++������
	//friend Integer operator++(Integer& i, int n);
private:
	int n_;
};

#endif //_INTEGER_H_