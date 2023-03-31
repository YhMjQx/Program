#include<iostream>
using namespace std;
//特殊的整形static const成员：
//整形static const成员可以在类定义体中初始化
class Test{
public:
	Test(int y):y_(y){

	}
	~Test(){

	}

	static void TestStaticFun(){
			//cout << "y_=" << y_ << endl; - error静态成员函数不能访问非静态成员（包括函数）
			//因为静态成员函数不含有this指针来指向某个对象，而y_是属于某个对象的，所以无法访问非静态成员
		cout << num_ << endl;//说明静态成员函数可以访问静态数据成员
	}
	void TestFun(){
		cout << "num_=" << num_ << endl;
		//非静态成员函数可以访问静态数据成员
		cout << "y_=" << y_ << endl;
	}
	static int num_;	//静态成员的引用性说明，只有static const int型的成员才可以在这里初始化，当然char也可以
	int y_;
};
int Test::num_ = 39;
//const int Test::num_;	//静态成员的定义性说明
int main(){
	Test::TestStaticFun();
		
	Test t(10);//在这里初始化的是t.y_
	t.TestFun();//非静态成员（包括函数）必须用在特定对象情况下
	cout << Test::num_ << endl;
	cout<< "sizeof(Test)=" << sizeof(Test) << endl;
	return 0;
}