#include<stdio.h>
#include<assert.h>
//KMP 算法
char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 && p2);
	if (*p2 == '\0')
	{
		return NULL;
	}
	char* s1 = (char*)p1;
	char* s2 = (char*)p2;
	char* cur = (char*)p1;
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)p2;
		while (*s1 && *s2 && !(*s1 - *s2))//while((*s1!='\0') && (*s2!='\0') && (*s1==*s2))
		{
			//(*s1 != '\0')是为了避免s1的第一个字符就是\0，此时就应该直接跳出循环
			//(*s2!='\0')是为了避免s2已经是'\0'的时候，此时s2已经在s1当中找到，就应该跳出循环
			//(*s1==*s2)当*s1 != *s2时，就应该让cur++，从s1的下一个字符开始匹配对比
			s1++;
			s2++;
		}
		if (!*s2)//if(*s2=='\0')
		{
			return cur;
		}
		if (!*s2)//if(*s2=='\0')
		{
			return NULL;
		}
		cur++;
	}
	return NULL;//如果一进第一个while的时候，cur就是\0，那么子串肯定是不存在的，于是便返回NULL
}
int main()
{
	char arr1[] = "abbbcdef";
	const char arr2[] = "bbc";
	char* ret = my_strstr(arr1, arr2);
	//char* strstr(char* ,const char*),返回的是一个指针，类似于这个题目，返回的是abcdefabcdef当中的第一个b的地址
	if (ret == NULL)
	{
		printf("子串不存在\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}