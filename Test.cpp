#include<iostream>
using namespace std;

class Person{
public:
	void ShowclassName(){
		cout << "this is Person class" << endl;
	}


	void ShowPersonAge(){
		//��ʵ��Ӧ������һ��thisָ����ָ��m_Age�ĵ����ڣ����Ǵ���һ��NULLָ�룬�൱�������this�ǿյģ���ô�϶��ᱨ��
		if (this == NULL){
			return ;
		}
		cout << "age= " << this->m_Age << endl;
	}


private:
	int m_Age;

};

int main(){
	Person* p = NULL;
	p->ShowclassName();
	p->ShowPersonAge();
	return 0;
}