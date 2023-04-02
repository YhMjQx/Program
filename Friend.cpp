//友元是一种允许 非类成员函数 访问 类的非公有成员 的一种机制
//可以把一个函数指定为类的友元 - 友元函数。也可以把整个类指定为另一个类的友元 - 友元类。
//
//1.友元函数在类的作用域外定义，但他需要在类体中进行说明
//2.为了与该类的成员函数加以区别，定义的方式是再累中用关键字friend说明该函数
//格式如下：friend 类型 友元函数名(参数表)
//友元的作用在于提高程序的运行效率
#include<iostream>
#include<math.h>
using namespace std;
class Point{
public:
	Point(int x, int y) :x_(x), y_(y){}		//构造函数

	friend double Distence(const Point& p1, const Point& p2);		//友元函数，不是类的成员函数
private:
	int x_;
	int y_;
};

//在类的作用域外定义
double Distence(const Point& p1, const Point& p2){
	double dx = p1.x_ - p2.x_;
	double dy = p1.y_ - p2.y_;
	//我们会发现，在这个友元函数体内可以直接对类的私有成员直接访问

	return sqrt(dx * dx + dy * dy);
}
int main(){
	Point p1(3, 4);
	Point p2(6, 8);
	cout<<Distence(p1, p2)<<endl;
	return 0;
}