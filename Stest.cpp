#include"String.h"
#include<stdio.h>
int main(){
	String s1("HYHYHY");
	char ch1 = s1[2];
	cout << ch1 << endl;
	char ch2 = s1[3];
	cout << ch2 << endl;
	//���Ƕ�[]�Ķ����ʵ���õ������õķ���ֵ����ô���ĺô���ʲô�أ�
	//�����������õĺô��ǿ����ú�������"="��߸������Ľ�����и�ֵ�͸ı䣬���£�
	s1[3] = 'H';
	s1.Display();
	s1[2] = 'Y';
	s1[3] = 'Y';
	s1.Display();
		//���ϴ�����õĶ���non const �汾��operator[]

	const String s2("abcdef");
		//��Ȼ�ҵĶ�����const�ģ���ô�ҾͲ�ϣ���ҵĶ��󱻸ı�
		//�����������ĸı���Ǹ��ҵ�operator[]ǰ�����const
		//��Ϊ�˷�ֹ���ز�ͨ��(��Ϊ��������������ֻ����Ϊ�������Ͳ�ͬ�ĺ���)
		//�������ں������Ҳ������const���Σ������ҵķ������;���const���ã���ô�����s2[2]�����޷��ı��
	char ch = s2[2];//���Խ�const char&��ֵ����char
	//s2[2] = 'A';//�����ܽ�char��ֵ����const char&
	s2.Display(); 
		//�ⲿ�ִ�����õ��� const �汾��operator[]


	String s3("HHH");
	String s4("YYY ");
		//������캯��û��explicit���εĻ��������������൱��
		//String s3 = "HHH";
		//String s4 = "YYY";
	String s5 = s3 + s4;
	s3 += s4;
	s5.Display();
	s3.Display();
	cout << s3 << endl;

	
	String s6 = "YhMjQx " + s5 + "1314";
		//String s6 = "YhMjQx " + "1314" + s5;��������Ͳ����ˣ���Ϊ���ǲ�û����������char*�ַ�����ӵ�operator+()����
		//��ˣ���ǰ���������ӵ���������һ��Ҫ�Ƕ���,Ȼ��ſ���ת��
	s6.Display();

	String s7;
	cin >> s7;
	cout << s7 << endl;

	return 0;
}