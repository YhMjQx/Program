#include<iostream>
using namespace std;
//����������
//1.���ú���ģ���װһ������ĺ��������ԶԲ�ͬ�������������������
//2.�������Ϊ��С���������㷨Ϊѡ������
//3.�ֱ�����char�����int������в���
//��������ģ��
template<typename T>
void MySwap(T& a,T& b)
{
	T temp = a;
	a = b;
	b = temp;

}

//������ģ��
template<typename T>
void MySort(T arr[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		int max = i;//���϶�i�������ֵ���±꣬ͨ������Ƚ��ڸı����
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[max] < arr[j])//ע��ע�⣬�����ǺͲ��ҵ��� j ���бȽϣ����Ǻ�ԭ���� i �Ƚϣ�����max = i������±�дi����ʲô����
			{
				//�϶������ֵ �� ����������ֵҪС��˵������������ֵ�������ֵ����ô�ͽ��µ����ֵ���н�����ǰ��
				max = j;//�������ֵ�±�
			}
		}
		
		if (max != i)
		{
			//��ʱ˵���������forѭ�������У�max�Ĵ�С�Ѿ����ı��ˣ���ô��Ҫ��������Ӧ������Ҳ�Ĺ���
			MySwap(arr[max], arr[i]);
		}
	}
}

//�����ӡ����ģ��
template<typename T>
void MyPrint(T arr[],int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test1(){
	char chararr[] = "bdceaf";
	int len = sizeof(chararr) / sizeof(char);
	MySort(chararr, len);

	MyPrint(chararr, len);

}

void test2(){
	int arr[] = { 1, 4, 3, 5, 2, 6, 8, 7, 9 };
	MySort(arr, sizeof(arr) / sizeof(int));
	MyPrint(arr, sizeof(arr) / sizeof(int));
}

int main(){

	test1();
	test2();
	return 0;
}