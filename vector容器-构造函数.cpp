#include<iostream>
#include<vector>
using namespace std;

//vector�Ŀռ䲻����ʱ�򲻻�ȥ������ռ乻����������ֱ��ѡ��һƬ�㹻�Ŀռ佫ԭ�������ݿ�����ȥ
//�ͷ�ԭ�пռ䣬Ȼ�󷵻���Ƭ�µĿռ�

void Printvector(vector<int>&v){
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	vector<int> v1;
	for (int i = 0; i < 5; ++i){
		v1.push_back(i);
	}
	Printvector(v1);

	//ͨ������ķ�ʽ���й���
	vector<int>v2(v1.begin(), v1.end());//��������䶼������ҿ�
	Printvector(v2);

	//n��num�Ĺ��췽ʽ
	vector<int>v3(10, 39);
	Printvector(v3);

	//��������
	vector<int>v4(v3);
	Printvector(v4);


}

int main(){
	test1();
	return 0;
}