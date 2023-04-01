#include<iostream>
using namespace std;
class Date{
public:
	Date(int year) :year_(year){

	}
	static bool IsLeapYear(int year){
		return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	}
	bool IsLeapYear(){
		return ((year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0));
	}
private:
	int year_;
};
int main(){
	Date d = 2022;
	cout << d.IsLeapYear() << endl;

	cout << Date::IsLeapYear(2023) << endl;
	return 0;
}
//对于特定类型的全体对象而言，有时候可能需要访问一个全局的变量。
//比如说统计某种类型对象已创建的数量
//如果我们用全局对象会破坏数据的封装，一般的用户代码都可以修改这个全局变量，
//这时我们可以用类的静态成员来解决这个问题
//非static数据成员存在于类类型的每个对象中，static数据成员独立该类的任意对象存在，
//它是与类关联的对象，不类对象关联
//非static成员属于类对象，每个对象都有一份拷贝


//static成员的优点：
//1.static成员的名字实在累得作用域中，因此可以避免与其他类成员或全局对象名字冲突
//2.可以实施封装，static成员可以是私有的，而全局对象不可以
//3.阅读程序容易看出static成员与某个类相关联，这种可见性可以清晰地反映程序员的意图
//static静态成员函数，不需要构造对象，就能直接访问并使用，不需要直接与对象相关联

//静态成员函数不能访问非静态数据成员
//1.static成员函数没有this指针
//2.非静态成员函数可以访问静态成员
//3.static静态成员函数不可以访问非静态成员（包括非静态成员函数）
