#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//copy(iterator beg, iterator end, iterator dest);
//原容器起始迭代器  原容器结束迭代器  目标容器起始迭代器
//容器内指定范围的元素拷贝到另一容器中
//按值查找元素，找到就返回指定位置的迭代器，找不到就返回结束位置迭代器

void Print(int val){
	cout << val << " ";
}

void test1(){
	vector<int>v1;
	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
	}

	vector<int>v2;
	//注意注意注意！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
	//一定要给v2开辟空间，不然写出bug，你就完蛋了！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
	/*v2.resize(v1.size());*/
	v2 = v1;
	//等号赋值的确是可以将一个容器的容量和大小全部赋给另一个容器，但是拷贝就不一样了

	//copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), Print);
	cout << endl;
}

int main(){
	test1();

	return 0;
}