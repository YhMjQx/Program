//ջ���Ǹߵ�ַ����ջ����������
#include<iostream>
#include<stack>
using namespace std;

void test1(){
	//ջ - �����Ƚ����
	stack<int>s;

	//��ջ
	s.push(10);
	s.push(20);
	s.push(39);
	s.push(39);
	s.push(10);

	cout << "ջ��Ԫ�ظ����� " << s.size() << endl;

	while(!s.empty()){
		//���ջ���ǿգ��Ͳ鿴ջ�������ݣ���ִ�г�ջ
		cout << "ջ������Ϊ�� " << s.top() << endl;
		//��ջ
		s.pop();
		//�鿴ջ��Ԫ�ظ���
		cout << "ջ��Ԫ�ظ����� " << s.size() << endl;
		cout << "------------------------" << endl;
	}



}

int main(){
	test1();

	return 0;
}
