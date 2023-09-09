#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include<errno.h>

void Key_Table(char jm_1[],int shuffle){

	int i, j = 0;
	char temp;
	//生成密码表
	for (i = 0; i < 26; ++i){
		jm_1[i] = 'a' + i;
	}
	for (j = 0; j < 26; ++i, ++j){
		jm_1[i] = 'A' + j;
	}
	for (j = 0; j < 10; ++i, ++j){
		jm_1[i] = '0' + j;
	}
	//注意，这里改变的都是下标i，不是下标j，因为只有i是从0开始到62连续变化的

	//打乱密码表
	for (i = 0; i < shuffle; ++i){
		temp = jm_1[61];
		for (j = 61; j > 0; --j){
			jm_1[j] = jm_1[j - 1];
		}
		jm_1[0] = temp;
	}
	printf("密码表：%s\n", jm_1);
}

void encode(char buf[],char jm_1[]){
	int i = 0;

	while (buf[i]){
		if (buf[i] >= 'a' && buf[i] <= 'z'){
			buf[i] = jm_1[buf[i] - 'a'];
		}
		//明文a-z从密码表头部开始加密
		else if (buf[i] >= 'A' && buf[i] <= 'Z'){
			buf[i] = jm_1[buf[i] - 'A' + 26];
		}
		//明文A-Z跳过密码表前26个字符开始加密
		else if (buf[i] >= '0' && buf[i] <= '9'){
			buf[i] = jm_1[buf[i] - '0' + 52];
		}
		//明文0-9跳过密码表前52个字符开始加密
		++i;
	}
	printf("加密后的字符串：%s\n", buf);
}

void decode(char buf[], char jm_1[]){
	int i = 0;
	int j = 0;

	while (buf[i])
	{
		for (j = 0; j<62; ++j)
		{
			if (jm_1[j] == buf[i])
				break;
		}
		if (j<26)
			buf[i] = 'a' + j;
		else if (j<52)
			buf[i] = 'A' + j - 26;
		else
			buf[i] = '0' + j - 52;
		i++;
	}
	printf("解密后的字符串：%s\n", buf);
}

int main()
{
	int r, j = 0;
	char buf[30] = { 0 };
	char jm_1[80] = { 0 };
	//char jm_2[80] = { 0 };
	
	srand((unsigned int)time(NULL));
	r = rand() % 61; //生成一个0-60的随机数
	
	//生成密码表
	Key_Table(jm_1,r);


	//将密码表导入文件TEXT.txt中
	FILE* pfwrite = fopen("TEXT.txt", "w");
	if (pfwrite == NULL){
		printf("%s\n", strerror(errno));
		return 0;
	}
	fputs(jm_1, pfwrite);
	fclose(pfwrite);
	pfwrite = NULL;

	printf("请输入一个明文：");
	gets(buf);

	encode(buf, jm_1);
	
	decode(buf, jm_1);

	return 0;
}

//#include <stdio.h>#include <stdlib.h>#include <string.h>#include <time.h>
//#define ALPHABET "abcdefghijklmnopqrstuvwxyz0123456789"
//// 生成随机替换表void generate_substitution_table(char table[36][2]) {
//srand(time(NULL));
//char sh[36];
//strcpy(sh, ALPHABET);
//for (int i = 35; i > 0; i--) {
//	int j = rand() % (i + 1);
//	char temp = sh[i];
//	sh[i] = sh[j];
//	sh[j] = temp;
//}
//for (int i = 0; i < 36; i++) {
//	table[i][0] = ALPHABET[i];
//	table[i][1] = sh[i];
//}}
//// 将替换表保存到文件void save_substitution_table(char table[36][2], const char* filename) {
//FILE* f = fopen(filename, "w");
//for (int i = 0; i < 36; i++) {
//	fprintf(f, "%c\t%c\n", table[i][0], table[i][1]);
//}
//fclose(f); }
//// 从文件中加载替换表void load_substitution_table(char table[36][2], const char* filename) {
//FILE* f = fopen(filename, "r");
//for (int i = 0; i < 36; i++) {
//	fscanf(f, "%c\t%c\n", &table[i][0], &table[i][1]);
//}
//fclose(f); }
//// 使用替换表加密明文void encrypt(const char* pl, char* ci, char table[36][2]) {
//int len = strlen(pl);
//for (int i = 0; i < len; i++) {
//	char c = pl[i];
//	for (int j = 0; j < 36; j++) {
//		if (table[j][0] == c) {
//			c = table[j][1];
//			break;
//		}
//	}
//	ci[i] = c;
//}
//ci[len] = '\0'; }
//// 使用替换表解密密文void decrypt(const char* ci, char* pl, char table[36][2]) {
//int len = strlen(ci);
//for (int i = 0; i < len; i++) {
//	char c = ci[i];
//	for (int j = 0; j < 36; j++) {
//		if (table[j][1] == c) {
//			c = table[j][0];
//			break;
//		}
//	}
//	pl[i] = c;
//}
//pl[len] = '\0'; }
//int main() {
//	char pl[] = "abcdef";
//	char table[36][2];
//	generate_substitution_table(table);
//	save_substitution_table(table, "table.txt");
//	for (int i = 0; i < 36; i++) {
//		printf("%c\t%c\n", table[i][0], table[i][1]);
//	}
//
//	char ci[7];
//	encrypt(pl, ci, table);
//	printf("%s\n", ci);
//
//	load_substitution_table(table, "table.txt");
//	char decrypted[7];
//	decrypt(ci, decrypted, table);
//	printf("%s\n", decrypted);
//	return 0;
//}