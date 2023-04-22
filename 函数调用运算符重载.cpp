#include<iostream>
#include<string>
using namespace std;

//打印输出类
class MyPrint{
public:
	MyPrint(string name) :m_name(name){

	}

	//函数调用运算符重载是很灵活的，他是根据我们的需求来重载的，就比如说这里，我需要输出字符很惨，那我的实现就是输出字符串
	//但是别的需求可能就不一样了，那么我们就需要重新实现重载
	void operator()(string name){
		cout << name << endl;
	}

	string m_name;
};

void test1(){
	MyPrint myprint("YhMjQx");

	myprint.operator()(myprint.m_name);
}

int main(){
	test1();
	return 0;
}