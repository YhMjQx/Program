#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void test1(){
	//����ͷ�ļ�

	//����������
	ifstream ifs;

	//���ļ��������ж��Ƿ�򿪳ɹ�
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()){
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//������
	char buf[1024] = { 0 };

	while (ifs >> buf){
		//������ȫ�����꣬Ҳ�����ļ�����β��֮�󣬾ͻ��Զ�����
		cout << buf << endl;
	}
	//�ر��ļ�
	ifs.close();
}

void test2(){

	//����������
	ifstream ifs;

	//���ļ��������ж��Ƿ�򿪳ɹ�
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()){
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//������
	char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf))){
		cout << buf << endl;
	}
	//�ر��ļ�
	ifs.close();
}

void test3(){
	//����������
	ifstream ifs;

	//���ļ��������ж��Ƿ�򿪳ɹ�
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()){
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//������
	string buf;
	while (getline(ifs, buf)){
		cout << buf << endl;
	}
	//�ر��ļ�
	ifs.close();
}
int main(){

	//test1();
	//test2();
	test3();
	return 0;
}