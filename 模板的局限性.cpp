#include<iostream>
#include<string>
using namespace std;

//ģ���ͨ���Բ������ܵ�
//����һ����ֵ���������������������ʵ�������飬��ģ��Ͳ���ʵ��
//���б��� �Ƚϵĺ���ģ�壬 ����Ƚϵ��������Զ������  ����ô�ȣ�
//Ϊ�˽����Щ���⣬C++�ṩģ������أ�����Ϊ��Щ�ض��������ṩ���廯ģ��

//�Աȵĺ���ģ��
template<typename T>
bool MyCampare(T& a, T& b){
	//�������ģ���޷��������Զ�������������
	if (a == b){
		return true;
	}
	else{
		return false;
	}
}

void test1(){
	int a = 10;
	int b = 20;

	if (MyCampare(a, b)){
		cout << "a = b" << endl;
	}
	else{
		cout << "a != b" << endl;

	}
}

class Person{
public:
	Person(string name, int age) :m_Name(name), m_Age(age){

	}

	string m_Name;
	int m_Age;
};

template<class T1,class T2>
bool MyCompare(T1& p1, T2& p2){
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age){
		return true;
	}
	else{
		return false;
	}
}

void test2(){
	Person p1("������", 19);
	Person p2("����ǿ", 19);

	if (MyCompare(p1, p2)){
		cout << "p1 = p2" << endl;
	}
	else{
		cout << "p1 != p2" << endl;

	}
}

int main(){
	//test1();
	test2();
	return 0;
}