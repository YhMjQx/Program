#include<stdio.h>
#include<string.h>
int main()
{           //数组的中括号中必须放的是常量表达式
	int arr1[9] = {1,2,3,4,5};//这种情况和下面的情况一样
	char arr2[5] = { 'H', 'Y' };//这种情况叫做不完全初始化，剩下的元素被默认为0,其中有H Y.
	char arr3[5] = "HY";//期中元素有H Y \0.
	char arr4[] = "hy1314";
	printf("%d\n", sizeof(arr4));//sizeof:计算arr4所占空间的大小，h y 1 3 1 4 \0,共7个
	//sizeof计算变量，数组，类型的大小单位是字节，属于操作符。
	printf("%d\n",strlen(arr4));//求字符串长度，直到\0停止，并且\0不被计算，h y 1 3 1 4,共6个
	//strlen是求字符串长度的，只能针对字符串求长度，属于库函数，需引头文件。
	printf("%d\n", strlen(arr2));
	printf("%d\n", sizeof(arr2));//这里的结果是一个随机值，因为strlen需要寻找\0才会停止，但arr2这个数组并没有包含\0，因此会一直往下寻找，直到随机遇到一个
	return 0;
}