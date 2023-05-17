#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<ctime>
using namespace std;

//sort											//对容器内元素进行排序
//random_shuffle(iterator beg,iterator end);	//洗牌，指定范围内的元素随机调整次序
//merge											//容器元素合并，并存储到另一个容器中
//reverse										//反转指定范围内的元素

void MyPrint(int val){
	cout << val << " ";
}

void test1(){
	//sort的基本用法我们都知道了
	//在这里使用一下一个不清楚的知识点
	vector<int>v;
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}
	//由于sort是默认的升序排序，而现在v中已经是升序了，所以我现在不用使用升序
	//我希望在不自己实现谓词和函数的情况下，实现sort的降序
	//greater - 是头文件中包含的一个模板，其实就相当于我们写的降序谓词
	sort(v.begin(), v.end(), greater<int>());

	//for (vector<int>::iterator it = v.begin(); it != v.end(); ++it){
	//	cout << *it << " ";
	//}
	//cout << endl;
	//以后就用下面这句代码代替for循环输出了
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

void test2(){
	//可以提供一个随机数种子，以防止每次打乱顺序的结果都是一样的
	srand((unsigned int)time(NULL));
	
	vector<int>v;
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

int main(){
	//test1();
	test2();
	return 0;
}