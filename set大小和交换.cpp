//set容器：
//所有元素在插入时都会被排序
//本质： 
//set/multiset属于关联式容器，底层采用的是二叉树实现
//
//set和multiset的区别：
//set不允许容器中有重复的元素存在
//multiset允许容器中有重复的元素存在
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
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);
	s1.insert(30);

	set<int>s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);

	cout << "交换前：" << endl;
	Printset(s1);
	Printset(s2);
	cout << "-------------------" << endl;
	s1.swap(s2);
	cout << "交换后：" << endl;
	Printset(s1);
	Printset(s2);
}

int main(){
	test1();

	return 0;
}
