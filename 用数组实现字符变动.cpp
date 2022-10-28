#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
int main()
{
	char arr1[] = "let us cheer YhMjQx!";
	char arr2[] = "#&*#&*#&*#&*#&*#&*#&";
	int left = 0;//left和right都是下标，固其需要数组元素数减一
	int right = strlen(arr1)-1;
	while (left <= right)
	{
		arr2[left] = arr1[left];//现在是赋字符
		arr2[right] = arr1[right];//现在是赋字符
		printf("%s\n", arr2);//每改变一次打印一次以便体现变换
		Sleep(500);
		system("cls");
		//清空屏幕操作
		left++;
		right--;
	}
	printf("%s\n", arr2);
	//配合system使用
	return 0;
}