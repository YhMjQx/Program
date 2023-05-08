#include<iostream>
#include<string>
#include<vector>
using namespace std;



void test1(){
	vector<vector<int>>v;

	//先创建小容器，然后给小容器插入数据
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	vector<int>v5;

	for (int i=0;i<5;++i){
		v1.push_back(i);
		v2.push_back(i + 1);
		v3.push_back(i + 2);
		v4.push_back(i + 3);
		v5.push_back(i + 4);
	}

	//现在将小容器插入大容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	//利用迭代器遍历大容器
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); ++it){
		//这里就会执行5次大的for循环，分别代表的是v1，v2，v3，v4，v5
		//然后再用一个for循环来遍历每一个小的容器
		//(*it) - vector<int>
		for (vector<int>::iterator jt = (*it).begin(); jt != (*it).end(); ++jt){
			cout << (*jt) << " ";
		}
		cout << endl;
	}

}

int main(){
	test1();
	return 0;
}