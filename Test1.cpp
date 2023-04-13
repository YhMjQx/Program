#include<iostream>
#include<string>
using namespace std;

class Manager1;
class Manager2;
class Employee{
public:
	Employee(){

	}
	Employee(const string& name, const int age, const int deptno) : name_(name), age_(age), deptno_(deptno)
	{

	}

	operator Manager1();//��ʵԭ����������ʵ��Ӧ�÷��������������Manager1��ʵ����ǰ�沢û��ʵ��
						//��������ʱ�ͷ���,���������ʵ����
private:
	string name_;
	int age_;
	int deptno_;//���ź�
};

class Manager1 : public Employee{
public:
	Manager1(){

	}

	Manager1(const string& name, const int age, const int deptno, int level)
		:Employee(name, age, deptno), level_(level){

	}

	//Manager1(const Employee& other) : Employee(other), level_(0){
	//	//��������������û���ת��Ϊ������ģ�ת�����캯���ǲ���һ��ͷ����Ǹ�Ŀ�������У������뷨����һ��������ʼ����һ���࣬�ǲ��Ǿͽ�ת�����캯����������������
	//}
private:
	int level_;
};


Employee::operator Manager1(){
	return Manager1(name_, age_, deptno_, -1);
}


class Manager2: private Employee{
public:
	Manager2(){

	}
	Manager2(const string& name, const int age, const int deptno, int level)
		:Employee(name, age, deptno), level_(level){

	}

	//Manager2(const Employee& other) : Employee(other), level_(0){
	//	//��������������û���ת��Ϊ������ģ�ת�����캯���ǲ���һ��ͷ����Ǹ�Ŀ�������У������뷨����һ��������ʼ����һ���࣬�ǲ��Ǿͽ�ת�����캯����������������
	//}
private:
	int level_;
};
int main(){
	
	Employee e1("hujiaxin",20,39);
	Manager1 m1("yangmingqiang", 20, 39, 39);
	Manager2 m2("huyang", 0, 0, 999);
	//m2 = e1; - ������ת��Ϊ�����࣬��Ҫ�õ��������ת�����캯��
	//m1 = e1;
	
	Employee* pe;
	Manager1* pm1;
	Manager2* pm2;

	pe = &e1;
	pm1 = &m1;
	pm2 = &m2;
		//���ϻ���ָ��ָ��������������ָ��ָ����������󣬶��ǶԵģ���ô����ָ��ɲ�����ָ�������������


			//public�̳�����£�
	pe = &m1;//����ͨ��˵��������ָ�����ָ����������� ����˵ ������ָ�����ת��Ϊ����ָ�� - ����������󿴳ɻ������
	////pm = &e1; - error,��������ָ�벻��ָ�������� ����˵ ����ָ�벻��ת��Ϊ������ָ�� - ���ܽ�������������������
	e1 = m1;//���Խ���������󸳸�������󣬽�������������г�Աɾ���������и� - object slicing����Ȼ���������������ȫȫ�ĸ����������


			//private ���� protected �̳������
	////pe = pm2; - error ,������ָ�벻�����Զ�ת��Ϊ����ָ�룬���������������Ҫ�õ�ǿ������ת������
	////pe = static_cast<Employee*>(pm2);	//���ǣ����ﲢ������static_cast<Employee*>(pm2) - ������Բ��ɷ��ʵĻ������ת��
	pe = reinterpret_cast<Employee*>(pm2);//����pe = (Employee*)pm2;
	////e1 = m1; - error,�ڸ��ּ̳�����²��ܽ����������ת��Ϊ�������Ҳû���κΰ취��������



	//����ָ��ת��Ϊ������ָ���ǲ���private��protceted�����Ƶ�
	pm1 = static_cast<Manager1*>(pe);  // ����ָ�����ת��Ϊ������ָ�룬���ǲ���ȫ����Ϊһ�������������ָ�����һЩ���еĳ�Ա
				//������ָ��ת��Ϊ������ָ��֮�󣬻���ָ���ǿ��Է�������������г�Ա�ģ�������ʵ�ϻ��ಢû�иó�Ա�����Ծͻ������
	//��������ǲ���ǿ������ת�������������


	return 0;

}