#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
//#include<functional>
//���������㷨����С���㷨��ʹ��ʱ����ͷ�ļ�Ϊ#include<numeric>
using namespace std;

//accmulate(iterator beg, iterator end, value);
////��������Ԫ���ۼ�Ԫ���ܺ�
//fill(iterator beg,iterator end,value);
////�����������Ԫ��

void Print(int val){
	cout << val << " ";
}

void test1(){
	vector<int>v;
	for (int i = 0; i <= 100; ++i){
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), Print);
	cout << endl;

	int total = accumulate(v.begin(), v.end(), 0);
	//������������ �ۼӵ� ��ʼֵ
	cout << "total = " << total << endl;

	v.resize(106);
	fill(v.begin() + 101, v.end(), 39);
	for_each(v.begin(), v.end(), Print);
	cout << endl;
}

int main(){
	test1();

	return 0;

}