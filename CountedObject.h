//#pragma once
#ifndef _COUNTEDOBJECT_H_
#define _COUNTEDOBJECT_H_
#include<iostream>
using namespace std;

class CountedObject
{
public:
	CountedObject();
	~CountedObject();
	static int GetCount();
private:
	static int count_;	//��̬��Ա��������������ʱ����������ʱ���ǲ���ֱ�ӳ�ʼ���ģ�Ӧ�÷���cpp�ļ����ʼ��
};

#endif //_COUNTEDOBJECT_H_