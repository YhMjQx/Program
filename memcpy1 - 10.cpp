#include<stdio.h>
#include<string.h>
#include<assert.h>
struct stu
{
	char name[39];
	int age;
};
void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest&&src);
	void* ret = dest; 
	while (num--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}
	return ret;
}
int main()
{
	//void* memcpy(void* destination,const char* source,size_t num)
	//size_t num ����Ԫ�ظ����������޷��ŵ��ֽ���,�����ʱ�����д��sizeof(arr)
	//C���Թ涨��memcpyֻ��Ҫ�����ڴ治�ص��Ŀ���������ɣ�memmove��ר���������ڴ��ص��ĵĿ��������
	//������VS2013�����£�memcpy��memmove�Ĺ��ܱ��һ������,Ҳ����˵��VS2013�����µ�memcpy�ǳ�����������
	int arr1[] = { 5, 2, 1, 3, 9 };
	int arr2[5] = { 0 };
	my_memcpy(arr2 , arr1, sizeof(arr1)); 
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}
	//struct stu H[2] = { { "����ǿ", 18 }, { "������", 18 } };
	//struct stu Y[3] = { 0 };
	//my_memcpy(Y, H, sizeof(H));
	return 0;
}
