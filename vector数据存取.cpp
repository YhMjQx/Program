#include<iostream>
#include<vector>
using namespace std; 

//at.(int idx);//��������idx��ָ������
//operator[];//��������idx��ָ��λ��
//front();//���������е�һ�����ݵ�Ԫ��
//back();//�������������һ��Ԫ��

void test1(){
	vector<int>v1;
	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
	}

	//����forѭ���ķ�ʽ����������
	//����[]�����������Ա
	for (int i = 0; i < v1.size(); ++i){
		cout << v1[i] << " ";
	}
	cout << endl;
	//����at�����������Ա
	for (int i = 0; i < v1.size(); ++i){
		cout << v1.at(i) << " ";
	}
	cout << endl;

	//���������һ��Ԫ��
	cout << v1.front() << endl;
	//�����������һ��Ԫ��
	cout << v1.back() << endl;

}

int main(){
	test1();
	return 0;
}