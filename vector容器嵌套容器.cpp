#include<iostream>
#include<string>
#include<vector>
using namespace std;



void test1(){
	vector<vector<int>>v;

	//�ȴ���С������Ȼ���С������������
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;
	vector<int>v5;

	for (int i=0;i<5;++i){
		v1.push_back(i);
		v2.push_back(i + 1);
		v3.push_back(i + 2);
		v4.push_back(i + 3);
		v5.push_back(i + 4);
	}

	//���ڽ�С���������������
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	//���õ���������������
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); ++it){
		//����ͻ�ִ��5�δ��forѭ�����ֱ�������v1��v2��v3��v4��v5
		//Ȼ������һ��forѭ��������ÿһ��С������
		//(*it) - vector<int>
		for (vector<int>::iterator jt = (*it).begin(); jt != (*it).end(); ++jt){
			cout << (*jt) << " ";
		}
		cout << endl;
	}

}

int main(){
	test1();
	return 0;
}