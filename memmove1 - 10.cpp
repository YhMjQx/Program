#include<stdio.h>
#include<string.h>
#include<assert.h>
void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest&&src);
	void* ret = dest;
	if (dest < src)//��ǰ��󿽱�
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else//�Ӻ���ǰ����
	{
		while (num--)//20����--���19���պ���������Ҫ�Ĵ�С
		{
			*((char*)dest + num) = *((char*)src + num);
		}
		return ret;
	}
	//if ((dest<src) || (dest>((char*)src + num)))
	//{
	//	while (num--)
	//	{
	//		*(char*)dest = *(char*)src;
	//		++(char*)dest;
	//		++(char*)src;
	//	}
	//}
	//else
	//{
	//	while (num--)
	//	{
	//		*((char*)dest + num) = *((char*)src + num);
	//	}
	//}
	//return ret;
}
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//memmove(arr1 + 2, arr1, 20);
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d ", arr1[i]);
	//}
	my_memmove(arr1 + 2, arr1, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}