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
	//格式化的读文件
	fscanf(pf, "%d %f %s", &(s.n), &(s.score), s.arr);//将从pf指向的文件中读到的文件输入到结构体中
	//在这里我们用printf看看是否将读取到的数据成功输入到了结构体当中
	printf("%d %f %s", s.n, s.score, s.arr);
	fclose(pf);
	pf = NULL;
	return 0;
}