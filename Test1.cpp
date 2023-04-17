#include<iostream>
#include<vector>
using namespace std;

//有了一个或一个以上的纯虚函数，该类就被称为抽象类
class Shape{
public:
	virtual void Draw() = 0;
	//多台基类的析构函数就要定义为虚析构函数
	//当多态基类的析构函数不定义为虚析构函数时，派生类的析构函数都不是虚的
	//虚析构函数的特点是：当我们在父类当中，通过virtual修饰析构函数之后
	//我们通过父类的指针再去指向子类的对象，然后通过delete接父类指针就可以释放掉子类的对象。
	virtual ~Shape(){
		cout << "~Shape..." << endl;
	}
};

class Circle :public Shape{
public:
	//如果一个派生类也不实现纯虚函数，那么这个派生类也变成了抽象类，则，纯虚函数的实现就要交给派生类的派生类了
	void Draw(){
		cout << "Circle::Draw()..." << endl;
	}
	~Circle(){
		cout << "~Circle..." << endl;
	}
};

class Square :public Shape{
public:
	void Draw(){
		cout << "Square::Draw()..." << endl;
	}
	~Square(){
		cout << "~Square..." << endl;
	}
};

class Rectangle:public Shape{
public:
	void Draw(){
		cout << "Rectangle::Draw()..." << endl;
	}
	~Rectangle(){
		cout << "~Rectangle..." << endl;
	}
};

void DrawAllShape(const vector<Shape*>& v){
	vector<Shape*>::const_iterator it;
	for (it = v.begin(); it != v.end(); ++it){
		//将基类和派生类当成一致的观点来看待)(*it) = Shape*
		//如果积累没有将该函数定义为纯虚函数，那么这里就会调用两次无意义的基类Draw
		//但如果定义的是纯虚函数，那么这里就是基类指针指向派生类的虚函数调用
		(*it)->Draw();
	}
}

void DeleteAllShape(const vector<Shape*>& v){
	vector<Shape*>::const_iterator it;
	for (it = v.begin(); it != v.end(); ++it){
		delete(*it);
		//*it就相当于Shape*,他实际指向的是一个派生类对象，通过的抽象类的虚析构函数，我们可以做到
		//先调用派生类的析构函数，然后再调用抽象类的析构函数，这样就不会有内存泄露的风险
	}
}

//实现一个简单的工厂模式
class ShapeFactory{
public:
	static Shape* CreateShape(const string& name){
		Shape* ps;
		if (name == "Circle"){
			ps = new Circle;
		}
		else if (name == "Square"){
			ps = new Square;
		}
		else if (name == "Rectangle"){
			ps = new Rectangle;
		}
		return ps;
	}
};
int main(){

	vector<Shape*> v;
	Shape* ps;
	//ps = new Circle;
	//v.push_back(ps);
	//ps = new Square;
	//v.push_back(ps);

	Shape* ps;
	ps = ShapeFactory::CreateShape("Circle");
	v.push_back(ps);
	ps = ShapeFactory::CreateShape("Square");
	v.push_back(ps);
	ps = ShapeFactory::CreateShape("Rectangle");
	v.push_back(ps);

	DrawAllShape(v);
	DeleteAllShape(v);
	return 0;
}