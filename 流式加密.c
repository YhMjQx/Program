#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 50

//struct S{
//	int k;
//	char arr[];
//};

//置乱密钥
void shufflekey(int* key, int length){
	for (int i = length - 1; i > 0; --i){
		int j = rand() % (i + 1);
		int temp = key[i];
		key[i] = key[j];
		key[j] = temp;
	}
}


//输出二进制明文
void Bin_plain(char* str){
	while (*str){
		for (int i = 7; i >= 0; --i){
			printf("%c", (*str & (1 << i)) ? '1' : '0');
		}
		printf(" ");
		++str;
	}
	printf("\n");
}


//输出二进制密文
void Bin_cipher(int* key,int length){
	for (int i = 0; i < length; ++i){
		for (int j = 7; j>=0; --j){
			printf("%c", (key[i] & (1 << j)) ? '1' : '0');
		}
		printf(" ");
	}
	printf("\n");
}

int main(){

	char plaintext[SIZE] = { 0 };

	char* ciphertext =  0 ;
	//char Bin_ciphertext[SIZE] = { 0 };

	int length = 0;

	srand((unsigned int)time(NULL));

	//struct S* ps = (struct S*)malloc(sizeof(struct S) + SIZE * sizeof(char));
	//if (ps == NULL){
	//	printf("%s", strerror(errno));
	//	return 0;
	//}

	printf("输入小写字母明文：");
	scanf("%s", plaintext);
	printf("明文的二进制：");
	Bin_plain(plaintext);

	length = strlen(plaintext);
	//printf("%d\n", length);

	//将密钥保存在文件中
	FILE* Save_Key = fopen("key.txt", "w");
	if (Save_Key == NULL){
		printf("%s", strerror(errno));
		return 0;
	}
	//产生一个密文并置乱
	int* key = (int*)malloc(length * sizeof(int));
	if (key == NULL){
		printf("%s", strerror(errno));
		return 0;
	}

	for (int i = 0; i < length; ++i){
		key[i] = i+1;
	}

	shufflekey(key, length);
	
	for (int i = 0; i < length; ++i){
		fprintf(Save_Key, "%d", key[i]);
	}
	
	printf("密钥的二进制：");
	Bin_cipher(key, length);
	//for (int i = 0; i < length; ++i){
	//	printf("%d\n", key[i]);
	//}

	//对明文和密钥进行异或得到密文并随即保存密文
	FILE* Save_cipher = fopen("cipher.txt", "w");
	if (Save_cipher == NULL){
		printf("%s", strerror(errno));
		return 0;
	}

	printf("密文的二进制：");
	for (int i = 0; i < length; ++i){
		for (int j = 7; j>=0; --j){
			int cipher = plaintext[i] ^ key[i];
			printf("%c", (cipher & (1 << j)) ? '1' : '0');
			fprintf(Save_cipher, "%c", (cipher & (1 << j)) ? '1' : '0');
		}
		fprintf(Save_cipher, "%c",' ');
		printf(" ");
	}
	printf("\n");

	free(key);
	key = NULL;
	return 0;
}


/*#include <stdio.h>#include <stdlib.h>#include <string.h>#include <time.h>
 void string_to_binary(const char *string, char *binary) {
    // 将字符串转换为二进制字符串
    int i,j;
    for ( i = 0; string[i] != '\0'; i++) {
        for ( j = 7; j >= 0; j--) {
            binary[(i * 8) + (7 - j)] = ((string[i] >> j) & 1) ? '1' : '0';
        }
    }}
 void binary_to_string(const char *binary, char *string) {
    // 将二进制字符串转换为字符串
    int i;
    for ( i = 0; binary[i] != '\0'; i += 8) {
        char byte[9] = {'\0'};
        strncpy(byte, binary + i, 8);
        string[i / 8] = strtol(byte, NULL, 2);
    }}
 void encrypt(const char *pl, const char *key_filename, const char *ciphertext_filename) {
    // 对明文进行加密
    char pl_binary[10000] = {'\0'};
    char key_binary[10000] = {'\0'};
    char ciphertext_binary[10000] = {'\0'};
    string_to_binary(pl, pl_binary);
 
    // 生成随机密钥
    srand(time(NULL));
    int i;
	for ( i = 0; i < strlen(pl_binary); i++) {
        key_binary[i] = (rand() % 2) ? '1' : '0';
    }
 
    // 对明文进行按位异或加密
    for (i = 0; i < strlen(pl_binary); i++) {
        ciphertext_binary[i] = ((pl_binary[i] == key_binary[i]) ? '0' : '1');
    }
 
    // 将密钥和密文保存到文件
    FILE *key_file = fopen(key_filename, "w");
    fprintf(key_file, "%s", key_binary);
    fclose(key_file);
    FILE *ciphertext_file = fopen(ciphertext_filename, "w");
    fprintf(ciphertext_file, "%s", ciphertext_binary);
    fclose(ciphertext_file);}
 void decrypt(const char *key_filename, const char *ciphertext_filename, char *pl) {
    // 解密密文
    char key_binary[10000] = {'\0'};
    char ciphertext_binary[10000] = {'\0'};
    char pl_binary[10000] = {'\0'};
    FILE *key_file = fopen(key_filename, "r");
    fscanf(key_file, "%s", key_binary);
    fclose(key_file);
    FILE *ciphertext_file = fopen(ciphertext_filename, "r");
    fscanf(ciphertext_file, "%s", ciphertext_binary);
    fclose(ciphertext_file);
 
    // 对密文进行按位异或解密
    int i;
    for ( i = 0; i < strlen(ciphertext_binary); i++) {
        pl_binary[i] = ((ciphertext_binary[i] == key_binary[i]) ? '0' : '1');
    }
 
    binary_to_string(pl_binary, pl);}
 int main() {
	char s[100001];
	printf("请输入要加密的字符串:\n");
	scanf("%s",&s);
    encrypt(s, "key.txt", "ciphertext.txt");
 
    char pl[10000] = {'\0'};
    decrypt("key.txt", "ciphertext.txt", pl);
    printf("解密后\n%s\n", pl);
 
 return 0;}*/