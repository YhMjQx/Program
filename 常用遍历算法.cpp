//算法主要是由头文件<algorithm><functional><numeric>组成
//<algorithm>是所有STL头文件中最大的一个，范围涉及到比较，交换，查找，遍历，复制，修改等等
//<numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
//<functional>定义了一些模板类，用以声明函数对象
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void Print1(int val){
	cout << val << " ";
}

class Print2{
public:
	void operator()(int val){
		cout << val << " ";
	}
};

class Transform{
public:
	int operator()(int v){
		return v + 39;
	}
};

void test1(){
	vector<int>v;

	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), Print1);
	cout << endl;
	for_each(v.begin(), v.end(), Print2());
	cout << endl;

	vector<int>vTarget;

	vTarget.resize(v.size());
	
	//transform( 原容器起始位置，原容器最终位置，目标容器起始位置，映射方式(可以有加减乘除取反之类的，这些可以内建函数对象))
	transform(v.begin(),v.end(), vTarget.begin(), Transform());
	for_each(vTarget.begin(), vTarget.end(), Print1);
	cout << endl;

}

int main(){
	test1();
	
	return 0;
}