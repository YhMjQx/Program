#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//adjacent_find(iterator beg, iterator end);
//���������ظ�Ԫ�أ���������Ԫ�صĵ�һ��λ�õĵ�����


void test1(){
	vector<int>v;
	v.push_back(2);
	v.push_back(0);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);

	v.push_back(1);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);

	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos == v.end()){
		cout << "û�ҵ������ظ�Ԫ��";
	}
	else{
		cout << "�ҵ��������ظ�Ԫ�أ�" << *pos << endl;
	}
	cout << *(++pos) << endl;//������Ϳ�����֤���صĵ������������ظ�Ԫ�صĵ�һ��Ԫ�صĵ�����

}

int main(){
	test1();

	return 0;
}