#include<iostream>
using namespace std;

//左移运算符重载
class Person{
public:
	friend ostream&  operator<<(ostream& cout, Person& p);
	//利用成员函数重载左移运算符，p.operator(cout)简化版本p<<cout
	//不会利用成员函数重载<<运算符，因为这样无法实现cout<<p，即cout在左侧
	//void operator<<( cout ){
	//}

	Person(int a, int b) :m_A(a), m_B(b){

	}

	int GetPriA();

	int GetPriB();

private:
	int m_A;
	int m_B;
};

//只能利用全局函数重载左移运算符
ostream&  operator<<(ostream& cout, Person& p){ // 本质，operator<<(cout,p),简化cout<<p
	//ostream& cout - 这里也要用引用的原因是因为ostream对应的cout只能有且仅有一个，所以用引用
	//这也是为什么，如果不用引用的话，cout<< p <<endl;中的cout就会报错，因为构造了一个新的cout，这是不允许的
	cout << "m_A= " << p.m_A <<" "<< "m_B= " << p.m_B;
	return cout;//让返回cout,也就是再返回一个哦stream&是为了确保链式编程，就比如，cout<<p.m_A<<endl;
				//如果不返回一个类对象，那么就无法实现链式编程，只能cout<<p.m_A;
}

int Person::GetPriA(){
	return m_A;
}

int Person::GetPriB(){
	return m_B;
}

void test1(){
	Person p(10,10);

	cout << p << endl << "YhMjQx" << endl;//这行代码有误，也不知道怎么回事

	//cout << "m_A= " << p.GetPriA() << endl;
	//cout << "m_A= " << p.GetPriA() << endl;

}

int main(){
	test1();
	return 0;
}