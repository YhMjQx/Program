#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//reverse(iterator bed, iterator end);
//��תָ����Χ�ڵ�Ԫ��

void Print(int val){
	cout << val << " ";
}

void test1(){
	vector<int>v;
	v.push_back(39);
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}
	v.push_back(39);
	cout << "��תǰ��" << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;

	reverse(v.begin() + 1, v.end() - 1);
	cout << "��ת��" << endl;
	for_each(v.begin(), v.end(), Print);
	cout << endl;


}
int main(){
	test1();

	return 0;
}