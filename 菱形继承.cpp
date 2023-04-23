#include<iostream>
using namespace std;

//动物类
class Animal{
public:
	int m_Age;

};
//利用虚继承，解决菱形继承的问题 - 关键字 - virtual
//在继承之前加上关键字virtual
//那么，Animal这个最大的基类就叫做 虚基类
//利用了虚继承之后，在这里羊类和驼类继承下去的东西
//在羊驼类当中其实是两个虚基类指针（vbptr）,虚基类指针是指向虚基类表（vbtable）的，
//虚基类表当中记载了 虚基类指针和虚基类指针到真实目的数据的地址偏移量，而且这个真实目的数据在最小的子类当中有且仅存在一份
//然后调用的时候就会通过这个虚基类指针，以及偏移量来找到我们所要的数据

//羊类
class Sheep:virtual public Animal{

};

//驼类
class Tuo :virtual  public Animal{

};

//羊驼类
class SheepTuo :public Sheep, public Tuo{

};

void test1(){
	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	cout << "st.Sheep::m_A = " << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_A = " << st.Tuo::m_Age << endl;
	//用了虚继承之后，st.Sheep::m_Age和st.Tuo::m_Age实际上是一个m_Age，第一次对m_Age赋值为18，第二次赋值为28
	cout << "st.m_Age = " << st.m_Age << endl;
	//当出现菱形继承的时候，有两个父类拥有相同的数据时，需要加以作用域区分

	//但是，这份数据在最后的类对象中，只需要有一份数据即可，菱形继承导致数据存在两份，资源浪费

}

int main(){
	test1();
	return 0;
}