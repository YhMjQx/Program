#include<iostream>
#include<string>
using namespace std;

//��ģ��
template<class NameType,class AgeType>
class Person{
public:
	Person(NameType name, AgeType age) :m_Name(name), m_Age(age){

	}

	void ShowInfo(){
		cout << "���֣�" << m_Name << " ���䣺" << m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

void test1(){
	Person<string, int> p1("������", 19);
	Person<string, int> p2("����ǿ", 19);

	p1.ShowInfo();
	p2.ShowInfo();
}

int main(){

	test1();
	return 0;
}