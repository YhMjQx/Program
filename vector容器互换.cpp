#include<iostream>
#include<vector>
using namespace std;

void Printvector(vector<int>& v){
	for (int i = 0; i < v.size(); ++i){
		cout << v[i] <<" ";
	}
	cout << endl;
}

//����ʹ��
void test1(){
	vector<int> v1;

	cout << "����ǰ��" << endl;
	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
	}
	cout << "v1:" << "";
	Printvector(v1);
	
	vector<int>v2;
	for (int i = 10; i>0; --i){
		v2.push_back(i);
	}
	cout << "v2:" << "";
	Printvector(v2);

	cout << "������" << endl;

	v2.swap(v1);
	cout << "v1:" << "";
	Printvector(v1);
	cout << "v2:" << "";
	Printvector(v2);

}

//ʵ����;
//����swap���������ڴ�ռ�
void test2(){
	vector<int >v1;
	for (int i = 0; i < 393939; ++i){
		v1.push_back(i);
	}

	cout << "v1������Ϊ�� " << v1.capacity() << endl;
	cout << "v1�Ĵ�СΪ�� " << v1.size() << endl;

	v1.resize(3939);//��v1����ָ��һ����С
	cout << "v1������Ϊ�� " << v1.capacity() << endl;
	cout << "v1�Ĵ�СΪ�� " << v1.size() << endl;
	//��ʱ���ǻᷢ�֣�v1���������С��ȷ�Ǳ�С�ˣ�����v1������������ô��˵�������������˷��ڴ�ռ�
	//��ô���Ǹ���λ�����Ƭ���˷ѵ��ڴ�ռ��أ����������Ҳ���

	vector<int>(v1).swap(v1);
	cout << "v1������Ϊ�� " << v1.capacity() << endl;
	cout << "v1�Ĵ�СΪ�� " << v1.size() << endl;

	//vector<int> - ����һ�����ͣ�Ȼ����������ʹ�����һ����������
	//�������������ʹ��v1������������ģ��������������Ĵ�С�Լ����ڲ���������һ����
	//��ô��˵�����������������ʹ�С��3939
	//Ȼ���������������������swap���������������������v1���л���
	//�������ڵ�v1��������С����3939���������ڲ�������Ҳ����ı�
	//��ô������������Ͷ�Ӧ����ԭ��v1��Ӧ�Ŀռ�
	//���Ǳ�������ִ����������֮�󣬷�������һ�������������ͻ�����������������
	//��������Ҳ���ö������������������������������ǲ�����
}

int main(){
	//test1();
	test2();
	return 0;
}