#include<iostream>
#include<string>
using namespace std;

template<class T1, class T2>
class Person{
public:
	Person(T1 name, T2 age);

	void ShowPerson();

	T1 m_Name;
	T2 m_Age;
};

template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age){
	this->m_Name = name;
	this->m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::ShowPerson(){
	cout << "������ " << this->m_Name << " ���䣺 " << this->m_Age << endl;
}