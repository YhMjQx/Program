#include<iostream>
using namespace std;

class Person{
public:
	void ShowclassName(){
		cout << "this is Person class" << endl;
	}


	void ShowPersonAge(){
		//事实上应该是有一个this指针来指向m_Age的但现在，我们传了一个NULL指针，相当于这里的this是空的，那么肯定会报错
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