#include "Text.h"
////��ôAdd�ͱ�����Ϊ������Ա��������Ȼ��ֻ�Ƕ����һ�ַ���
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
	this->x_ = x;//�������������thisָ��
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
//void Text::Init(int x , int y, int z){//ȱʡ�������������ʱ���ֵ��ʵ�ֵ�ʱ����Ҫ��ֵ
//	//��Ա�������������ʱ��Ҫע��������ĺ�������������
//	x_ = x;
//	y_ = y;
//	z_ = z;
//}