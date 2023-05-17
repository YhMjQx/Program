#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<ctime>
using namespace std;

//sort											//��������Ԫ�ؽ�������
//random_shuffle(iterator beg,iterator end);	//ϴ�ƣ�ָ����Χ�ڵ�Ԫ�������������
//merge											//����Ԫ�غϲ������洢����һ��������
//reverse										//��תָ����Χ�ڵ�Ԫ��

void MyPrint(int val){
	cout << val << " ";
}

void test1(){
	//sort�Ļ����÷����Ƕ�֪����
	//������ʹ��һ��һ���������֪ʶ��
	vector<int>v;
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}
	//����sort��Ĭ�ϵ��������򣬶�����v���Ѿ��������ˣ����������ڲ���ʹ������
	//��ϣ���ڲ��Լ�ʵ��ν�ʺͺ���������£�ʵ��sort�Ľ���
	//greater - ��ͷ�ļ��а�����һ��ģ�壬��ʵ���൱������д�Ľ���ν��
	sort(v.begin(), v.end(), greater<int>());

	//for (vector<int>::iterator it = v.begin(); it != v.end(); ++it){
	//	cout << *it << " ";
	//}
	//cout << endl;
	//�Ժ�����������������forѭ�������
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

void test2(){
	//�����ṩһ����������ӣ��Է�ֹÿ�δ���˳��Ľ������һ����
	srand((unsigned int)time(NULL));
	
	vector<int>v;
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

int main(){
	//test1();
	test2();
	return 0;
}