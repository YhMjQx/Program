#include<iostream>
#include<map>
using namespace std;

//map容器默认排序规则为按照key值进行从小到大排序，掌握如何改变排序规则，通过仿函数，可以改变排序规则
//注意这一点，要想使用自己定义的排序规则，那么自己定义的排序规则一定要在最前面
class MyCompare{
public:
	bool operator()(int a, int b){
		return a > b;
	}
};

void Printmap(map<int, int, MyCompare>& m){
	for (map<int, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); ++it){
		cout << "key值：" << (*it).first << " value值：" << it->second << endl;
	}
	cout << "---------------------" << endl;
}


void test1(){
	//创建一个map容器
	map<int,int,MyCompare> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));
	
	//for (map<int, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); ++it){
	//	cout << "key值：" << (*it).first << " value值：" << it->second << endl;
	//}
	Printmap(m);
}

int main(){
	test1();

	return 0;
}