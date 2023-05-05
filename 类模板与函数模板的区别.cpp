#include<iostream>
#include<string>
using namespace std;


template<class NameType, class AgeType= int>
class Person{
public:
	Person(NameType name, AgeType age ) :m_Name(name), m_Age(age){

	}

	void ShowInfo(){
		cout << "名字：" << m_Name << " 年龄：" << m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

//类模板没有自动类型推导的方式
void test1(){
	//Person("胡佳欣", 19); - error,类模板不能自己类型推导，在这里就是无法将NameType推导为string，无法将AgeType推导为int
	Person<string ,int> p("胡佳欣", 19);
	p.ShowInfo();
}

//类模板在模板参数列表中可以有默认参数
void test2(){
	Person<string> p("杨明强",19);
	p.ShowInfo();
}

int main(){

	test1();

	test2();
	return 0;
}