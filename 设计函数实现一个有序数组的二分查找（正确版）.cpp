#include<stdio.h>
int binary_search(int arr[], int k,int sz)
{                //���������arr��һ��ָ��
	//�㷨��ʵ��
	int left = 0;
	int right = sz - 1;
	while (left <= right)//ע��Ⱥ�ҲҪ��Ŷ
	{
		int mid = (left + right) / 2;//��仰һ��ֻ����ѭ�������棬�������ѭ�����棬��ÿһ�ε�mid�м�ֵ���±궼���䣬�Ǿʹ�����
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid]>k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;//�ҵ��˵�ʱ�򣬷��ص����±�
		}
	}
	return -1;//�Ҳ�����ʱ�򷵻ص���-1
}
int main()
{
	int i = 0;
	//��һ�������������ö��ֲ����ҳ�ĳ����������ҵ��˷�����������±꣬���û�ҵ�������-1
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int k = 7;
	int ret = binary_search(arr, k,sz);//�ú�����arr����ȥ���ң�ȥ���ҵ���k��Ȼ����Һ󷵻صĽ�����±꣩����ret
	if (-1 == ret)                  //���ﴫ��ȥ���������еĵ�һ��Ԫ�صĵ�ַ
	{
		printf("�Ҳ���ָ��������\n");
	}
	else
	{
		printf("�ҵ����±��ǣ�%d \n", ret);
	}
	return 0;
}//��д���������ô�ã���ȥд����