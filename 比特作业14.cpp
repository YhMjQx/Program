#include <stdio.h>
#include<string.h> 
//�������������������ĳ���,��ȫ������strlen�⺯�����е��� 
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
void string(char str[])//�Ƚ���������� 
{
        int left = 0;
        int right = strlen(str) - 1;//����һ���͵���my_strlen������������β�����str����my_strlen���������
		                               //����ú�����������ʵ������ĳ��ȣ��൱��ִ����һ��strlen������ 
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
//�����ڲ��õ���str���飬��ʵ������str����arrȻ����str�������
//���������ڲ��õ���arr������飬����ʵ������Ϊarr���β�����Ϊstr 
int main()
{
        char arr[] = "abcedf";
        string(arr);//��arr������鴫��string��������������ڲ���str����arr 
        printf("%s\n",arr);
        return 0;
}

