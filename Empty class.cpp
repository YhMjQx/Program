#include<iostream>
using namespace std;
class Empty{
public:
	Empty* operator&(){
		cout << "取址运算符" << endl;
		return this;
	}
	Empty* operator&(){
		cout << "取const地址运算符" << endl;
		retunr this;
	}
};
int main(){
	Empty e1;
	Empty* p1 = &e1;

	const Empty e2;
	const Empty* p2 = &e2;

	cout << sizeof(Empty) << endl;
	//说明空类也是有一个字节的
	return 0;
}
//空类默认产生的成员：

//Empty();//默认构造函数
//Empty(const Empty& other);//默认拷贝构造函数
//~Empty();//默认析构函数
//Empty& operator=(const Empty& other);//默认等号运算符
//Empty* operator&();//默认取值运算符
//const Empty* operator&()const;//const型的默认取值运算符
