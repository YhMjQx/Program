#include<iostream>
#include<vector>
using namespace std;

void Printvector(vector<int>& v){
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
}

void test1(){
	vector<int>v1;
	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
	}
	Printvector(v1);

	if (v1.empty()){
		cout << "v1Ϊ��" << endl;
	}
	else{
		cout << "v1��Ϊ��" << endl;
		cout << "v1������Ϊ��" << v1.capacity() << endl;
		cout << "v1�Ĵ�СΪ��" << v1.size() << endl;
	}


	//����ָ����С
	v1.resize(15,39);//��������ƶ��Ĵ�С��������ô��Ĭ����0��������Ŀռ�
						//��Ȼ��Ҳ������ָ����ֵ��������Ŀռ�
	Printvector(v1);

	v1.resize(10);//��������ƶ��Ĵ�С��ԭ��С���򳬳��Ĳ��ֻᱻɾ��
	Printvector(v1);

}

int main(){
	test1();
	return 0;
}