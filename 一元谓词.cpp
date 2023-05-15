//谓词概念；
//返回bool类型的仿函数称为谓词
//如果operator()接受一个参数，那么就叫做一元谓词
//如果operator()接收两个参数，那么就叫做二元谓词
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class FindGreaterFine{
public:
	bool operator()(int val){
		return val > 5;
	}
};

void test1(){
	vector<int>v;
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}

	FindGreaterFine fgf;
	vector<int>::iterator pos = find_if(v.begin(), v.end(), fgf);//这里的第三个参数就是一个谓词
	//find_if(v.begin(), v.end(), FindGreaterFine());//这里的第三个参数就是一个谓词,这个是一个匿名函数对象

	//find_if会返回一个迭代器,如果找到了就返回该位置的迭代器，如果没找到就返回end()
	if (pos != v.end()){
		cout << "找到了大于5的第一个数字为： " << *pos << endl;
	}
	else{
		cout << "没找到大于5的数字" << endl;
	}
}

int main(){
	test1();

	return 0;
}