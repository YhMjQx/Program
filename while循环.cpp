#include<stdio.h>
int main()
{
	int line = 0;//�������
	printf("ѧ���������������Ϻ���\n");//���printfһ��Ҫ��whileǰ�棬����ͻ�ȫ����ӡprintf�е����� 
	scanf("line=%d",&line) ;
	while (line < 20000)//ѭ�����
	{
		printf("ѧC���ԣ�����������Ϊ�˺���%d\n",line);//Ҫ���line��ֵ��printf��������������%d����ֵ��line
		line++;//line�Լ�
	}
	if (line >= 20000)
		printf("�м������������������\n");
	return 0;
}
