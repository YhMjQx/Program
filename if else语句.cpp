#include<stdio.h>
int main()
{
	int input = 0;
	printf("你要好好学习吗?(1/0)>;");
	scanf("%d", &input);
	if (input == 1)
    //if(input==0) 
		printf("胡杨三九合\n");//注意，这里的else默认与上一个未配对的if进行配对，若出现问题则叫悬空else问题 ，可以通过加上{}解决 
	else
		printf("胡杨三九散\n");
	return 0;
}
