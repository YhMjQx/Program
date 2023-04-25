#include<iostream>
#include<string>
using namespace std;

//�ֱ�������ͨд���Ͷ�̬���������ʵ��������������������ļ�������


//��ͨд��
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
		//�����Ҫ��չ�µĹ��ܣ���Ҫ���޸�Դ��
		//����ʵ�Ŀ����У��ᳫ ����ԭ�򣬶���չ���п��������޸Ľ��йر�
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


//��̬д��

//���ö�̬ʵ�ּ�����
//�����������
//��̬���ŵ㣺
//1.������֯�ṹ����
//2.�ɶ���ǿ
//3.����ǰ�ںͺ��ڵ���չ��ά��
class Abstractcalculator{
public:

	virtual int Getresult(){
		return 0;
	}

	int m_Num1;
	int m_Num2;
};

//�ӷ���������
class Addclaculator :public Abstractcalculator{
public:
	int Getresult(){
		return m_Num1 + m_Num2;
	}
};

//������������
class Subclaculator :public Abstractcalculator{
public:
	int Getresult(){
		return m_Num1 - m_Num2;
	}
};

//�˷���������
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

	//�ӷ�
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->Getresult() << endl;
	delete abc;

	//����
	abc = new Subclaculator;
	abc->m_Num1 = 39;
	abc->m_Num2 = 39;
	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->Getresult() << endl;
	delete abc;

	//�˷�
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