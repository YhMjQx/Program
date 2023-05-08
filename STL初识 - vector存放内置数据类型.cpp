#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//vector容器存放内置数据类型
void Printvector(int val){
	cout << val << endl;
}

void test1(){
	vector<int> v;

	//向容器中插入数据
	for (int i = 10; i <= 50; i += 10){
		v.push_back(i);
	}


	////第一种遍历方式
	////通过迭代器来访问容器中的数据
	//vector<int>::iterator itBegin = v.begin();//itBegin 指向容器中的第一个元素
	//vector<int>::iterator itEnd = v.end();//itend指向容器中的最后一个元素的下一个位置
	//while (itBegin != itEnd){
	//	cout << *itBegin << " ";
	//	++itBegin;
	//}
	//cout << endl;


	////第二种遍历方式
	//for (vector<int>::iterator it = v.begin(); it < v.end(); ++it){
	//	cout << *it << " ";
	//}
	//cout << endl;


	//第三种遍历方式 利用STL提供的遍历算法
	for_each(v.begin(), v.end(), Printvector);//使用了回调函数

}

int main(){
	test1();
	return 0;
}
