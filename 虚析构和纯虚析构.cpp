#include<iostream>
#include<string>
using namespace std;

//��̬ʹ��ʱ��������൱���漰�����ڶ����Ͽ��ٿռ���������ô����ָ�����ͷ�ʱ���޷��������������������
//Ҳ����˵����������£������ͷŸ���ָ���޷������Զ������ٵ��ڴ���ȫ�ͷţ����ܻ�����ڴ�й©
//��������������������������Ϊ���������ߴ�������

////�������ʹ��������Ĺ��ԣ�
//1.���Խ������ָ���ͷ�������������
//2.�������ʹ�����������Ҫ�Ժ�������ʵ�֣���������������ʵ�֣���������ͨ�Ĵ��麯���ǲ���Ҫ�Ժ�������ʵ�ֵ�

//�������ʹ�������������
//����Ǵ����������������ڳ����࣬�޷�ʵ��������

class Animal{
public:
	Animal(){
		cout << "Animal �Ĺ��캯������" << endl;
	}

	//�������������Խ������ָ���ͷ��������ʱ���ͷŲ��ɾ�������
	//virtual ~Animal(){
	//	cout << "Animal ����������������" << endl;
	//}

	//���ô�������Ҳ���Խ���������
	virtual ~Animal() = 0;

	virtual void speak() = 0;
};

Animal::~Animal(){
	cout << "Animal �Ĵ���������������" << endl;
}

class Cat :public Animal{
public:
	Cat(string name) :m_Name(new string(name)){
		//������Ҫ��Cat���ڽ����ٵ�name�ͷŸɾ�
		cout << "Cat ���캯������" << endl;
	}

	~Cat(){
		if (m_Name != NULL){
			cout << "Cat ��������������" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}

	void speak(){
		cout << *m_Name << "è��˵��" << endl;
	}

	string* m_Name;
};

void test1(){
	Animal* animal = new Cat("hjx");
	animal->speak();
	//����ָ��������ʱ��������������������������ˣ�����������ڶ������ٿռ������ʱ����������Ϳ��ܻᵼ���ڴ�й©
	delete animal;
	animal = NULL;
}

int main(){
	test1();
	return 0;
}