#include <iostream>
#include <string>
using namespace std;

string encrypt(string plaintext, string key) {
	string ciphertext = "";
	int plaintext_len = plaintext.length();
	int key_len = key.length();
	int key_index = 0;

	for (int i = 0; i < plaintext_len; i++) {
		// ����key�ĵ�ǰ�ַ�������λ����
		char encrypted_char = plaintext[i] + key[key_index] - 'a';

		// �ж��Ƿ񳬳���ĸ��Χ��������ص�a
		if (encrypted_char > 'z') {
			encrypted_char = encrypted_char - 26;
		}

		// ����key������
		key_index = (key_index + 1) % key_len;

		// �����ܺ���ַ���ӵ�������
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
		// ����key�ĵ�ǰ�ַ�������λ����
		char decrypted_char = ciphertext[i] - key[key_index] + 'a';

		// �ж��Ƿ������ĸ��Χ��������ص�z
		if (decrypted_char < 'a') {
			decrypted_char = decrypted_char + 26;
		}

		// ����key������
		key_index = (key_index + 1) % key_len;

		// �����ܺ���ַ���ӵ�������
		plaintext += decrypted_char;
	}

	return plaintext;
}

int main() {
	string plaintext, key;

	cout << "�����������ַ�����";
	cin >> plaintext;

	cout << "��������Կ��";
	cin >> key;

	// ��������
	string ciphertext = encrypt(plaintext, key);
	cout << "���ܺ�����ģ�" << ciphertext << endl;

	// ��������
	string decrypted_text = decrypt(ciphertext, key);
	cout << "���ܺ�����ģ�" << decrypted_text << endl;

	return 0;
}