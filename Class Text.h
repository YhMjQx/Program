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
	//�����ⲻ���ǹ��캯����������
	void Display();

	~Text();
		//����������������ڳ��������ʱ�򣬻��Զ�������������
		//���������������ƣ�ǰ������ַ���~����
		//��������û�з������ͣ�û�в���
		//�����������ܱ�����
		//���û�ж����������������������Զ�����һ��Ĭ���������������ʽ���£�
		//Ĭ������������һ���պ���
		//����::~Ĭ������������(){
		//
		//}
private:
	int num_;
};
#endif // _TEXT_H_