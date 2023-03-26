#include<iostream>
using namespace std;
#ifndef _TEXT_H_
#define _TEXT_H_
//内联函数也可以重载，函数重载的要求是要在相同作用域
//同理，内联函数的重载就是要在类内部
//隐含的this指针：
/*成员函数有一个隐含的附加形参，即，指向该对象的指针，这个隐含的形参叫做this指针
使用this指针保证了每个对象可以拥有不同的数据成员，但处理这些成员的代码（成员函数）可以被多有对象共享*/
class Text{
public:
	int Add(int a, int b){
		return a + b;
	}
	//这也是一种定义内联函数的方式，在这里即使没有inline关键字也可以
	void Init();
	void Init(int x);
	void Init(int x, int y);
	void Init(int x, int y, int z);
	//这些函数名称相同，参数数量不同，构成重载 

	//还可以用缺省参数来设计函数
	void Init(int x = 0, int y = 0, int z = 0);// 这是缺省参数的定义方式
	void Display();
private:
	int x_;
	int y_;
	int z_;
};
#endif //_TEXT_H_