#include<iostream>
#include<list>
using namespace std;

void PrintList(const list<int>& L){
	for (list<int>::const_iterator it = L.begin(); it != L.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	//创建一个list容器
	list<int>L1;

	//添加数据
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);

	PrintList(L1);

	//list<int>::const_iterator it = L1.begin();
	//it = it + 2;
	//it += 2;
	//it = L1.begin()+2;
	//从这几句代码就可以知道，it可以加加，但不能跳跃式加减


	//区间形式构造
	list<int>L2(L1.begin(), L1.end());
	PrintList(L2);

	//拷贝构造
	list<int >L3(L1);
	PrintList(L3);

	//n个elem的形式构造
	list<int>L4(10, 39);
	PrintList(L4);


}

int main(){
	test1();

	return 0;
}