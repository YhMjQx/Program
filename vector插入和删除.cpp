#include<iostream>
#include<vector>
using namespace std;

//push_back(ele);//β����������ele
//pop_back(ele);//β��ɾ������ele
//insert(const_iterator pos, ele);//�ڵ�����ָ���λ��pos����������ele
//insert(const_iterator pos,int count, ele);//�ڵ�����ָ���λ��pos������count������ele
//erase(const_iterator pos);//ɾ��������posָ��λ�õ�����
//erase(const_iterator start,const_iterator end);//ɾ����������start��end֮���Ԫ��
//clear();//ɾ������������Ԫ��



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

	//βɾ
	v1.pop_back();
	Printvector(v1);

	//����
	v1.insert(v1.begin(), 39);//��һ�������ǵ�����������������λ��
	Printvector(v1);

	v1.insert(v1.begin(), 2, 39); //��һ�������ǵ�����������������λ��
	Printvector(v1);

	//ɾ��
	v1.erase(v1.begin());//�����ǵ�����������������λ��
	Printvector(v1);

	//���
	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	Printvector(v1);

}

int main(){
	test1();
	return 0;
}