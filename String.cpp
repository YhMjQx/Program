#include "String.h"

String::String(char* str)
{
	 str_ = AllocAndCpy(str);
}

String::~String()
{
	delete[] str_;
}

char* String::AllocAndCpy(char* str){
	int len = strlen(str) + 1;
	char* tmp = new char[len];
	memset(tmp, 0, len);
	strcpy(tmp, str);
	return tmp;
}

void String::Display(){
	cout << str_ << endl;
}

String::String(const String& other){
	//������Ͳ����ں�������ʱ���г�ʼ������Ϊ����ں����Ͻ��г�ʼ���������Ҳ���ڵ�����ǳ����
	//String::String(const String& other) :str_(other.str_); - Error �������Ҳ���ڵ�����ǳ����
	str_ = AllocAndCpy(other.str_);
}

String& String:: operator=(const String& other)//�Լ��ĵȺ������
{
	if (this == &other)
		return *this;

	//��Ȼ��ʹ�á�=���������˵��=��ߵĶ����Ѿ������ˣ���ô��Ҫ��ֵ��
	//����Ҫ�Ȱ�ԭ���ĵȺ���ߵĿռ��ͷ��ˣ��ٵ����Լ���������캯��
	delete[] str_;
	str_ = AllocAndCpy(other.str_);
	return *this;
}

