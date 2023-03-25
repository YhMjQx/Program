#include<iostream>
using namespace std;
void fun(int& refval){
	cout << "fun=" << refval << endl;
}
int main(){
	//1.const_cast<>()用来移除常量性
	//2.const_cast<>()一般是对指针和引用使用
	//3.const_cast<>()去除常量性不是为了修改他所指向的内容
	//4.const_cast<>()去除常量性（const）是为了函数能够接受实参
	//5.<>中必须是指针，引用，或者是指向对象类型成员的指针
	const int val = 39;
	//int n = const_cast<int>(val);
	//error这句话没有任何意义，const int去掉const就又变成了int，再用int接收没有任何意义

	//int* p = &val; - const int* 类型的值不能用于初始化int*类型的值
	int* p = const_cast<int*>(&val);
	//&val本来应该是const int*，然后现在转换过后就是int*
	*p = 93;
	cout << "val=" << val << endl;//结果还是39，这也验证了第3点
	cout << "p=" << p << endl;
	cout << "&val=" << &val << endl;
	//这说明p和&val是一样的，但是的确不能通过指针来改变val的值
	//fun(val);error - 无法将const常量传给非const引用
	fun(const_cast<int&>(val));//结果是93
	//由于我已经通过p将val改变了，但是实际上val并没有改变，而在这里输出结果却发生了改变
	//我自己的理解是：
	//本来的val的确没有改变，但是还有一个p的地址和val的地址是一样，那么经过函数调用之后
	//有没有可能，引用的并不是真正的val，而是函数形参作为*p的别名，而*p和&val共用同一块空间
	//即：函数传参时，引用初始化的对象的*p而不是val，故，val没有改变，*p发生了改变
	cout << "val=" << val << endl;//结果还是39，这也验证了我自己的想法

	return 0;
}