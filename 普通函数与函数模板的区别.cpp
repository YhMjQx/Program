//普通函数与函数模板的区别：
//1.普通函数在调用时可以发生自动类型转换（隐式类型转换）
//2.函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换(因为自动类型推导时需要保持数据类型一致)
//3.如果利用显式指定类型的方式，可以发生隐式类型转换

#include<iostream>
using namespace std;

int Add(int a, int b){
	return a + b;
}

template<typename T>
T ADD(T a, T b){
	return a + b;
}


void test1(){
	int a = 10;
	int b = 20;

	char ch = 'c';
	cout << Add(a, b) << endl;
	cout << Add(a, ch) << endl;//a - 97 ;c - 99
	//字符型隐式类型转换为整形的时候，会使用其ASCII码值

	//自动类型推导
	cout << ADD(a, b) << endl;
	//cout << ADD(a, ch) << endl; - error

	//显式指定类型
	cout << ADD<int>(a, ch) << endl;
	//在这里就直接指定a , ch要是整形的，所以会自动将ch转换为整形
}

int main(){
	test1();
	return 0;
}