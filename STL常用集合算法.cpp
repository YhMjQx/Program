#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//set_intersection(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);//求两个容器交集
//求交集的的两个容器必须是两个有序序列
//目标容器开辟空间的时候需要从两个确认中找出较小的一个
//set_intersection返回的迭代器是交集中最后一个元素的位置，不是目标容器的结束位置

//set_union(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);//求两个容器并集
//求并集的的两个容器必须是两个有序序列
//目标容器开辟空间的时候需要开辟两个容器大小之和
//set_union返回的迭代器是并集中最后一个元素的位置，不是目标容器的结束位置

//set_difference(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);//求两个容器差集
//求差集的的两个容器必须是两个有序序列
//目标容器开辟空间的时候需要开辟两个容器中较大的一个空间
//set_difference返回的迭代器是差集中最后一个元素的位置，不是目标容器的结束位置


void Print(int val){
	cout << val << " ";
}

void test1(){
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
	}

	for (int i = 5; i < 15; ++i){
		v2.push_back(i);
	}

	vector<int>vTarget;
	vTarget.resize(min(v1.size(), v2.size()));

	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	//for_each(vTarget.begin(), vTarget.end(), Print);

	for_each(vTarget.begin(), itEnd, Print);
	cout << endl;

}

void test2(){
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, Print);
	cout << endl;
}

void test3(){
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>vTarget;
	vTarget.resize(max(v1.size(), v2.size()));

	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	cout << "v1对v2的差集为：" << endl;
	for_each(vTarget.begin(), itEnd, Print);
	cout << endl;

	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	cout << "v2对v1的差集为：" << endl;
	for_each(vTarget.begin(), itEnd, Print);
	cout << endl;

}

int main(){
	//test1();
	//test2();
	test3();
	return 0;
}