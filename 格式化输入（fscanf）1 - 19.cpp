#include<stdio.h>
struct S
{
	int n;
	float score;
	char arr[10];
};
int main()
{
	struct S s = { 0 };
	FILE* pf = fopen("TEXT.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
	//��ʽ���Ķ��ļ�
	fscanf(pf, "%d %f %s", &(s.n), &(s.score), s.arr);//����pfָ����ļ��ж������ļ����뵽�ṹ����
	//������������printf�����Ƿ񽫶�ȡ�������ݳɹ����뵽�˽ṹ�嵱��
	printf("%d %f %s", s.n, s.score, s.arr);
	fclose(pf);
	pf = NULL;
	return 0;
}