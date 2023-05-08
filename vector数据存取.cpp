#include<iostream>
#include<vector>
using namespace std; 

//at.(int idx);//返回索引idx所指的数据
//operator[];//返回索引idx所指的位置
//front();//返回容器中第一个数据的元素
//back();//返回容器中最后一个元素

void test1(){
	vector<int>v1;
	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
	}

	//利用for循环的方式来遍历数组
	//利用[]来访问数组成员
	for (int i = 0; i < v1.size(); ++i){
		cout << v1[i] << " ";
	}
	cout << endl;
	//利用at来访问数组成员
	for (int i = 0; i < v1.size(); ++i){
		cout << v1.at(i) << " ";
	}
	cout << endl;

	//返回数组第一个元素
	cout << v1.front() << endl;
	//返回数组最后一个元素
	cout << v1.back() << endl;

}

int main(){
	test1();
	return 0;
}