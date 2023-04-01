//单例模式是设计模式的一种，其保证一个类只有一个实例，并提供一个全局访问点，而且禁止拷贝
//实现这个单例模式，但是线程不安全
//将默认构造函数设为私有的,此时需要设定一个全局的接口，禁止拷贝，禁止赋值
#include<iostream>
using namespace std;
class Singleton{
public:
	//由于我把构造函数放在了private当中，所以main函数里无法实例化，所以我在public当中就需要创建一个接口，来进行初始化

	//返回引用
	static Singleton& GetInstance(){
		static Singleton Instance;	//局部静态对象
		return Instance;
	}

	~Singleton(){
		cout << "~Singleton" << endl;
	}
private:
	Singleton(const Singleton& other);
	Singleton& operator=(const Singleton& other);
	//为了禁止拷贝，那么就需要将拷贝构造函数声明为私有的，并且不提供实现
	//为了禁止拷贝，那么就需要将等号运算符声明为私有的，且也不提供实现

	//只需要将构造函数声明为私有的，那么main就不能调用构造函数

	Singleton(){
		cout << "Singleton..." << endl;
	}

};


int main(){
		//这里的引用是不能省略的
	Singleton& s1 = Singleton::GetInstance();
	Singleton& s2 = Singleton::GetInstance();
		//虽然调用了两次GetInstance，但是只构造了一个对象

	return 0;
}