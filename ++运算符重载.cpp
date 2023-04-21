#include<iostream>
using namespace std;

//
class MyInteger{
public:
	friend ostream& operator<<(ostream& cout, MyInteger& myint);

	MyInteger(int num) :m_Num(num){

	}

	//重载前置++运算符
	MyInteger& operator++(){
		//先进行加加操作
		m_Num++;
		//再将自身（引用）做返回，目的是为了多次++都是在对同一个数据进行操作
		//因为如果返回的是一个新的对象，那么同时的第二次++操作就是对一个新的对象的数据进行操作，而不是一直对同一个数据
		return *this;
	}


	//重载后置++运算符
	//int - 代表的是一个占位参数，用以区分前置++和后置++
	//注意，如果是后置++，返回的一定是一个值，为什么呢？
	//因为后置++的需求是要求我们返回一个局部对象，这是后置++的作用需求
	//而一旦返回的是局部对象，那么一出函数体，该局部对象就会被销毁，然后将该引用赋给了另一个对象，另一个对象销毁时又会对该空间销毁，就会报错
	//所以，返回一个不是引用的对象，通过拷贝构造函数构造一个新的对象然后返回
	MyInteger operator++(int){
		//先 记录当时的结果
		MyInteger temp = *this;//将未++之前的自身赋给temp
		//后 ++操作
		m_Num++;
		//最后 将记录的结果返回
		return temp;
	}
private:
	int m_Num;
};

//重载左移运算符
ostream& operator<<(ostream& cout, MyInteger& myint){
	cout << myint.m_Num;
	return cout;
}


void test1(){
	MyInteger myint(0);
	cout << myint << endl;
	cout << ++myint << endl;
	cout << ++(++myint) << endl;
	cout << myint << endl;

}

void test2(){
	MyInteger myint(0);
	cout << myint++ << endl;
	cout << myint << endl;
}


int main(){
	//test1();
	test2();
	return 0;
}