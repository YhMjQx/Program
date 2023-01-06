#include<stdio.h>
#include<string.h>
#include<assert.h>
void Round(char* str, int k)
{
	assert(str != NULL);//assert()括号当中放的是个表达式
	int len = strlen(str);
	int i = 0;
	for (i = 0; i < k; i++)//这里循环用k是为了控制旋转多少个字符
	{
		//第一步：将首字符放空
		char tmp = *str;
		int j = 0;
		//第二步：将首字符后面的字符往前移动
		for (j = 0; j < len - 1; j++)
		{
			*(str+j) = *(str + j+1);
		}
		//第三步：将放空的首字符放在最后一个字符的位置
		*(str + len - 1) = tmp;
	}
}
int main()
{
	char ch[] = "YhMjQx";
	int k = 3;
	Round(ch, k);
	printf("%s\n", ch);
	return 0;
}