//map基本概念：
//简介：
//map中的所有元素都是pair
//pair中的第一个元素为key（键值），起到索引作用，第二个元素为value(实值)
//所有元素都会根据元素的键值排序
//本质;
//map/multimap - 属于关联式容器，底层用二叉树实现
//优点：
//可以根据key值快速找到value值
//map和multimap的区别：
//map不允许容器中有重复key值元素
//multimap允许容器中有重复key值元素
#include<iostream>
#include<map>
using namespace std;

void Printmap(map<int,int>& m){
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); ++it){
		cout << "key值：" << (*it).first << " value值：" << it->second << endl;
	}
	cout << "---------------------" << endl;
}

void test1(){
	//创建一个map容器
	map<int, int> m;

	//会根据key的值自动升序存放在容器中
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(5, 50));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	
	Printmap(m);

	//拷贝构造，相当于是一种初始化
	map<int, int> m2(m);
	Printmap(m2);

	//直接赋值
	map<int, int>m3;
	m3 = m;
	Printmap(m2);

}

int main(){
	test1();

	return 0;
}