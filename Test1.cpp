#include<iostream>
#include<string>
using namespace std;

class Manager1;
class Manager2;
class Employee{
public:
	Employee(){

	}
	Employee(const string& name, const int age, const int deptno) : name_(name), age_(age), deptno_(deptno)
	{

	}

	operator Manager1();//其实原本将函数的实现应该放在这里，但是由于Manager1的实现在前面并没有实现
						//所以我暂时就放在,类外面进行实现了
private:
	string name_;
	int age_;
	int deptno_;//部门号
};

class Manager1 : public Employee{
public:
	Manager1(){

	}

	Manager1(const string& name, const int age, const int deptno, int level)
		:Employee(name, age, deptno), level_(level){

	}

	//Manager1(const Employee& other) : Employee(other), level_(0){
	//	//这个函数是用来让基类转化为派生类的，转换构造函数是不是一般就放在那个目的类型中，换个想法，将一个整数初始化给一个类，是不是就将转换构造函数放在这个类里面的
	//}
private:
	int level_;
};


Employee::operator Manager1(){
	return Manager1(name_, age_, deptno_, -1);
}


class Manager2: private Employee{
public:
	Manager2(){

	}
	Manager2(const string& name, const int age, const int deptno, int level)
		:Employee(name, age, deptno), level_(level){

	}

	//Manager2(const Employee& other) : Employee(other), level_(0){
	//	//这个函数是用来让基类转化为派生类的，转换构造函数是不是一般就放在那个目的类型中，换个想法，将一个整数初始化给一个类，是不是就将转换构造函数放在这个类里面的
	//}
private:
	int level_;
};
int main(){
	
	Employee e1("hujiaxin",20,39);
	Manager1 m1("yangmingqiang", 20, 39, 39);
	Manager2 m2("huyang", 0, 0, 999);
	//m2 = e1; - 将基类转换为派生类，需要用到派生类的转换构造函数
	//m1 = e1;
	
	Employee* pe;
	Manager1* pm1;
	Manager2* pm2;

	pe = &e1;
	pm1 = &m1;
	pm2 = &m2;
		//以上基类指针指向基类对象，派生类指针指向派生类对象，都是对的，那么基类指针可不可以指向派生类对象呢


			//public继承情况下：
	pe = &m1;//编译通过说明，基类指针可以指向派生类对象 或者说 派生类指针可以转化为基类指针 - 将派生类对象看成基类对象
	////pm = &e1; - error,，派生类指针不能指向基类对象 或者说 基类指针不能转化为派生类指针 - 不能将基类对象看做派生类对象
	e1 = m1;//可以将派生类对象赋给基类对象，将派生类对象特有成员删除（对象切割 - object slicing），然后将派生类对象完完全全的赋给基类对象


			//private 或者 protected 继承情况下
	////pe = pm2; - error ,派生类指针不可以自动转化为基类指针，这种情况下我们需要用到强制类型转化方法
	////pe = static_cast<Employee*>(pm2);	//但是，这里并不能用static_cast<Employee*>(pm2) - 不允许对不可访问的基类进行转换
	pe = reinterpret_cast<Employee*>(pm2);//或者pe = (Employee*)pm2;
	////e1 = m1; - error,在该种继承情况下不能将派生类对象转化为基类对象，也没有任何办法可以做到



	//基类指针转换为派生类指针是不受private和protceted的限制的
	pm1 = static_cast<Manager1*>(pe);  // 基类指针可以转换为派生类指针，但是不安全，因为一般情况下派生类指针具有一些特有的成员
				//将基类指针转换为派生类指针之后，基类指针是可以访问派生类的特有成员的，但是事实上基类并没有该成员，所以就会出问题
	//基类对象是不能强制类型转换成派生类对象


	return 0;

}