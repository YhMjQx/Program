#include<stdio.h>
struct S
{
	int n;
	float score;
	char arr[10];
};
int main()
{
	struct S s = { 100, 13.14f,"YhMjQx" };
	FILE* pf = fopen("TEXT.txt", "w");
	if (pf == NULL)
	{
		return 0;
	}
	//��ʽ����д�ļ�
	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);//���ṹ����д�õ����������pfָ����ļ�����ȥ
	fclose(pf);
	pf = NULL;
	return 0;
}
