#include<iostream>
#include<list>
using namespace std;

//list容器的迭代器不支持随机访问，只能前移和后移，list不是连续的空间，所以不能用at或者[]访问元素
//

void test1(){
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);

	cout << "l1的第一个数据为： " << l1.front() << endl;
	cout << "l1的最后一个数据为： " << l1.back() << endl;

	list<int>::iterator it = l1.begin();
	it++;
	it--;
	//list的迭代器支持前移和后移，但是不支持跳跃式访问
	//it = it + 2; - error


}

int main(){
	test1();

	return 0;
}