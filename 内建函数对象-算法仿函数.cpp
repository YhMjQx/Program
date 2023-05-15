//内建函数对象
//概念：
//STL内建了一些函数对象
//分类：
//算法仿函数
//关系仿函数
//逻辑仿函数
//用法：
//这些仿函数所产生的对象，用法和一般的函数相同
//使用内建函数对象，需要引入头文件#include<functional>

#include<iostream>
#include<functional>
using namespace std;

//template<class T> T negate<T> 一元仿函数 取反仿函数
//template<class T> T plus<T> 二元仿函数 加法
//template<class T> T minus<T> 二元仿函数 减法
//template<class T> T multiplies<T> 二元仿函数 乘法仿函数
//template<class T> T divides<T> 二元仿函数  除法仿函数
//template<class T> T modulus<T> 二元仿函数 取模仿函数

void test1(){
	//说明这些都是函数模板
	negate<int>n;
	//取反函数

	cout << n(50) << endl;

}

void test2(){
	plus<int>p;
	cout << p(10, 20) << endl;

}

int main(){
	//test1();
	test2();
	return 0;
}