#include<iostream>
#include<deque>
using namespace std;

//deque û��������ֻ��Ԫ�ظ���

//deque.empty();//�ж������Ƿ�Ϊ��
//deque.size();//����������Ԫ�ظ���
//deque.resize(num);//����ָ�������ĳ���Ϊnum�������ԭ���ĳ�������Ĭ��ֵ�������λ��
//					//�����Ա��ȶ̣��򳬳������ݱ�ɾ��
//deqeu.resize(num, elem);//����ָ�������ĳ��ȣ���������䳤������elem����µ�λ��
//						//�����������̣��򳬳���Ԫ�ر�ɾ��

void Printdeque(deque<int>& d){
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	deque<int>d1;
	for (int i = 0; i < 10; ++i){
		d1.push_back(i);
	}
	Printdeque(d1);

	if (d1.empty()){
		cout << "d1Ϊ�գ�" << endl;
	}
	else{
		cout << "d1��Ϊ�գ�" << endl;
	}

	d1.resize(5);
	Printdeque(d1);

	d1.resize(15, 39);
	Printdeque(d1);

}

int main(){
	test1();

	return 0;
}