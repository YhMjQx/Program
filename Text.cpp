#include "Text.h"
////那么Add就被定义为内联成员函数，当然这只是定义的一种方法
//inline int Text::Add(int a, int b){
//	return a + b;
//}
void 
void Text::Init(){
	x_ = 0;
	y_ = 0;
	z_ = 0;
}
void Text::Init(int x){
	this->x_ = x;//这个就是隐含的this指针
	y_ = 0;
	z_ = 0;
}
void Text::Init(int x, int y){
	x_ = x;
	y_ = y;
	z_ = 0;
}
void Text::Init(int x, int y, int z){
	x_ = x;
	y_ = y;
	z_ = z;
}
void Text::Display(){
	cout << "x_=" << x_ << " y_=" << y_ << " z_=" << z_ << endl;
}
//void Text::Init(int x , int y, int z){//缺省参数函数定义的时候给值，实现的时候不需要给值
//	//成员内联函数定义的时候要注意和其他的函数产生二义性
//	x_ = x;
//	y_ = y;
//	z_ = z;
//}