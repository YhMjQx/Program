//单例模式是设计模式的一种，其保证一个类只有一个实例，并提供一个全局访问点，而且禁止拷贝
#include<iostream>
using namespace std;
class Singleton{
public:
	//由于我把构造函数放在了private当中，所以main函数里无法实例化，所以我在public当中就需要创建一个接口，来进行初始化
	static Singleton* GetInstance(){
		if (Instance_ == NULL){
			{
				Instance_ = new Singleton;
			}
			return Instance_;
		}
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
			//既然外部没法访问这个构造函数，那么我们就需要创建一个全局的访问点
	Singleton(){
		cout << "Singleton..." << endl;
		cout << Instance_ << endl;
	}
	//static void Free(){
	//	if (Singleton::Instance_ != NULL){
	//		delete Instance_;
	//	}
	//为了防止最后不调用析构函数导致内存泄漏，我们可以选择这种形式，但是这种形式很不方便，需要自己手动插入
	//}
	class Garbo{
	public:
		~Garbo(){
			if (Singleton::Instance_ != NULL){
				delete Instance_;
			}
		}
	};

	static Singleton* Instance_;	//这是声明
	static Garbo garbo_;	//利用对象的确定性析构，由于SIngleton实例化不会调用析构函数
							//所以我用了garbo_这个数据成员，该数据成员是Garbon类类型的
							//garbo_除了生存期一定会销毁调用析构函数，
};

Singleton* Singleton::Instance_;	//这是定义
Singleton::Garbo Singleton::garbo_;

int main(){
	//Singleton s1;
	//Singleton s2;
	Singleton* s1 =  Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();
			//我们会发现只调用了一次构造函数，虽然调用了两次GetInstance，实际上只构造了一个对象
			//如果没有Garbo这个类的话，就不会调用析构函数

	return 0;
}