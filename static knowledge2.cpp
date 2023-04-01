#include<iostream>
using namespace std;
class Test{
public:
	Test(int num):num_(num){
		cout << "Test... " << num_ << endl;
	}
	~Test(){
		cout << "~Test... " << num_ << endl;
	}
private:
	int num_;
};

Test g1(39);	//全局对象的构建先于main函数
static Test g2(93);	//静态全局对象的构建先于main函数
int n;	//未初始化的全局变量默认值为0,此时未初始化的全局变量或者静态全局对象存储于.bss段
int n2 = 100;	//已初始化的全局变量或者静态全局变量存储于.data段
int main(){
	cout << "Entering main..." << endl;
	cout << n << endl;
	Test t1(1);	//栈对象，
	{
		Test t2(2);	//栈对象
	}

	{
		Test* t3 = new Test(3);	//堆上创建的对象需要显式释放
		delete t3;//作用域和生存期不等同，如果这里没有释放，那么t3只是出了作用域
		//其他的无法访问到t3而已，但t3的生存期还存在，因为他的数据都还没有释放
	}
	{
		//已初始化的静态局部变量存储于.data段中
		//未初始化的静态局部变量存储于.bss段中
		static int n3;	//存储于.bss段 编译期初始化
		static int n4 = 200;	//存储于.data段 编译期初始化

		static Test t4(300);	//存储于.data 段，t4对象在运行期初始化
	}
	cout << "Entering main..." << endl; 
	return 0;
}