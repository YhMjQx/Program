#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//����ָ��Ԫ���Ƿ����
//bool binary_search(iterator beg, iterator end, value); 
//����ָ��Ԫ�أ��ҵ�����true��û�ҵ�����false
//ע�⣺�����������в�����

void test1(){
	
	vector<int >v;
	for (int i = 0; i < 10; ++i){
		v.push_back(i);
	}
	//v.push_back(0);
	//binary_serach�����ҵ����в�������������
	bool ret = binary_search(v.begin(), v.end(), 9);

	if (ret == true){
		cout << "�ҵ���" << endl;
	}
	else{
		cout << "δ�ҵ�" << endl;

	}

}

int main(){
	test1();

	return 0;
}