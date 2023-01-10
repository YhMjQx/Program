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
	//size_t num 不是元素个数，而是无符号的字节数,数组的时候可以写成sizeof(arr)
	//C语言规定：memcpy只需要处理内存不重叠的拷贝情况即可，memmove是专门来处理内存重叠的的拷贝情况的
	//但是在VS2013环境下，memcpy和memmove的功能变成一样的了,也就是说，VS2013环境下的memcpy是超额完成任务的
	int arr1[] = { 5, 2, 1, 3, 9 };
	int arr2[5] = { 0 };
	my_memcpy(arr2 , arr1, sizeof(arr1)); 
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}
	//struct stu H[2] = { { "杨明强", 18 }, { "胡佳欣", 18 } };
	//struct stu Y[3] = { 0 };
	//my_memcpy(Y, H, sizeof(H));
	return 0;
}
