#include<stdio.h>
int main()
{
	int input = 0;
	printf("��Ҫ�ú�ѧϰ��?(1/0)>;");
	scanf("%d", &input);
	if (input == 1)
    //if(input==0) 
		printf("�������ź�\n");//ע�⣬�����elseĬ������һ��δ��Ե�if������ԣ������������������else���� ������ͨ������{}��� 
	else
		printf("��������ɢ\n");
	return 0;
}
