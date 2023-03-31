#include<iostream>
using namespace std;
//特殊的整形static const成员：
//整形static const成员可以在类定义体中初始化
class Test{
public:
	Test(){

	}
	~Test(){

	}
	static const int num_ = 40;	//静态成员的引用性说明，只有static const int型的成员才可以在这里初始化，当然char也可以
};

//const int Test::num_;	//静态成员的定义性说明
int main(){
	cout << Test::num_ << endl;
	return 0;
}