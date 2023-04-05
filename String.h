//#pragma once
#ifndef _STRING_H_
#define _STRING_H_
#include<string.h>
#include<iostream>
using namespace std;

class String
{
public:
	/*explicit*/ String(char* str = ""); //����explicit��Ϊ�˷�ֹ���캯������ʽת��,��ȻһЩ�������ʽת��Ҳ�ǿ��Եģ��ȽϷ���

	String(const String& other);//�Լ��Ŀ������캯��

	String& operator=(const String& other);//�Լ��ĵȺ����������
	String& operator=(const char* str);//��һ����ʽ�ĵȺ����������

	bool operator!() const;//!�����������

	char& operator[](unsigned int index) ;//[]�����������
	const char& operator[](unsigned int index) const;
		//�����ǰ�������const����ô���еĶ�s1[index]���еĸ�ֵ�������Ǵ��

	friend String operator+(const String& s1, const String& s2);
		//ΪʲôҪ����Ԫ����ʽ�����أ��ô���ʲô��
		//��Ϊ������Գ�Ա��������ʽ���صĻ�����ô�ú�����ֻ��һ�����������е�һ��������thisָ�룬��ָ������Լ���һ��ָ��
		//�������Ǿ��޷�ʵ��String s6 = "YhMjQx " + s5 + "1314";�����Ĳ�����
		//���ֲ���ʱ�ǽ��ַ�����ת��Ϊ����Ȼ���ڵ���operator+()�������

	String& operator+=(const String& other);//+=��һ������Ӧ���Ƕ�����������ѡ���ó�Ա��������ʽ����

	friend ostream& operator<<(ostream& os,const String& str);
	//1.��Ԫ����ʽ��2.<< ��˫Ŀ������ 3.����������ostream& ��ostream - ����
	//1.��Ϊ<<���ܻ�ֱ�ӷ���������ݳ�Ա,�������ĵ�һ��������cout
	//2.˫Ŀ����������һ��������cout��cout��ʵ����һ��ostream������
	//3.��Ϊ���ܹ���һ�д����ж������������ʹ��<<(�����)

	friend istream& operator>>(istream& is,String str);// >>(��ȡ��)

	~String();

	void Display() const;//����const˵���ú������ܶ�˽�г�Ա�����ı�

private:
	String& Assign(const char* str);
	char* AllocAndCpy(const char* str);
	char* str_;
};

#endif //_STRING_H_
