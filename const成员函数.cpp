//const成员函数不会修改对象的状态
//const成员函数只能访问数据成员的值，而不能修改它
//如果把一个对象指定为const，就是告诉编译器不要修改它
//const对象的定义：const 类名 对象名(参数表)
//const对象不能调用非const成员函数

//用mutable(易变的，可变的)修饰的数据成员即使在const对象或在const成员函数中都可以修改

//const 定义常量必须初始化，定义对象也必须初始化
//const引用能够引用至const常量，而普通的引用就不能
//在类中，如果有const成员，const成员的初始化必须只能在构造函数初始化列表中进行
//const成员函数，该函数不能修改对象状态，只能访问数据成员，但不能修改

#include<iostream>
using namespace std;
class Test{
public:
	Test(int x) :x_(x), OutputTimes_(0){

	}

	//非const成员函数存在对对象修改的风险
	int GetX(){
		cout << "Test..." << x_ << endl;
		return x_;//这里的x_可以发生改变
	}

	//const成员函数
	int GetX() const{
		cout << "const Test..." << x_ << endl;
		return x_;//这里的x_不能发生改变
		
	}
	void Output(){
		cout << "x_= " << x_ << endl;
		OutputTimes_++;
	}
	int GetOutputTimes(){
		return OutputTimes_;
	}
private:
	int x_;
	mutable int OutputTimes_;
};
int main(){
	Test t1(39);//调用GetX
	const Test t2(10);//调用const GetX

	cout << t1.GetX() << endl;//调用GetX
	cout<<t2.GetX()<<endl;//调用const GetX

	t1.Output();
	t1.Output();
	cout << t1.GetOutputTimes() << endl;
	return 0;
}