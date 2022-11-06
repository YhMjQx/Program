#include<stdio.h>
#include<string.h>
//My_strlen("hy39")
//1+My_strlen("y39")
//1+1+My_strlen("39")
//1+1+1+My_strlen("9")
//1+1+1+1+My_strlen("")
//1+1+1+1+0=4
int My_strlen(char* str)//递归的方式，把大事化小
{
	if (*str != '\0')
		return 1 + My_strlen(str + 1);//不停地递减字符串的长度每递减一次前面加个一，这样就算出来了
	else
		return 0;
}
int main()
{
	char arr[] = "hy39";//h y 3 9 \0
	printf("长度=%d\n", My_strlen(arr));
	return 0;
}