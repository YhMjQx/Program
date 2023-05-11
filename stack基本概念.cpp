//栈底是高地址，且栈不允许被遍历
#include<iostream>
#include<stack>
using namespace std;

void test1(){
	//栈 - 符合先进后出
	stack<int>s;

	//入栈
	s.push(10);
	s.push(20);
	s.push(39);
	s.push(39);
	s.push(10);

	cout << "栈的元素个数： " << s.size() << endl;

	while(!s.empty()){
		//如果栈不是空，就查看栈顶的数据，并执行出栈
		cout << "栈顶数据为： " << s.top() << endl;
		//出栈
		s.pop();
		//查看栈的元素个数
		cout << "栈的元素个数： " << s.size() << endl;
		cout << "------------------------" << endl;
	}



}

int main(){
	test1();

	return 0;
}
