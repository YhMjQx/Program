#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
struct S
{
	int key;
	char arr[];//柔性数组成员之前必须至少包含一个成员
};
//柔性数组：结构体中的最后一个成员允许是未知大小的数组，叫做柔性数组成员
//计算结构体大小的时候，柔性数组成员并不在计算范围之内

void encode(struct S* ps){

	printf("密钥大小：");
	scanf("%d", &(ps->key));
	printf("加密字符串：");
	scanf("%s", ps->arr);

	int i = 0;
	
	for (int i = 0; ps->arr[i] != '\0'; ++i){
		ps->arr[i] = (ps->arr[i] - 'a' + ps->key) % 26 + 'a';
		//加‘a'是为了将ASCII值转换为字符存储
	}
	printf("密文：%s\n", ps->arr);

}

void decode(struct S* ps){

	printf("密钥大小：");
	scanf("%d", &(ps->key));
	printf("解密字符串：");
	scanf("%s", ps->arr);
	
	int i = 0;
	for (i = 0; ps->arr[i] != '\0'; ++i){
		ps->arr[i] = (ps->arr[i] - 'a' - ps->key) % 26 + 'a';
		
	}
	printf("明文：%s\n", ps->arr);
}

int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S) + 100 * sizeof(char));
	//这样的开辟内存的方式让n的内存空间和arr的内存空间紧密的开辟在一起

	if (ps == NULL){
		return 0;
	}
	ps->key = 0;

	printf("加密过程：\n");
	encode(ps);
	printf("解密过程：\n");
	decode(ps);

	free(ps);
	ps = NULL;
	return 0;
}

