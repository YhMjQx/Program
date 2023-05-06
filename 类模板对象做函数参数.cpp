#include<iostream>
#include<string>
using namespace std;

//��ģ��ʵ�����Ķ����������������ַ�ʽ

template<class T1, class T2>
class Person{
public:

	Person(T1 name, T2 age) :m_Name(name), m_Age(age){

	}

	void ShowPerson(){
		cout << "������" << this->m_Name << " ���䣺" << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};
//1.ָ����������� - ֱ����ʾ�������������

void PrintPerson1(Person<string, int>& p){
	//Person<string, int>& p - ֱ��ָ����������
	p.ShowPerson();

}

void test1(){
	Person<string, int> p1("������", 19);
	PrintPerson1(p1);

}

//2.����ģ�廯 - �������еĲ�����Ϊģ����д���

//Person<T1, T2>& p - ��p2��ģ�廯��һ��ģ�壬Ȼ�����Ϸ���һ��ģ������һ��ģ������б��ɣ�Ҳ����˵����Ҳ�����ģ��
template<class T1,class T2>
void PrintPerson2(Person<T1, T2>& p){
	p.ShowPerson();
	cout << "T1������Ϊ��" << typeid(T1).name() << endl;
	cout << "T2������Ϊ��" << typeid(T2).name() << endl;

}

void test2(){
	Person<string, int> p2("����ǿ", 19);
	PrintPerson2(p2);
	
}

//3.������ģ�廯 - ��������������ģ�廯���д���
template<class T>
void PrintPerson3( T& p ){
	p.ShowPerson();
	cout << "T���������ͣ� " << typeid(T).name() << endl;
	//������Person�඼ģ�廯��һ�� T ,Ȼ���ٽ�p3��Ϊ��������
	//
}

void test3(){
	Person<string, int> p3("����", 0);
	PrintPerson3(p3);
}

int main(){
	//test1();
	//test2();
	test3();
	return 0;
}