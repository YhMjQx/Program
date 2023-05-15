//函数对象的概念：
//重载函数调用操作符的类，其对象常称为函数对象
//函数对象使用重载的()，行为类似函数调用，也叫仿函数
//本质：
//函数对象就是一个类，不是函数
//
//函数对象的使用：
//特点：
//1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
//3.函数对象可以作为参数传递
#include<iostream>
#include<string>
using namespace std;

class MyAdd{
public:
	int operator()(int a,int b){
		return a + b;
	}
};

class MyPrint{
public:
	MyPrint(){
		this->count = 0;
	}

	void operator()(string str){
		cout << str << endl;
		++this->count;
	}

	int count;

};


void test1(){
	MyAdd myadd;

	//1.函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
	cout << myadd(10, 20) << endl;
}

void test2(){
	//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
	MyPrint mp;
	mp("YhMjQx");
	mp("YhMjQx");
	mp("YhMjQx");
	mp("YhMjQx");

	cout << "myprint调用次数为：" << mp.count << endl;
}



void doPrint(MyPrint& mp,string str){
	mp(str);
}

void test3(){
	//3.函数对象可以作为参数传递 - 这一点更多的是用在容器排序的时候改变容器排序规则
	//或者容器传自定义数据类型的时候需要排序，这时需要自己写一个仿函数来作为这个自定义数据类型专属的排序规则
	MyPrint mp;
	doPrint(mp,"YhMjQx");

}

int main(){
	//test1();
	//test2();
	test3();
	return 0;
}