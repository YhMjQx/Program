#include<map>
#include<string>
#include<iostream>
using namespace std;

int main(){

	//���뵽map�������е�Ԫ����Ĭ�ϰ���key��С�򵽵�˳������ģ����Զ�key������Ҫ�󣬱������ص���"<"�����
	//���key�������ظ�����ô���أ���ô��Ҫ������ķ�ʽ�ˣ�
	//�������[]�ķ�ʽ������Ļ���key�ظ��ˣ���ô���value��Ӧ��ֵ�����������ֵ�����ַ�ʽ������ᱻ�ı��

	map<string, int> mapTest;
	//map<key�����ͣ�valueֵ���ͣ���������ͣ�> - ģ����
	//mapTest - ģ���������

	mapTest["aaa"] = 100;		//int& operator[](const string& index);
	//����һ��key����aaa��Ԫ�أ����ĳ�ʼֵ��int���͵Ŀ�ֵ��Ҳ���൱��0��Ȼ���100���Ƹ���

	mapTest.insert(map<string, int>::value_type("bbb", 200));
	//(map<string, int>::value_type - ����һ������
	//ͨ���������������Ĺ��캯���������� - �����ͽ�����������������һ������ ��һ��������key���ڶ�����������value
	//Ȼ�󽫹���õĶ������map��������

	mapTest.insert(pair<string, int>("ccc", 300));
	//pair<string, int> - �����һ������
	//pair<string, int>("ccc", 300) - ��������ʹ�������������һ������

	mapTest.insert(make_pair("ddd", 400));
	//make_pair -  ��һ��������������һ��pair�����͵Ķ��󣬵������ϻ��ǹ�����һ��pair�����͵Ķ���

	//ɾ��
	mapTest.erase("bbb");
	
	map<string, int>::const_iterator it;//map<string, int>�����ĵ�����,const_iterator it,�����it���Ըı䣬���ܸı����it->ָ�������

	//���õ�������ɾ��map�������е�Ԫ��
	it = mapTest.find("ccc");
	if (it != mapTest.end()){
		mapTest.erase(it);
	}
		//�õ�����������map����
	for (it = mapTest.begin(); it != mapTest.end(); ++it){
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}