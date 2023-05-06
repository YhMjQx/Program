#include<iostream>
#include<string>
using namespace std;

//类模板实例化的对象，向函数传参有三种方式

template<class T1, class T2>
class Person{
public:

	Person(T1 name, T2 age) :m_Name(name), m_Age(age){

	}

	void ShowPerson(){
		cout << "姓名：" << this->m_Name << " 年龄：" << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};
//1.指定传入的类型 - 直接显示对象的数据类型

void PrintPerson1(Person<string, int>& p){
	//Person<string, int>& p - 直接指定传入类型
	p.ShowPerson();

}

void test1(){
	Person<string, int> p1("胡佳欣", 19);
	PrintPerson1(p1);

}

//2.参数模板化 - 将对象中的参数变为模板进行传递

//Person<T1, T2>& p - 将p2再模板化成一个模板，然后在上方用一个模板声明一下模板参数列表即可，也就是说参数也变成了模板
template<class T1,class T2>
void PrintPerson2(Person<T1, T2>& p){
	p.ShowPerson();
	cout << "T1的类型为：" << typeid(T1).name() << endl;
	cout << "T2的类型为：" << typeid(T2).name() << endl;

}

void test2(){
	Person<string, int> p2("杨明强", 19);
	PrintPerson2(p2);
	
}

//3.整个类模板化 - 将整个对象类型模板化进行传递
template<class T>
void PrintPerson3( T& p ){
	p.ShowPerson();
	cout << "T的数据类型： " << typeid(T).name() << endl;
	//将整个Person类都模板化成一个 T ,然后再将p3作为参数传递
	//
}

void test3(){
	Person<string, int> p3("胡杨", 0);
	PrintPerson3(p3);
}

int main(){
	//test1();
	//test2();
	test3();
	return 0;
}