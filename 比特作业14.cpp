#include <stdio.h>
#include<string.h> 
//这个函数用来计算数组的长度,完全可以用strlen库函数进行调用 
int my_strlen(char * str)
{
        int count = 0;
        while('\0' != *str)
        {
                str++ ;
                count++ ;
        }
        return count;
}
void string(char str[])//先进入这个函数 
{
        int left = 0;
        int right = strlen(str) - 1;//到这一步就调用my_strlen这个函数，将形参数组str传给my_strlen这个函数，
		                               //这个该函数用来计算实参数组的长度，相当于执行了一个strlen的作用 
        while(left < right)
        {
                //int len = strlen(str);
                char temp = str[left];
                str[left] = str[right];
                str[right] = temp;
                left++ ;
                right--;
        }
}
//函数内部用的是str数组，其实就是用str接收arr然后用str这个数组
//而主函数内部用的是arr这个数组，即：实参数组为arr，形参数组为str 
int main()
{
        char arr[] = "abcedf";
        string(arr);//把arr这个数组传给string这个函数，函数内部的str就是arr 
        printf("%s\n",arr);
        return 0;
}

