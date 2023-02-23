//���Ա�������ͬ����Ԫ�ص���������
//���Ա�֮˳��� - ����������
//����ṹ������Ļ����ϣ�Ҫ�������Ǵ�ͷ���������洢�ģ�������Ծ����������ɾ���
#include"SeqList.h"
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDatatype* tmp = (SLDatatype*)realloc(ps->a, newcapacity*sizeof(SLDatatype));
		if (tmp == NULL)
		{
			printf("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPushBank(SL* ps, SLDatatype x)
{
	//���ռ䲻�����û�пռ��ʱ��,���Ǿ�����
	SeqListCheckCapacity(ps);
	//���ռ��㹻��ʱ��ֱ�Ӳ������ݾͺ�
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPopBank(SL* ps)
{
	//βɾʱ��Ҫע�⣬��Ҫɾ��Խ����
	//����βɾ��ʽ
	//if (ps->size > 0)
	//{
	//	//ps->a[ps->size - 1] = 0;
	//	ps->size--;
	//}
	//������βɾ��ʽ
	assert(ps->size > 0);
	ps->size--;
}

void SeqListPushFront(SL* ps, SLDatatype x)
{
	//�ȿ������������������Ļ�������
	SeqListCheckCapacity(ps);

	//Ų������
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps)
{
	int begin = 1;
	assert(ps->size > 0);
	//Ų������
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	//����Ų��һ�Σ�begin�Ӽ�һ�Σ�ֱ��begin=size��ʱ��Ϳ��Բ�����Ų��������
	//��Ϊ��Ų�����ݺ�begin++������Ų��ʵ�����Ѿ���ɵ�ʱ�򣬴�ʱbegin��sizeСһ
	//�ڽ���һ��begin++���ͻ���begin=size����ʱ�����Ѿ�Ų����ɣ�����Ҫ�ٶ���
	//���Դ�ʱѭ�����Ѿ�����ֹͣ��,�����Ϊʲôbegin < ps->size�������ü�=��
	ps->size--;
}
