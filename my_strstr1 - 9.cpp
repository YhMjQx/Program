#include<stdio.h>
#include<assert.h>
//KMP �㷨
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
			//(*s1 != '\0')��Ϊ�˱���s1�ĵ�һ���ַ�����\0����ʱ��Ӧ��ֱ������ѭ��
			//(*s2!='\0')��Ϊ�˱���s2�Ѿ���'\0'��ʱ�򣬴�ʱs2�Ѿ���s1�����ҵ�����Ӧ������ѭ��
			//(*s1==*s2)��*s1 != *s2ʱ����Ӧ����cur++����s1����һ���ַ���ʼƥ��Ա�
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
	return NULL;//���һ����һ��while��ʱ��cur����\0����ô�Ӵ��϶��ǲ����ڵģ����Ǳ㷵��NULL
}
int main()
{
	char arr1[] = "abbbcdef";
	const char arr2[] = "bbc";
	char* ret = my_strstr(arr1, arr2);
	//char* strstr(char* ,const char*),���ص���һ��ָ�룬�����������Ŀ�����ص���abcdefabcdef���еĵ�һ��b�ĵ�ַ
	if (ret == NULL)
	{
		printf("�Ӵ�������\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	return 0;
}