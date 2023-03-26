#include<iostream>
using namespace std;
int main(){
	//new运算符可以用于在堆上创建空间，相当于C语言中的malloc
	//new - 调用的时候先分配内存，然后调用构造函数
	//new operator - 分配内存 + 调用构造函数
	//operator new - 只分配内存
	//如果空间开辟成功，则返回首地址，如果没有开辟成功直接抛出异常，但是C语言中是返回NULL
	int *p1 = new int(39);//这是开辟了一个int型的数据空间,并且初始化为39
	cout << *p1 << endl;

	int *p2 = new int[10];//开辟了一个连续的10个整形的空间
	
	//记住，堆上开辟的空间需要我们自己去销毁，这是就用到了delete，相当于C语言中的free
	delete p1;
	delete[] p2;//注意，如果new的时候用到了[]，那么delete的时候也要有[]
	//delete - 调用的时候，先调用析构函数，然后释放内存
	return 0;
}