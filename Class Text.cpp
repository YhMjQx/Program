#include "Class Text.h"


//Text::Text()
//{
//}
//
//
//Text::~Text()
//{
//}
//���������Ĺ��캯����ΪĬ�Ϲ��캯��
//ע�͵���δ��룬�������Ƿ���Զ�����һ�����캯��
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