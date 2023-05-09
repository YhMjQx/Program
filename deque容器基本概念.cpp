#include<iostream>
#include<deque>
using namespace std;

//deque���� - ˫�����飬���Զ���ͷ���в����ɾ������
//deque��vector������
//vector����ͷ���Ĳ���ɾ��Ч�ʵͣ�������Խ��Ч��Խ��
//deque��Զ��ԣ���ͷ���Ĳ����ɾ���ٶȱ�vector��
//vector����Ԫ��ʱ���ٶȱ�deque�죬��������ڲ�ʵ���й�

//deque�ڲ�����ԭ��
//deque�ڲ���һ���п�����ά��ÿ�λ������е����ݣ��������д����ʵ����
//�п���ά������ÿ�λ������ĵ�ַ��ʹ��dequeʹ����һƬ�����Ŀռ�
//deque�ĵ�����Ҳ֧���������

void PrintDeque(deque<int>& d){
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it){
		//const_iterator - ��Ϊ�˷�ֹ��it��ָ������ݽ��иı�
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	deque<int>d1;
	for (int i = 0; i < 10; ++i){
		d1.push_back(i);
	}
	PrintDeque(d1);

	deque<int>d2(d1.begin(), d1.end());
	PrintDeque(d2);

	deque<int>d3(10, 39);
	PrintDeque(d3);

	deque<int>d4(d3);//��������
	PrintDeque(d4);

}

int main(){
	test1();
	return 0;
}