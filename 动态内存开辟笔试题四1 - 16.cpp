#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void test(void)
{
	char* str = (char*)malloc(20);//一般在正常的代码中这句代码结束之后都需要用if判断返回的指针是否为NULL
	if (str == NULL)
	{
		//应该结束函数
	}
	strcpy(str, "YhMjQx");
	printf(str);
	free(str);//注意，在这里我提前用free释放了str之后，因为free释放空间之后并不会吧str置空，所以str就变成了野指针，
	//对野指针进行操作，是一件非常危险的事，于是，我在free之后一定要手动置空
	str = NULL;//如果没有这一步，整个代码就会有很大危险
	if (str != NULL)
	{
		strcpy(str,"HY1314");
		printf("%s\n", str);
	}
}
int main()
{
	test();
	return 0;
}