#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//adjacent_find(iterator beg, iterator end);
//查找相邻重复元素，返回相邻元素的第一个位置的迭代器


void test1(){
	vector<int>v;
	v.push_back(2);
	v.push_back(0);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);

	v.push_back(1);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);

	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos == v.end()){
		cout << "没找到相邻重复元素";
	}
	else{
		cout << "找到了相邻重复元素：" << *pos << endl;
	}
	cout << *(++pos) << endl;//这句代码就可以验证返回的迭代器是相邻重复元素的第一个元素的迭代器

}

int main(){
	test1();

	return 0;
}