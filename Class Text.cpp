#include "Class Text.h"


//Text::Text()
//{
//}
//
//
//Text::~Text()
//{
//}
//不带参数的构造函数称为默认构造函数
//注释掉这段代码，看程序是否会自动生成一个构造函数
Text::Text(){
	num_ = 0;
	cout << "Initializing Default" << endl;
}
void Text::Display(){
	cout << "num_=" << num_ << endl;
}
Text::Text(int num){
	num_ = num;
	cout << "Initializing " << num_ << endl;
}
Text::~Text(){
	cout << "Destroy " << num_ << endl;
}