#include <iostream>
#include <string>
using namespace std;

string encrypt(string plaintext, string key) {
	string ciphertext = "";
	int plaintext_len = plaintext.length();
	int key_len = key.length();
	int key_index = 0;

	for (int i = 0; i < plaintext_len; i++) {
		// 根据key的当前字符进行移位加密
		char encrypted_char = plaintext[i] + key[key_index] - 'a';

		// 判断是否超出字母范围，超出则回到a
		if (encrypted_char > 'z') {
			encrypted_char = encrypted_char - 26;
		}

		// 更新key的索引
		key_index = (key_index + 1) % key_len;

		// 将加密后的字符添加到密文中
		ciphertext += encrypted_char;
	}

	return ciphertext;
}

string decrypt(string ciphertext, string key) {
	string plaintext = "";
	int ciphertext_len = ciphertext.length();
	int key_len = key.length();
	int key_index = 0;

	for (int i = 0; i < ciphertext_len; i++) {
		// 根据key的当前字符进行移位解密
		char decrypted_char = ciphertext[i] - key[key_index] + 'a';

		// 判断是否低于字母范围，低于则回到z
		if (decrypted_char < 'a') {
			decrypted_char = decrypted_char + 26;
		}

		// 更新key的索引
		key_index = (key_index + 1) % key_len;

		// 将解密后的字符添加到明文中
		plaintext += decrypted_char;
	}

	return plaintext;
}

int main() {
	string plaintext, key;

	cout << "请输入明文字符串：";
	cin >> plaintext;

	cout << "请输入密钥：";
	cin >> key;

	// 加密明文
	string ciphertext = encrypt(plaintext, key);
	cout << "加密后的密文：" << ciphertext << endl;

	// 解密密文
	string decrypted_text = decrypt(ciphertext, key);
	cout << "解密后的明文：" << decrypted_text << endl;

	return 0;
}