#include<stdio.h>
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1,5,7 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);//���������Ԫ�ظ�����ΪʲôҪ��������أ���Ϊ������Ԫ�ظ����ı�֮�󣬸Ĵ�����������
	int ret = 0;
	for (i = 0; i < sz; i++)
	{
		ret = ret^arr[i];//����ʹ�ã�eg��3^3=0 5^5=0 a^a=0 0^3=3 0^a=a 3^5^3=5 3^3^5=5��������Ƿ��Ͻ����ɵġ�
	}
	printf("��������=%d", ret);
	return 0;
}