#include<iostream>
using namespace std;

//点类
class Point{
public:
	//设置点的坐标
	Point(int x, int y) :m_X(x), m_Y(y){

	}
	//获取点的横坐标
	int GetX(){
		return m_X;
	}
	//获取点的纵坐标
	int GetY(){
		return m_Y;
	}
private:
	int m_X;
	int m_Y;

};


//圆类
class Circle{
public:
	//设置圆的半径和圆心
	Circle(int r, Point& p) :m_R(r), m_Center(p){

	}

	//获取圆的半径
	int GetR(){
		return m_R;
	}

	//获取圆心
	Point GetCenter(){
		return m_Center;
	}
private:
	int m_R;
	Point m_Center;
};

//用全局函数来判断点和圆的位置关系
void WherePointCircle(Circle& c,Point& p){
	//计算点与圆心之间的距离的平方
	int ret = ((c.GetCenter().GetX() - p.GetX()) *(c.GetCenter().GetX() - p.GetX())) +
		((c.GetCenter().GetY() - p.GetY())*(c.GetCenter().GetY() - p.GetY()));
	//计算半径的平方
	int R = c.GetR()*c.GetR();
	if (ret == R){
		cout << "点在圆上" << endl;
	}
	else if (ret < R){
		cout << "点在圆内" << endl;
	}
	else{
		cout << "点在圆外" << endl;
	}
}
int main(){
	//创建圆
	//给一个圆心
	Point center(10, 0);
	//给出圆的半径
	Circle c(10,center);

	//创造一个点
	Point p(10,10);

	//判断关系
	WherePointCircle(c, p);
	return 0;
}