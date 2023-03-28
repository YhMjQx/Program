#include"Clock.h"
//下面的类是为了方便检测语法，所以放在了该文件内，一般情况下我们都要将它分为工程编程
class Object
{
public:
	Object() 
	{
		cout << " ... Object ... " << endl;
	}
	~Object(){
		cout << " ... ~Object ..." << endl;
	}
private:
	int num_;
};
class Container
{
public:
	//如果上面不提供默认构造函数，这里就无法执行
	Container(){
		cout << " ... Container ..." << endl;
	}
	~Container(){
		cout << " ... ~Container ..." << endl;
	}
private:
	//创建一个子类对象
	Object obj_;
};
int main(){
	//Clock c(10, 10, 10);
	//c.Display();
	Container c;
	//既然要创建Container的对象你，那么就要给该对象分配内存，但该对象又包含了
	//Object这个类，所以就要先创建Object这个类创建的对象
	return 0;
}