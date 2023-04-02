#include<iostream>
using namespace std;
class Date{
public:
	Date(int year) :year_(year){

	}
	static bool IsLeapYear(int year){
		return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	}
	bool IsLeapYear(){
		return ((year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0));
	}
private:
	int year_;
};
int main(){
	Date d = 2022;
	cout << d.IsLeapYear() << endl;

	cout << Date::IsLeapYear(2023) << endl;
	return 0;
}
//�����ض����͵�ȫ�������ԣ���ʱ�������Ҫ����һ��ȫ�ֵı�����
//����˵ͳ��ĳ�����Ͷ����Ѵ���������
//���������ȫ�ֶ�����ƻ����ݵķ�װ��һ����û����붼�����޸����ȫ�ֱ�����
//��ʱ���ǿ�������ľ�̬��Ա������������
//��static���ݳ�Ա�����������͵�ÿ�������У�static���ݳ�Ա������������������ڣ�
//������������Ķ��󣬲���������
//��static��Ա���������ÿ��������һ�ݿ���


//static��Ա���ŵ㣺
//1.static��Ա������ʵ���۵��������У���˿��Ա������������Ա��ȫ�ֶ������ֳ�ͻ
//2.����ʵʩ��װ��static��Ա������˽�еģ���ȫ�ֶ��󲻿���
//3.�Ķ��������׿���static��Ա��ĳ��������������ֿɼ��Կ��������ط�ӳ����Ա����ͼ
//static��̬��Ա����������Ҫ������󣬾���ֱ�ӷ��ʲ�ʹ�ã�����Ҫֱ������������

//��̬��Ա�������ܷ��ʷǾ�̬���ݳ�Ա
//1.static��Ա����û��thisָ��
//2.�Ǿ�̬��Ա�������Է��ʾ�̬��Ա
//3.static��̬��Ա���������Է��ʷǾ�̬��Ա�������Ǿ�̬��Ա������