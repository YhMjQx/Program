#include<iostream>
#include<string>
using namespace std;

template<class T1,class T2>
class Person{
public:

	//Person(T1 name, T2 age) :m_Name(name), m_Age(age){

	//}

	Person(T1 name, T2 age);

	void ShowPerson();/*{
		cout << "������ " << m_Name << " ���䣺 " << m_Age << endl;
	}*/

	T1 m_Name;
	T2 m_Age;
};

//���캯������ʵ��
template<class T1,class T2>
Person<T1, T2>::Person(T1 name, T2 age){
	this->m_Name = name;
	this->m_Age = age;

}

//��Ա��������ʵ��
template<class T1,class T2>
void Person<T1, T2>::ShowPerson(){
	cout << "������ " << m_Name << " ���䣺 " << m_Age << endl;
}

void test1(){
	Person<string ,int> s("������",19);
	s.ShowPerson();
}

int main(){
	test1();
	return 0;
}