#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//copy(iterator beg, iterator end, iterator dest);
//ԭ������ʼ������  ԭ��������������  Ŀ��������ʼ������
//������ָ����Χ��Ԫ�ؿ�������һ������
//��ֵ����Ԫ�أ��ҵ��ͷ���ָ��λ�õĵ��������Ҳ����ͷ��ؽ���λ�õ�����

void Print(int val){
	cout << val << " ";
}

void test1(){
	vector<int>v1;
	for (int i = 0; i < 10; ++i){
		v1.push_back(i);
	}

	vector<int>v2;
	//ע��ע��ע�⣡����������������������������������������������������������������������������������������������������
	//һ��Ҫ��v2���ٿռ䣬��Ȼд��bug������군�ˣ���������������������������������������������������������������������
	/*v2.resize(v1.size());*/
	v2 = v1;
	//�ȺŸ�ֵ��ȷ�ǿ��Խ�һ�������������ʹ�Сȫ��������һ�����������ǿ����Ͳ�һ����

	//copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), Print);
	cout << endl;
}

int main(){
	test1();

	return 0;
}