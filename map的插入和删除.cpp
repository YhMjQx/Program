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

void Printmap(map<int, int>& m){
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); ++it){
		cout << "key值：" << (*it).first << " value值：" << it->second << endl;
	}
	cout << "---------------------" << endl;
}

void test1(){
	//创建一个map容器
	map<int, int> m;

	//插入
	//第一种：
	m.insert(pair<int, int>(1, 10));

	//第二种
	m.insert(make_pair(2, 20));

	//第三种
	m.insert(map<int, int>::value_type(3, 30));

	//第四种
	//[]的方式并不建议用来插入，但可以用来索引
	m[4] = 40;
	//cout << m[4] << endl;
	//cout << m[5] << endl;//所以这里就会先创建key值为5的元素，然后输出钙元素的value值
	//实际上m容器中并没有key值为5的元素，但这里我要打印，他就会帮我创建一个key值为5的元素，并且以0作为value值

	Printmap(m);

	//删除
	m.erase(m.begin());
	Printmap(m);

	m.erase(4);//注意，这里是按照key值来删除
	Printmap(m);

	//m.erase(m.begin(), m.end());//清空
	m.clear();
	Printmap(m);

}

int main(){
	test1();

	return 0;
}