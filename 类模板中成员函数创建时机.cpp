#include<iostream>
#include<string>
using namespace std;

//��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
//��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���
class Person1{
public:
	void ShowPerson1(){
		cout << "Person1 show" << endl;
	}
};

class Person2{
public:
	void ShowPerson2(){
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass{
public:
	T obj;
	//�޷�ȷ��obj�ľ������ͣ����Ը�ģ����ĳ�Ա������һ��ʼ����ȥ����

	void func1(){
		obj.ShowPerson1();
	}

	void func2(){
		obj.ShowPerson2();
	}
};

void test1(){
	MyClass<Person1> p1;
	p1.func1();
	//p1.func2(); - �����δ����ڵ��õ�ʱ���ȥ������ģ���г�Ա����

	MyClass<Person2> p2;
	//p2.func1();
	p2.func2();
}

int main(){

	test1();
	return 0;
}