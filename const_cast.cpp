#include<iostream>
using namespace std;
void fun(int& refval){
	cout << "fun=" << refval << endl;
}
int main(){
	//1.const_cast<>()�����Ƴ�������
	//2.const_cast<>()һ���Ƕ�ָ�������ʹ��
	//3.const_cast<>()ȥ�������Բ���Ϊ���޸�����ָ�������
	//4.const_cast<>()ȥ�������ԣ�const����Ϊ�˺����ܹ�����ʵ��
	//5.<>�б�����ָ�룬���ã�������ָ��������ͳ�Ա��ָ��
	const int val = 39;
	//int n = const_cast<int>(val);
	//error��仰û���κ����壬const intȥ��const���ֱ����int������int����û���κ�����

	//int* p = &val; - const int* ���͵�ֵ�������ڳ�ʼ��int*���͵�ֵ
	int* p = const_cast<int*>(&val);
	//&val����Ӧ����const int*��Ȼ������ת���������int*
	*p = 93;
	cout << "val=" << val << endl;//�������39����Ҳ��֤�˵�3��
	cout << "p=" << p << endl;
	cout << "&val=" << &val << endl;
	//��˵��p��&val��һ���ģ����ǵ�ȷ����ͨ��ָ�����ı�val��ֵ
	//fun(val);error - �޷���const����������const����
	fun(const_cast<int&>(val));//�����93
	//�������Ѿ�ͨ��p��val�ı��ˣ�����ʵ����val��û�иı䣬��������������ȴ�����˸ı�
	//���Լ�������ǣ�
	//������val��ȷû�иı䣬���ǻ���һ��p�ĵ�ַ��val�ĵ�ַ��һ������ô������������֮��
	//��û�п��ܣ����õĲ�����������val�����Ǻ����β���Ϊ*p�ı�������*p��&val����ͬһ��ռ�
	//������������ʱ�����ó�ʼ���Ķ����*p������val���ʣ�valû�иı䣬*p�����˸ı�
	cout << "val=" << val << endl;//�������39����Ҳ��֤�����Լ����뷨

	return 0;
}