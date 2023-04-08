#include<vector>
#include<iostream>
#include<algorithm>//包含算法的头文件
using namespace std;
using std::vector;


typedef vector<int> INTVEC;//vector<int> - 这是一个类型
//void ShowVec1(const INTVEC& v){
//	unsigned int i = 0;
//	//用unsigned无符号的原因是因为size()的返回值对应的就是无符号整数
//	for (i = 0; i < v.size(); i++){
//		cout << v[i] << endl;
//	}
//	cout << endl;
//}
//
//void ShowVec2(INTVEC& v){
//	//利用迭代器来遍历容器（迭代器可以将它看作是面向泛型程序指针）
//	INTVEC::iterator it; //iterator - 这就是vector里面的一个迭代器
//	for (it = v.begin(); it != v.end(); ++it){
//		cout << *it << " ";
//	}
//	cout << endl;
//}

void ShowVec3(const INTVEC& v){
	//利用迭代器来遍历容器（迭代器可以将它看作是面向泛型程序指针）
	INTVEC::const_iterator it; //const_iterator - 这就是vector里面的一个常量迭代器
	for (it = v.begin(); it != v.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}
int main(){
	//string = basic_string<char>
	INTVEC v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);


	//ShowVec1(v);
	//ShowVec2(v);
	ShowVec3(v);

	//v.erase(v.begin() + 2);
	//ShowVec3(v);
	v.erase(v.begin(), v.begin() + 2);//凡涉及到迭代器的区间都是左闭右开区间
	ShowVec3(v);

	v.erase(remove(v.begin(), v.end(), 3),v.end());
	ShowVec3(v);
	return 0;
}