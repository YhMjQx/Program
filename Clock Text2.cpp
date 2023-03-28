#include"Clock.h"
//下面的类是为了方便检测语法，所以放在了该文件内，一般情况下我们都要将它分为工程编程
class Object
{
public:
	//那么如果我们不提供默认构造函数会怎样呢
	Object(int num) :num_(num)
	{
		cout << "Object " << num_ << endl;
	}
	~Object(){
		cout << "~Object " << num_ << endl;
	}
private:
	int num_;
};
class Container
{
public:
	//如果上面不提供默认构造函数，这里就无法执行
	Container(int obj1 = 0, int obj2 = 0) :obj2_(obj2) , obj1_(obj1)
		//这里没有传参，但是有初始化默认值，也就相当于给obj1初始化为0，给obj2初始化为0
	{
		cout << "Container ..." << endl;
	}
	~Container(){
		cout << "~Container ..." << endl;
	}
private:
	//如果不提供默认构造函数，在调用这里的时候，要想给obj初始化就没有办法，那么就只能在
	//Container类的构造函中直接给Object初始化
	Object obj1_;
	Object obj2_;
	//这是对象初始化的顺序，与构造函数初始化列表的顺序无关
};
int main(){
	//Clock c(10, 10, 10);
	//c.Display();
	Container c(10,39);
	//既然要创建Container的对象你，那么就要给该对象分配内存，但该对象又包含了
	//Object这个类，所以就要先创建Object这个类创建的对象
	return 0;
}