#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

//merge(iterator beg1, iterator end1, iterator bed2, iterator end2, iterator dest);
//����Ԫ�غϲ������洢����һ��������
//ע�⣺�������������������
//beg1 - ����1��ʼ������
//end1 - ����1����������
//beg2 - ����2��ʼ������
//end2 - ����2����������
//dest - Ŀ���������ʼ������

void MyPrint(int val){
	cout << val << " ";
}

void test1(){

	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
		v2.push_back(i);
	}

	vector<int>vTarge;
	//��ס��һ��Ҫ��vTarge�����µĿռ�
	vTarge.resize(v1.size() + v2.size());

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarge.begin());
	for_each(vTarge.begin(), vTarge.end(),MyPrint);
	cout << endl;
	//�����ɵ�vTarge����һ����������


}

int main(){
	test1();

	return 0;
}