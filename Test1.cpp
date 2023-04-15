#include<iostream>
using namespace std;
//改文件中的所有地址均为暂时性的，每执行一次稳健，分配的地址都不一样，在该文件表示出来只是为了更好的演示内存模块

class BB{
public:

	int bb_;

};

class B1 :virtual public BB{
public:

	int b1_;

};

class B2 :virtual public BB{
public:

	int b2_;

};

class DD :public B1, public B2{
public:

	int dd_;

};
int main(){

	cout << sizeof(BB) << endl;
	cout << sizeof(B1) << endl; 
	cout << sizeof(B2) << endl;
	cout << sizeof(DD) << endl;
	
	B1 b1;
	long** p;
	cout << &b1 << endl;	//004FFBAC
	cout << &b1.b1_ << endl;//004FFBB0
	cout << &b1.bb_ << endl;//004FFBB4

	p = (long**)&b1;
	cout << p[0][0] << endl;// - 0
	cout << p[0][1] << endl;// - 8
	//第一个空间为空格是虚基类表指针（vbptr）,指向虚基类表（virtual base table）
	//此时本类地址就是虚基类表指针地址就是本类地址
	//___________
//p-> |  p[0]   |           vbptr   ____________ vbtl 
	//|		    |//004FFBAC - &B1 ->| p[0][0]  | - 本类地址与虚基类表指针地址的差 - 此时就是0（此时没有虚函数）
	//-----------                   ------------   
	//|         |                   |  p[0][1] | - 虚基类地址与虚基类表指针地址的差 - 此时为8
	//|    b1_  |//004FFBB0         ------------
	//-----------
	//|         |
	//|   bb_   |//004FFBB4 - 虚基类部分
	//-----------
	//以上是BB对象的内存模型


	DD dd;
	cout << &dd << endl;//00BBFD04
	cout << &dd.dd_ << endl;//00BBFD14
	cout << &dd.b1_ << endl;//00BBFD08
	cout << &dd.b2_ << endl;//00BBFD10
	cout << &dd.bb_ << endl;//00BBFD18

	p = reinterpret_cast<long**>(&dd);
	cout << p[0][0] << endl;
	cout << p[0][1] << endl;
	cout << p[2][0] << endl;
	cout << p[2][1] << endl;
//	
//	_________		___________  ______      <-   00BBFD04-&dd
//	|0 p[0][0]|	<-	|vbptr p[0]|	   |
//	----------		-----------   b1   |     <-   00BBFD08-&dd.b1_ 
//	|___20____|		|dd.b1_ p[1]|      |
//					-----------  ------ 								   
//	__________	<-	|vbptr p[2] |      |							
//	|0 p[2][1]|		-----------	  b2   | 								
//	-----------		|dd.b2_ p[3]|	   |      <-  00BBFD10-&dd.b2_								
//	|__12_____|		-----------  ------								
//					|dd.dd_ p[4]|			  <-  00BBFD14-&dd.dd_ 
//					-----------  ------										
//					|dd.bb_ p[5]|   BB  |	  <-  00BBFD18-&dd.bb_ = pp											
//					-----------  ------							

	//虚基类是通过虚基类表指针来找到的，通过虚基类表指针的偏移位置找到的

	//上面我们是用对象来直接访问的，那先面我们就来看看用指针访问的情况
	BB* pp;
	pp = &dd;
	pp->bb_;
	//这时候就涉及到间接访问了，通过调试发现，pp指针指向的内容和&dd指针指向的内容是不一样的
	//例如：pp 0x00b3f814 {bb_ = -858993460 }	
	//	 &dd 0x00b3f800 {dd_ = -858993460 }	
	//编译时刻已经固定了内存模型，所以通过指针来访问成员，是间接访问的，运行时会对改地址进行调整
	//此过程需要运行时的支持，需要通过虚基类表指针 找到 虚基类地址与虚基类表指针的地址的差，也就是虚基类表的第二项
	//实际上的pp指向的是BB这块空间


	return 0;
}