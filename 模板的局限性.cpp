#include<iostream>
#include<string>
using namespace std;

//模板的通用性不是万能的
//例如一个赋值操作函数，如果传进来的实参是数组，该模板就不能实现
//还有比如 比较的函数模板， 如果比较的是两个自定义的类  该怎么比？
//为了解决这些问题，C++提供模板的重载，可以为这些特定的类型提供具体化模板

//对比的函数模板
template<typename T>
bool MyCampare(T& a, T& b){
	//这个函数模板无法运用在自定义类型数据上
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
	Person p1("胡佳欣", 19);
	Person p2("杨明强", 19);

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