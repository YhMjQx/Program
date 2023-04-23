#include<iostream>
using namespace std;

class Base{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
	//
};

//利用开发人员命令提示符查看对象模型
//跳转盘符：（前提是看提示的盼复和文件所对应的盘符是否是一个磁盘，如果是就不需要此操作了，如果不是就）盘符:
//跳转文件路径 cd 具体路径下
//查看命名
//c1 /d1 reportSingleClassLayout类名 文件名

class Son :public Base{
public:
	int m_D;
	//在父类中所以非静态成员都会被子类继承下来
	//父类中私有的成员属性被编译器隐藏了，所以访问不到，但是事实上的确是继承下去了

};

void test1(){
	cout << "sizeof(Son)=  " << sizeof(Son) << endl; //  -  16
}

int main(){
	test1();
	return 0;
}