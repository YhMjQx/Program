#include<iostream>
using namespace std;
//变量具有的性质：名称，空间
//引用，引用不是变量，引用仅仅是变量的别名
//引用没有自己的独立空间
//引用与它所引用的变量共享空间
//对引用所做的改变实际上是对他所引用的变量的改变
//引用在定义的时候要初始化
//引用一经初始化不能指向（引用）其他变量
int main(){
	int val = 39;
	int& refval = val;
	refval = 200;//虽说表面上改变的是引用，但实际上已经改变了val
	cout << "val=" << val << endl;

	int val2 = 500;
	refval = val2;
	//这不代表将refval引用至val2这个变量，仅仅只是代表将val2赋值给refval，实际上改变的还是val
	cout << "val=" << val << endl;

	return 0;
}