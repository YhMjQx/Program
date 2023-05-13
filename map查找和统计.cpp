#include<iostream>
#include<map>
using namespace std;

//find(key); -- 查找key是否已经存在，返回该键的元素的迭代器，若不存在，返回map.end();
//count(key); -- 统计key的元素个数

void Printmap(map<int, int>& m){
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); ++it){
		cout << "key值：" << (*it).first << " value值：" << it->second << endl;
	}
	cout << "---------------------" << endl;
}

void test1(){
	//创建一个map容器
	map<int, int> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));
	m.insert(make_pair(5, 50));
	m.insert(make_pair(5, 50));


	map<int,int>::iterator pos = m.find(3);//查找key值为3 的元素
	if (pos != m.end()){
		cout << "找到了元素 key= " << (*pos).first << " value= " << pos->second << endl;
	}
	else{
		cout << "没找到" << endl;
	}

	//统计
	cout<<"统计到 "<<m.count(5)<<" 个key为5的元素"<<endl;//结果还是1
	//说明map也是不允许插入key值相同的元素，所以对于map容器来说count结果只有0或1
	//那么count一般就用于multimap容器中


}

int main(){
	test1();

	return 0;
}