#include<iostream>
using namespace std;
class Test{
public:
	Test(int num):num_(num){
		cout << "Test... " << num_ << endl;
	}
	~Test(){
		cout << "~Test... " << num_ << endl;
	}
private:
	int num_;
};

Test g1(39);	//ȫ�ֶ���Ĺ�������main����
static Test g2(93);	//��̬ȫ�ֶ���Ĺ�������main����
int n;	//δ��ʼ����ȫ�ֱ���Ĭ��ֵΪ0,��ʱδ��ʼ����ȫ�ֱ������߾�̬ȫ�ֶ���洢��.bss��
int n2 = 100;	//�ѳ�ʼ����ȫ�ֱ������߾�̬ȫ�ֱ����洢��.data��
int main(){
	cout << "Entering main..." << endl;
	cout << n << endl;
	Test t1(1);	//ջ����
	{
		Test t2(2);	//ջ����
	}

	{
		Test* t3 = new Test(3);	//���ϴ����Ķ�����Ҫ��ʽ�ͷ�
		delete t3;//������������ڲ���ͬ���������û���ͷţ���ôt3ֻ�ǳ���������
		//�������޷����ʵ�t3���ѣ���t3�������ڻ����ڣ���Ϊ�������ݶ���û���ͷ�
	}
	{
		//�ѳ�ʼ���ľ�̬�ֲ������洢��.data����
		//δ��ʼ���ľ�̬�ֲ������洢��.bss����
		static int n3;	//�洢��.bss�� �����ڳ�ʼ��
		static int n4 = 200;	//�洢��.data�� �����ڳ�ʼ��

		static Test t4(300);	//�洢��.data �Σ�t4�����������ڳ�ʼ��
	}
	cout << "Entering main..." << endl; 
	return 0;
}