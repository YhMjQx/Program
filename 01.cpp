#include"Text.h"
int main(){
	Text t ;
	t.Init();
	t.Init(39);
	//t.Init(&t, 39);������thisָ��ʵ�������������ģ�������ʡ���ˣ������Ϳ������ҵĺ�����׼�ҵ�ִ�ж���
	t.Display();
	return 0;
}