#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//vector�������������������
void Printvector(int val){
	cout << val << endl;
}

void test1(){
	vector<int> v;

	//�������в�������
	for (int i = 10; i <= 50; i += 10){
		v.push_back(i);
	}


	////��һ�ֱ�����ʽ
	////ͨ�������������������е�����
	//vector<int>::iterator itBegin = v.begin();//itBegin ָ�������еĵ�һ��Ԫ��
	//vector<int>::iterator itEnd = v.end();//itendָ�������е����һ��Ԫ�ص���һ��λ��
	//while (itBegin != itEnd){
	//	cout << *itBegin << " ";
	//	++itBegin;
	//}
	//cout << endl;


	////�ڶ��ֱ�����ʽ
	//for (vector<int>::iterator it = v.begin(); it < v.end(); ++it){
	//	cout << *it << " ";
	//}
	//cout << endl;


	//�����ֱ�����ʽ ����STL�ṩ�ı����㷨
	for_each(v.begin(), v.end(), Printvector);//ʹ���˻ص�����

}

int main(){
	test1();
	return 0;
}
