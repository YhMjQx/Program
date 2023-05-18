#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
//#include<functional>
//算数生成算法属于小型算法，使用时包函头文件为#include<numeric>
using namespace std;

//accmulate(iterator beg, iterator end, value);
////计算容器元素累计元素总和
//fill(iterator beg,iterator end,value);
////向容器中添加元素

void Print(int val){
	cout << val << " ";
}

void test1(){
	vector<int>v;
	for (int i = 0; i <= 100; ++i){
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), Print);
	cout << endl;

	int total = accumulate(v.begin(), v.end(), 0);
	//第三个参数是 累加的 起始值
	cout << "total = " << total << endl;

	v.resize(106);
	fill(v.begin() + 101, v.end(), 39);
	for_each(v.begin(), v.end(), Print);
	cout << endl;
}

int main(){
	test1();

	return 0;

}