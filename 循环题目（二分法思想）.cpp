#include<stdio.h>
int main()
{
	int arr[] = {  1, 3, 5, 7, 9, 2, 4, 8, 6, 10,11 };//�����k�������������
	int k = 0;

	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("������k��ֵ (k��ֵӦ�ڸ�����֮��) :");
	scanf("%d", &k);
	int left = 0;
	int right = sz - 1;
	while (left<=right)
	{
		int mid = (left + right) / 2;//
		if (arr[mid] > k)//
		{//
			right = mid - 1;//
		}//
		else if (arr[mid] < k)//
		{//
			left = mid + 1;//
		}//
		else//arr[i]�Ȳ���k���ֲ���kС����ֻ��arr[i]=k��ֻ�������ʱ��i���� 
		{//
			printf("�ҵ��ˣ��±��ǣ�%d", mid);//
			break;//
		}//
		//��ע�˵������ѭ�������Ҫ��ɲ���
	}
	if (left>right)
	{
		printf("�Ҳ�����");
	}
	return 0;
}
