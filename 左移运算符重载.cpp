#include<iostream>
using namespace std;

//左移运算符重载
class Person{
public:
	friend ostream&  operator<<(ostream cout, Person& p);
	//利用成员函数重载左移运算符，p.operator(cout)简化版本p<<cout
	//不会利用成员函数重载<<运算符，因为这样无法实现cout<<p，即cout在左侧
	//void operator<<( cout ){
	//}

	//Person(int a, int b) :m_A(a), m_B(b){

	//}
//private:
	int m_A;
	int m_B;
};

//只能利用全局函数重载左移运算符
ostream&  operator<<(ostream cout, Person& p){ // 本质，operator<<(cout,p),简化cout<<p
	cout << "m_A= " << p.m_A <<" "<< "m_B= " << p.m_B;
	return cout;
}

void test1(){
	Person p;
	p.m_A = 10;
	p.m_B = 10;

	cout << p.m_A << endl; 
}

int main(){
	test1();
	return 0;
}