//this 指针概念
//每个非静态函数只会诞生一份代码实例，也就是说多个对象会共用一块代码
//this指针指向被调用的成员函数的所属对象
//this指针是隐含每一个非静态成员函数的一种指针
//this指针不需要定义，直接使用即可

//this指针的用途：
//1.当形参和成员变量重名时，可用this指针来区分 - 解决名称冲突	
//2.在类的非静态成员函数中返回对象本身，可用return *this;
#include<iostream>
using namespace std;
 
class Person{
public:
	Person(int age)/*:age(age)*/{
		//age = age;//当形参和成员变量重名时，如果不在构造函数的参数列表中进行初始化，那么编译器就无法对
		//成员变量真正的做出改变，当我们将光标放在这里的age上，我们会发现，函数体内和形参都是同一个阴影，说明编译器将这三个age认为是了同一个age
		//那么，这样就会报错，如果不想在参数列表中初始化的话，我们只能用this进行区分，如下：this->age = age;
		this->m_age = age;
	}

	Person& PersonAddAge(const Person& p){
		this->m_age += p.m_age;
		return *this;
		//this指向Person的对象，那么*this就是实例化之后的对象
		//记住，返回*this的时候，一定要将返回值设置为  类名&
		//如果不加 & 这个引用符号的话，最终返回的将会是通过拷贝构造函数重新构造的对象，而这个新对象的成员变量
		//就是被改变后的原对象，剩下的具体解释放在main的注释当中
	}

	int Getage(){
		return m_age;
	}
private:
	int age;
	int m_age;

};
int main(){
	Person p1(39);
	Person p2(10);

	p1.PersonAddAge(p2);
	cout << "p1的年龄为： " << p1.Getage() << endl;
	//这是给p2加了一次p1的年龄，那么如果我想要多加几次呢，该怎么做，
	//试想，我们应该用对象才能调用类内的成员函数，所以想要多调用PersonAddAge，我们应该让调用一次之后返回的是一个对象
	//那么，此时就用到了返回对象本身用*this

	p1.PersonAddAge(p2).PersonAddAge(p2).PersonAddAge(p2);
	//链式编程思想，如果该函数的返回值不是引用而是一个对象，那么p1.PersonAddAge(p2)这句代码会将p1的年龄增加后
	//赋给一个新的对象，然后返回这个新对象，这也是为什么我们看见不管在后面叠加多少代码，最终的结果都是那么多
	//所以，事实上第一次的p1的确是加上了p2的年龄
	//p1.PersonAddAge(p2).PersonAddAge(p2)这句代码就是p1的年龄加上p2的年龄返回一个新的对象1，然后给对象1加上p2的年龄
	//再返回一个新的对象2
	//p1.PersonAddAge(p2).PersonAddAge(p2).PersonAddAge(p2);然后这句代码再让对象2的年龄加上p2的年龄再返回一个新的对象3
	//于是就导致最终结果不管叠加多少都不变
	//所以，在返回*this的时候，一定要将返回值设置为  类名&
	cout << "p1的年龄为： " << p1.Getage() << endl;

	return 0;
}