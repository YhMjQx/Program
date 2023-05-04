#include<iostream>
using namespace std;

//交换两个int型数据
void SwapInt(int& a,int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//交换两个浮点型数据
void SwapDouble(double& a, double& b){
	double temp = a;
	a = b;
	b = temp;
}

//C++中有很多数据类型，每一个类都可以当做是一个数据类型
//所以数据交换函数需要用一个函数模板来实现，这样才方便
template<typename T>
//声明一个模板，告诉编译器，接下来紧跟着的T不要报错，T是一个通用数据类型
//template - 声明创建模板
//typename - 表明其后面的符号是数据类型，可以用class代替
//T - 通用的数据类型，名称可以替换，通常为大写字母
void MySwap(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}

void test1(){
	int a = 10;
	int b = 20;
	//SwapInt(a, b);

	//函数模板调用有两种方式
	//1.自动类型推导
	//此时必须推导出一致的数据类型，也就是说，穿进去的两个数据的类型一定要一样
	MySwap(a, b);
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;

	//2.显式指定类型
	//函数模板的内容当中必需要确定出T的数据类型，才可以使用
	MySwap<int>(a, b);
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
}

int main(){
	test1();
	return 0;
}