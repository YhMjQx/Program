//#include<iostream>
//#include<string>
//using namespace std;
//
//template<class T1,class T2>
//class Person{
//public:
//	Person(T1 name, T2 age);
//
//	void ShowPerson();
//
//	T1 m_Name;
//	T2 m_Age;
//};
//
//template<class T1,class T2>
//Person<T1, T2>::Person(T1 name, T2 age){
//	this->m_Name = name;
//	this->m_Age = age;
//}
//
//template<class T1, class T2>
//void Person<T1, T2>::ShowPerson(){
//	cout << "������ " << this->m_Name << " ���䣺 " << this->m_Age << endl;
//}

//#include"Person.h"

//��һ�ֽ���취��
//���ļ��а���#include"Person.cpp"
//#include"Person.cpp"
//Ϊʲô��������������أ�
//����Ϊ��ģ���ڰ�����ʱ�������еĳ�Ա���������ᴴ����Ҫ�ڵ��õ�ʱ��Żᴴ��
//���Ըտ�ʼ��ʱ�򵥵�����һ��Person.h��û�õģ������ͻᵼ�±��������ӵ�ʱ��������Ӳ���person.cpp
//�����ڱ����������ʱ�򿴲���������ʵ�֣��͵��³�������ʧ����
//����ֱ�Ӱ���.cpp�ļ����ɣ���.cpp�ļ��а��� .h�ļ��ͺ���

//�ڶ��ֽ���취��
//��������ʵ�ֵĴ������ͬһ��ͷ�ļ����У����ҽ��ļ�����׺��Ϊ.hpp
//�����ֽ���취�ͱȽϼ��ˣ���������ʵ�ַ���һ���ļ����У�ֱ�Ӱ�������ļ���������
#include"Person.hpp"

void test1(){
	Person<string, int>p("������", 19);
	p.ShowPerson();
}

int main(){
	test1();
	return 0;
}