#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
int main()
{
	char arr1[] = "let us cheer YhMjQx!";
	char arr2[] = "#&*#&*#&*#&*#&*#&*#&";
	int left = 0;//left��right�����±꣬������Ҫ����Ԫ������һ
	int right = strlen(arr1)-1;
	while (left <= right)
	{
		arr2[left] = arr1[left];//�����Ǹ��ַ�
		arr2[right] = arr1[right];//�����Ǹ��ַ�
		printf("%s\n", arr2);//ÿ�ı�һ�δ�ӡһ���Ա����ֱ任
		Sleep(500);
		system("cls");
		//�����Ļ����
		left++;
		right--;
	}
	printf("%s\n", arr2);
	//���systemʹ��
	return 0;
}