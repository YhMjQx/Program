#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_LEN 50
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

struct S{
	int k;
	char text[];
};

void Bincode(char* str){
	while (*(str)){
		for (int i = 7; i >= 0; --i){
			printf("%c", (*str & (1 << i)) ? '1' : '0');
		}
		//(1 << i)  将1向左移动i位，在for循环的环境下，可以使得检验到每个字符的二进制的每一位
		//(*str & (1 << i)) 配合三目操作符，将每一位字符中的每一位二进制与 1 进行对比，如果该位二进制等于 1 ，就返回显示 1 ，反之则显示 0 
		printf(" ");
		++str;
	}
	printf("\n");
}

void Hexcode(char* str){
	while (*str){
		printf("%02x ", *str);
		++str;
	}
	printf("\n");
}

int main(){

	struct S* ps = (struct S*)malloc(sizeof(struct S) + MAX_LEN * sizeof(char));
	if (ps == NULL){
		printf("%s\n", strerror(errno));
		return 0;
	}
	
	printf("请输入要进行转换的字符串：");
	scanf("%s", ps->text);

	//printf("%d\n", strlen(ps->text));

	//二进制转换
	printf("Bincode：");
	Bincode(ps->text);

	//十六进制转换
	printf("Hexcode：");
	Hexcode(ps->text);


	free(ps);
	ps = NULL;
	return 0;
}


/*#include <stdio.h>#include <string.h>
  int main() {
    char string[100];
    printf("请输入要更改的字符串:");
    scanf("%s", string);
 
    // 将字符串转换为二进制字符串
    int length = strlen(string);
    char bi[length * 8 + 1];
    int i,j;
    for (i = 0; i < length; i++) {
        int ascii_value = (int) string[i];
        for (j = 7; j >= 0; j--) {
            bi[i * 8 + 7 - j] = (ascii_value & (1 << j)) ? '1' : '0';
        }
    }
    bi[length * 8] = '\0';
 
    // 将字符串转换为十六进制字符串
    char hex_string[length * 2 + 1];
    for (i = 0; i < length; i++) {
        sprintf(hex_string + i * 2, "%02x", string[i]);
    }
    hex_string[length * 2] = '\0';
 
    printf("二进制字符串：%s\n", bi);
    printf("十六进制字符串：%s\n", hex_string);
	return 0;}*/