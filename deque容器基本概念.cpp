#include<iostream>
#include<deque>
using namespace std;

//deque容器 - 双端数组，可以对两头进行插入和删除造作
//deque与vector的区别：
//vector对于头部的插入删除效率低，数据量越大，效率越低
//deque相对而言，对头部的插入和删除速度比vector快
//vector访问元素时的速度比deque快，这和两者内部实现有关

//deque内部工作原理：
//deque内部有一个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
//中控器维护的是每段缓冲区的地址，使得deque使用像一片连续的空间
//deque的迭代器也支持随机访问

void PrintDeque(deque<int>& d){
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it){
		//const_iterator - 是为了防止对it所指向的内容进行改变
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	deque<int>d1;
	for (int i = 0; i < 10; ++i){
		d1.push_back(i);
	}
	PrintDeque(d1);

	deque<int>d2(d1.begin(), d1.end());
	PrintDeque(d2);

	deque<int>d3(10, 39);
	PrintDeque(d3);

	deque<int>d4(d3);//拷贝构造
	PrintDeque(d4);

}

int main(){
	test1();
	return 0;
}