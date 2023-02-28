//�Ƴ��������е�Ԫ��
#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
	int data;
	struct ListNode* next;
};
//�Ƴ�����Ϊval������
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* cur = head;
	struct ListNode* prev = NULL;
	while (cur)
	{
		if (cur->data == val)
		{
			//��һҪɾ�������������ͷ����ô��
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			//��ʱ����prev����NULL�����ұ���Խ�prevʹ��->
			else
			{
				prev->next = cur->next;//����val����ָ��ָ��val����һ������
				free(cur);
				cur = prev->next;//��cur������
			}
		}
		//cur->data ��= val��ʱ��cur������
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}
//���㵥�����ͷ�ڵ�head�����㷴ת���������ط�ת�������
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* prev, *cur, *next;
	prev = NULL;
	cur = head;
	next = cur->next;
	while (cur)
	{
		cur->next = prev;
		prev = cur;
		cur = next;
		if (next->next!=NULL)
			next = next->next;
	}
	return prev;
}
int main()
{
	//������ٵ�������
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->data = 7;
	n2->data = 7;
	n3->data = 7;
	n4->data = 7;
	n5->data = 5;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;


	struct ListNode* head = removeElements(n1, 7);

}
