#include<iostream>
using namespace std;
void swap(int& x, int& y){
	//传值的时候只需要传值就行，不需要其他的我操作
	int tmp = x;
	x = y;
	y = tmp;
}
int main(){
	//引用传递是在函数定义时在形参前面加上引用运算符 &
	//本来函数传值是无法通过形参改变实参的，除非传地址
	//但是用引用就很好地解决了这个问题
	//引用作为实参对形参的任何操作都能改变相应的实参的数据，使函数变得简单又自然
	int a = 3;
	int b = 9;
	swap(a, b);//在函数调用传值的时候就会自动引用，相当于
	//int& x = a;    int& y = b;
	//因而，对x改变就是对a改变，对y改变就是对b改变
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	return 0;
}