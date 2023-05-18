#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//set_intersection(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);//��������������
//�󽻼��ĵ���������������������������
//Ŀ���������ٿռ��ʱ����Ҫ������ȷ�����ҳ���С��һ��
//set_intersection���صĵ������ǽ��������һ��Ԫ�ص�λ�ã�����Ŀ�������Ľ���λ��

//set_union(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);//��������������
//�󲢼��ĵ���������������������������
//Ŀ���������ٿռ��ʱ����Ҫ��������������С֮��
//set_union���صĵ������ǲ��������һ��Ԫ�ص�λ�ã�����Ŀ�������Ľ���λ��

//set_difference(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest);//�����������
//���ĵ���������������������������
//Ŀ���������ٿռ��ʱ����Ҫ�������������нϴ��һ���ռ�
//set_difference���صĵ������ǲ�����һ��Ԫ�ص�λ�ã�����Ŀ�������Ľ���λ��


void Print(int val){
	cout << val << " ";
}

void test1(){
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
	}

	for (int i = 5; i < 15; ++i){
		v2.push_back(i);
	}

	vector<int>vTarget;
	vTarget.resize(min(v1.size(), v2.size()));

	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	//for_each(vTarget.begin(), vTarget.end(), Print);

	for_each(vTarget.begin(), itEnd, Print);
	cout << endl;

}

void test2(){
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, Print);
	cout << endl;
}

void test3(){
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>vTarget;
	vTarget.resize(max(v1.size(), v2.size()));

	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	cout << "v1��v2�ĲΪ��" << endl;
	for_each(vTarget.begin(), itEnd, Print);
	cout << endl;

	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	cout << "v2��v1�ĲΪ��" << endl;
	for_each(vTarget.begin(), itEnd, Print);
	cout << endl;

}

int main(){
	//test1();
	//test2();
	test3();
	return 0;
}