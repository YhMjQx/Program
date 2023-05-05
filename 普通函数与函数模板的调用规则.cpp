#include<iostream>
using namespace std;
//调用规则如下：
//1.如果函数模板和普通函数都可以调用，优先调用普通函数
//2.可以通过空模板参数列表来强制调用函数模板
//3.函数模板也可以发生函数重载
//4.如果函数模板可以产生更好的匹配，优先调用函数模板

void myPrint(int a, int b){
	cout << "调用普通函数" << endl;
}

template<typename T>
void myPrint(T a, T b){
	cout << "调用函数模板" << endl;
}
template<typename T>
void myPrint(T a, T b,T c){
	cout << "调用重载函数模板" << endl;
}



//void myFunc(int a, int b);/*{
//	cout << "调用普通函数" << endl;
//}*/
//
//template<typename T>
//void myFunc(T a, T b){
//	cout << "调用函数模板" << endl;
//}


void test1(){
	int a = 10;
	int b = 20;

	//myPrint(a, b);//调用普通函数

	myPrint<>(a, b);
	myPrint(a, b, 39);

	char c = 'c';
	char d = 'd';

	myPrint(c, d);//如果调用普通函数的话，会发生额隐式类型转换，有可能数据会发生改变，还不如直接推导出T为char呢
}

//void test2(){
//	int a = 10;
//	int b = 20;
//
//	myFunc(a, b);//会报错，因为想要调用普通函数，但是普通函数没实现
//}


int main(){

	test1();
	//test2();
	return 0;
}