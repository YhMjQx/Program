#include<iostream>
using namespace std;
#ifndef _TEXT_H_
#define _TEXT_H_
//��������Ҳ�������أ��������ص�Ҫ����Ҫ����ͬ������
//ͬ���������������ؾ���Ҫ�����ڲ�
//������thisָ�룺
/*��Ա������һ�������ĸ����βΣ�����ָ��ö����ָ�룬����������βν���thisָ��
ʹ��thisָ�뱣֤��ÿ���������ӵ�в�ͬ�����ݳ�Ա����������Щ��Ա�Ĵ��루��Ա���������Ա����ж�����*/
class Text{
public:
	int Add(int a, int b){
		return a + b;
	}
	//��Ҳ��һ�ֶ������������ķ�ʽ�������Ｔʹû��inline�ؼ���Ҳ����
	void Init();
	void Init(int x);
	void Init(int x, int y);
	void Init(int x, int y, int z);
	//��Щ����������ͬ������������ͬ���������� 

	//��������ȱʡ��������ƺ���
	void Init(int x = 0, int y = 0, int z = 0);// ����ȱʡ�����Ķ��巽ʽ
	void Display();
private:
	int x_;
	int y_;
	int z_;
};
#endif //_TEXT_H_