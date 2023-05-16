#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//查找指定元素是否存在
//bool binary_search(iterator beg, iterator end, value); 
//查找指定元素，找到返回true，没找到返回false
//注意：在无序序列中不可用

void test1(){
	
	vector<int >v;
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}
	//v.push_back(0);
	//binary_serach所查找的序列不能是无序序列
	bool ret = binary_search(v.begin(), v.end(), 9);

	if (ret == true){
		cout << "找到了" << endl;
	}
	else{
		cout << "未找到" << endl;

	}

}

int main(){
	test1();

	return 0;
}