#include "String.h"
//ǳ�������൱�ڸ�ֵ���㣬��������� ����1.str_ = ����2.str_;
//��ô����ͻᵼ�������������������������ʱ�򣬻��str_���ڵĿռ������ͷ����Σ���ͳ�������
String::String(char* str)
{
	 str_ = AllocAndCpy(str);
}

String::~String()
{
	//�����ڶ��Ͽ����˿ռ䣬���������������в��õ�delete
	delete[] str_;
}

char* String::AllocAndCpy(const char* str){
	int len = strlen(str) + 1;
	char* tmp = new char[len];
	memset(tmp, 0, len);
	strcpy(tmp, str);
	return tmp;
}

void String::Display() const{
	cout << str_ << endl;
}

String::String(const String& other){
		//������Ͳ����ں�������ʱ���г�ʼ������Ϊ����ں����Ͻ��г�ʼ���������Ҳ���ڵ�����ǳ����
		//String::String(const String& other) :str_(other.str_); - Error �������Ҳ���ڵ�����ǳ����
		//���Ծ�ʹ�����
	str_ = AllocAndCpy(other.str_);
}


String& String::Assign(const char* str){
	delete[] str_;
	str_ = AllocAndCpy(str);
	return *this;
}


String& String:: operator=(const String& other)//�Լ��ĵȺ������
{
	if (this == &other)
		return *this;

		//��Ȼ��ʹ�á�=���������˵��=��ߵĶ����Ѿ������ˣ�������֮����ܸ�ֵ������������Ҫ��ֵ�ĵط��Ѿ���ռ����
		//����Ҫ�Ȱ�ԭ���ĵȺ���ߵĿռ��ͷ��ˣ��ٵ����Լ���������캯��
	return Assign(other.str_);
}


String& String::operator=(const char* str){
		//������������Ƕ��������ֵ�ˣ�����ֱ�ӽ�һ���ַ�����ֵ���Ѵ����Ķ���
		//���ԾͲ���Ҫ�жϣ�thisָ��ָ����Ƿ������ʵ��һ����
		//������һ�㻹��һ���ģ����ǵ��ȰѵȺ�����Ѿ��洢�����ݵĿռ��е������ͷŵ�
	return Assign(str);
}

bool String::operator!() const{
	return (strlen(str_) != 0);
}

//
char& String::operator[](unsigned int index){
		//return str_[index];
		//һ������£�������������ĺ�������ྶͥ�����ǲ�����Ҫʵ�������汾�ĺ������ᵼ�´������࣬��ô���Ǹ���δ�����
		//���ǿ�����non const�汾������const�汾,�Ϳ��Ա������ܶ����������ɵ�����
	return const_cast<char&>(static_cast<const String&>(*this)[index]);
		//*this - ָ������������ָ�룬����Ҫ�������ת����const���͵��࣬�Ա����const operator[]����
		//static_ cast<const String&>(*this) - ��*this�����ת����const ���͵���
		//const_cast<char&>(static_cast<const String&>(*this)) - ��const���͵���ķ���ֵȥ�������ԣ���Ϊ�ú��������Ƿ��ص�non const
}

const char& String::operator[](unsigned int index) const{
	return str_[index];
}
//

String operator+(const String& s1, const String& s2){
	//int len = strlen(s1.str_) + strlen(s2.str_) + 1;
	//char* newstr = new char[len];
	//memset(newstr, 0, len);
	//strcpy(newstr, s1.str_);
	//strcat(newstr, s2.str_);
	//	//�����newstr���ں����ڲ���������ʱ���󣬶���newstr�Ŀռ����ڶ��ϴ��������ģ�����Ҫ�ͷ�
	//	//����newstr��ջ�ǻᱻ���ٵģ���ô�͸����޷���ȷ���أ������Ҿͱ��뽫�丳ֵ����һ���µ��࣬Ȼ��������
	//	//�����ֱ�ӷ��ر����Ƶ������
	//String tmp(newstr);//�����ǵ��ÿ������캯������newstr������tmp�����Ծ����ҽ�newstr�ͷ��ˣ�����tmp����������ɴ�������
	//delete[] newstr;
	//return tmp;
	String str = s1;
	str += s2;
	return str;
}


String& String::operator+=(const String& other){
	int len = strlen(str_) + strlen(other.str_) + 1;
	char* newstr = new char[len];
	memset(newstr, 0, len);
	strcpy(newstr, str_);
	strcat(newstr, other.str_);

	delete[] str_;
	str_ = newstr;
	//����ǧ�򲻸��ͷ�����newstr�����ͷ�newstr��ԭ������Ϊ�ҽ�newstr�����ݶ�������str_����˼��newstr��str_������ָ�����
	//������ָ�붼ָ��ͬһ��ռ䣬�ڳ��������ʱ��ϵͳ�����������������str_�����ͷ����٣�������ں��������������
	//��ô��������ͻ��str_��Ƭ�ռ��������Σ���ͻ�����⣬���㲻���߷��濼�ǣ���ô���ǻ�������
	//str_��newstr����ָ��ָ�����ͬһƬ�ռ䣬���ͷ�newstrҲ���൱���ͷ���str_�����һ���ʲô���Բ��ԣ�
	return *this;//��������Ҳ�ͷ�������Ϊ������ƥ��
}


ostream& operator<<(ostream& os, const String& str){
	os << str.str_;
	return os;
}


istream& operator>>(istream& is, String str){// >>(��ȡ��)
	char tmp[1024];
	cin >> tmp;//cin - ���룬�൱��C�����е�scanf
	str = tmp;//tmp��ջ���Զ����ٵģ����ǲ����ù�
	return is;
}
