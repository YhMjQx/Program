#include<stdio.h>
//���Ͼ���һ�����־��󣬾����ÿһ�д������ǵ����ģ�������ϵ���Ҳ�ǵ�����
//��д�����������ľ����в���һ�����ֵĴ���
int Findnum(int arr[3][3], int k, int* px, int* py)
{
	//ȷ�����Ͻ����ֵ��±�
	int x = 0; 
	int y = *py - 1;
	while ((x<=*px-1)&&(y>=0))
	{
		if (arr[x][y] > k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	//�Ҳ���
	return 0;
}
int main()
{
	int arr[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int k = 0;
	//�����x��y��������У�����
	int x = 3;
	int y = 3;
	printf("����������Ҫ���ҵ����֣�");
	scanf("%d", &k);
	int ret = Findnum(arr, k, &x, &y);//����ʱ��������ȡ��ַ�����������Ͳ��������ں����ڲ��ı����
	if (ret == 1)
	{
		printf("�ҵ��ˣ������ֵ��±���%d %d\n", x, y);
	}
	else
	{
		printf("�Ҳ���\n");
	}
	return 0;
}