#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

//merge(iterator beg1, iterator end1, iterator bed2, iterator end2, iterator dest);
//容器元素合并，并存储到另一个容器中
//注意：两个容器必须是有序的
//beg1 - 容器1开始迭代器
//end1 - 容器1结束迭代器
//beg2 - 容器2开始迭代器
//end2 - 容器2结束迭代器
//dest - 目标迭代器开始迭代器

void MyPrint(int val){
	cout << val << " ";
}

void test1(){

	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
		v2.push_back(i);
	}

	vector<int>vTarge;
	//记住：一定要给vTarge开辟新的空间
	vTarge.resize(v1.size() + v2.size());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarge.begin());
	for_each(vTarge.begin(), vTarge.end(),MyPrint);
	cout << endl;
	//新生成的vTarge还是一个有序序列


}

int main(){
	test1();

	return 0;
}