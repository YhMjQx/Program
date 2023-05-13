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
	s1.insert(39);

	Printset(s1);

	//查找
	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end()){
		cout << "找到元素：" << *pos << endl;
	}
	else{
		cout << "没找到元素" << endl;
	}
}

void test2(){
	multiset<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);
	s1.insert(30);
	s1.insert(39);


	//统计
	//对于set容器来说，count的结果永远都是0 或1，因为set容器存储是不会出现重复的
	//而multiset就不一样了
	cout << "s1中30的个数为： " << s1.count(30) << endl;
	cout << "s1中300的个数为： " << s1.count(300) << endl;


}

int main(){
	test1();
	test2();
	return 0;
}
