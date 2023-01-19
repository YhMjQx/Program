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
	//格式化的写文件
	fprintf(pf, "%d %f %s", s.n, s.score, s.arr);//将结构体中写好的数据输出到pf指向的文件当中去
	fclose(pf);
	pf = NULL;
	return 0;
}
