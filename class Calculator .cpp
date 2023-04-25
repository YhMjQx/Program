#include<iostream>
#include<string>
using namespace std;

//分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类


//普通写法
class calculator{
public:
	int GetResult(string oper)
	{
		if (oper == "+"){
			return m_Num1 + m_Num2;
		}
		else if (oper == "-"){
			return m_Num1 - m_Num2;
		}
		else if (oper == "*"){
			return m_Num1 * m_Num2;
		}
		//如果想要扩展新的功能，需要来修改源码
		//在真实的开发中，提倡 开闭原则，对扩展进行开发，对修改进行关闭
	}


	int m_Num1;
	int m_Num2;
};

void test1(){
	calculator c;
	c.m_Num1 = 39;
	c.m_Num2 = 39;

	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.GetResult("+") << endl;

	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.GetResult("-") << endl;

	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.GetResult("*") << endl;

}


//多态写法

//利用多态实现计算器
//计算机抽象类
//多态的优点：
//1.代码组织结构清晰
//2.可读性强
//3.利于前期和后期的扩展和维护
class Abstractcalculator{
public:

	virtual int Getresult(){
		return 0;
	}

	int m_Num1;
	int m_Num2;
};

//加法计算器类
class Addclaculator :public Abstractcalculator{
public:
	int Getresult(){
		return m_Num1 + m_Num2;
	}
};

//减法计算器类
class Subclaculator :public Abstractcalculator{
public:
	int Getresult(){
		return m_Num1 - m_Num2;
	}
};

//乘法计算器类
class Mulclaculator :public Abstractcalculator{
public:
	int Getresult(){
		return m_Num1 * m_Num2;
	}
};


void test2(){
	Abstractcalculator* abc = new Addclaculator;
	abc->m_Num1 = 39;
	abc->m_Num2 = 39;

	//加法
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->Getresult() << endl;
	delete abc;

	//减法
	abc = new Subclaculator;
	abc->m_Num1 = 39;
	abc->m_Num2 = 39;
	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->Getresult() << endl;
	delete abc;

	//乘法
	abc = new Mulclaculator;
	abc->m_Num1 = 39;
	abc->m_Num2 = 39;
	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->Getresult() << endl;
	delete abc;

}

int main(){
	//test1();
	test2();
	return 0;
}