//set容器：
//所有元素在插入时都会被排序
//本质： 
//set/multiset属于关联式容器，底层采用的是二叉树实现
//
//set和multiset的区别：
//set不允许容器中有重复的元素存在
//multiset允许容器中有重复的元素存在

//set插入数据的同时会返回插入结果，表示插入成功
//multiset不会检测数据，因此可以插入重复数据
#include<iostream>
#include<set>
using namespace std;

void Printset(set<int>& s){
	for (set<int>::const_iterator it = s.begin(); it != s.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	set<int>s1;
	//用对组接收一下这个插数据的时候是否插成功了
	pair<set<int>::iterator,bool> ret = s1.insert(30);

	//ret.second - 意识就是pair<set<int>::iterator,bool>当中的bool，检查是否插入数据成功
	if (ret.second){
		cout << "插入成功" << endl;
	}
	else{
		cout << "插入失败" << endl;
	}

	ret = s1.insert(30);
	if (ret.second){
		cout << "插入成功" << endl;
	}
	else{
		cout << "插入失败" << endl;
	}
	//insert函数会返回一个迭代器类，而这个迭代器又是由set的迭代器和bool值确定的,这个bool值就是用来判断是否插数据成功率

	multiset<int>ms;
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); ++it){
		cout << *it << endl;
	}
		 
}


int main(){
	test1();

	return 0;
}
