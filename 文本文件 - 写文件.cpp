#include<iostream>
#include<fstream>
using namespace std;

//�ı��ļ� - д�ļ�
void test1(){
	//����������
	ofstream ofs;

	//ָ���򿪷�ʽ
	ofs.open("test.txt",ios::out);

	//д����
	ofs << "����������ǿ" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;
	ofs << "---------------------" << endl;
	ofs << "������������" << endl;
	ofs << "�Ա�Ů" << endl;
	ofs << "���䣺18" << endl;

	//�ر��ļ�
	ofs.close();

}

int main(){

	test1(); 
	return 0;
}