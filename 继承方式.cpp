#include<iostream>
using namespace std;

class Base{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};


class Son1 :public Base{
	void func(){
		m_A = 10;//父类中公共权限成员到子类中依然是公共权限
		m_B = 10;//父类中保护权限成员到子类中仍是保护权限
		//m_C = 10;//父类中的私有权限成员，子类访问不到
	}
};

void test1(){
	Son1 s1;
	s1.m_A = 10;
	//s1.m_B = 10;到Son1中，m_B是保护权限，Son1类外访问不到
}

class Son2 :protected Base{
public:
	void func(){
		m_A = 100;//父类中公共成员到子类中编程保护权限
		m_B = 100;//父类中保护权限到子类中还是保护权限
		//m_C = 100;//父类中的私有权限 子类访问不到
	}

};

void test2(){
	Son2 s2;
	//s2.m_A = 1000;//在Son2中m_A是保护权限，类外访问不到
	//s2.m_B = 1000;//在Son2中m_B是保护权限，类外访问不到
}

class Son3 :private Base{
public:
	void func(){
		m_A = 100;//父类中公有成员到子类中变为私有成员
		m_B = 100;//父类中保护成员到子类中变为私有成员
		//m_C = 100; - 父类中的私有成员 子类访问不到
	}


};

void test3(){
	Son3 s3;
	//s3.m_A = 1000;//m_A到子类中变成了私有的成员，类外访问不到
	//s3.m_B = 1000;//m_B到子类中变成了私有的成员，类外访问不到
	//s3.m_C = 1000;//m_C到子类中变成了私有的成员，类外访问不到
}

class GrandSon3:public Son3{
public:
	void func(){
		//m_A = 1000;
		//m_B = 1000;
		//由此也可知,zai Son3类中这两个成员都是私有的
	}
};

int main(){

	return 0;
}