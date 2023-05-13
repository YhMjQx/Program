#include<iostream>
#include<list>
using namespace std;

//push back(elem);//在容器尾部加入一个元素pop_back0;//删除容器中最后一个元素
//push front(elem) ://在容器开头插入一个元素
//pop_front0 ://从容器开头移除第一个元素
//insert(pos, elem) ://在pos位置插elem元素的拷贝，返回新数据的位置。
//insert(pos, n, elem) ://在pos位置插入n个elem数据，无返回值。
//insert(pos, beg, end);//在pos位置插入[beg,end)区间的数据，无返回值
//clear()://移除容器的所有数据
//erase(beg,end)://删除[beg,end)区间的数据，返回下一个数据的位置
//erase(pos)://删除pos位置的数据，返回下一个数据的位置。
//remove(elem)://删除容器中所有与elem值匹配的元素。


void Printlist(list<int>&L){
	for (list<int>::const_iterator it = L.begin(); it != L.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	list<int>L1;
	
	//尾插
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	Printlist(L1);

	//头插
	L1.push_front(100);
	L1.push_front(200);
	Printlist(L1);

	//头删
	L1.pop_front();
	//尾删
	L1.pop_back();
	Printlist(L1);

	//insert插入
	list<int>::iterator it = L1.begin();
	L1.insert(it++, 39);
	Printlist(L1);
	//删除
	--it;//原来的it在插入之后还是指向插入之前的位置，也就是说即使插入了元素，但it的指向并不变
	L1.erase(it);
	Printlist(L1);

	//移除相同的数据
	L1.push_back(2000);
	L1.push_back(2000);
	L1.push_back(2000);
	Printlist(L1);
	L1.remove(2000);
	Printlist(L1);

	//清空
	L1.clear();
	Printlist(L1);


}

int main(){
	test1();

	return 0;
}