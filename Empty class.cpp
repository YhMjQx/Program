#include<iostream>
using namespace std;
class Empty{
public:
	Empty* operator&(){
		cout << "ȡַ�����" << endl;
		return this;
	}
	Empty* operator&(){
		cout << "ȡconst��ַ�����" << endl;
		retunr this;
	}
};
int main(){
	Empty e1;
	Empty* p1 = &e1;

	const Empty e2;
	const Empty* p2 = &e2;

	cout << sizeof(Empty) << endl;
	//˵������Ҳ����һ���ֽڵ�
	return 0;
}
//����Ĭ�ϲ����ĳ�Ա��

//Empty();//Ĭ�Ϲ��캯��
//Empty(const Empty& other);//Ĭ�Ͽ������캯��
//~Empty();//Ĭ����������
//Empty& operator=(const Empty& other);//Ĭ�ϵȺ������
//Empty* operator&();//Ĭ��ȡֵ�����
//const Empty* operator&()const;//const�͵�Ĭ��ȡֵ�����
