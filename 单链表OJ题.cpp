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
//˼·һ��
	if (head == NULL)
	{
		return NULL;
	}
	struct ListNode* prev, *cur, *next;
	prev = NULL;
	cur = head;
	next = head->next;
	while (cur)
	{
		//��ת
		cur->next = prev;
		//����������
		prev = cur;
		cur = next;
		if (next != NULL)
			next = next->next;
	}
	return prev;
//˼·����ȡԭ�����еĽڵ㣬ͷ�嵽newhead��������
	//ListNode* cur = head;
	//ListNode* newhead = NULL;
	//while (cur)//�������ΪNULL�����������ѭ��
	//{
	//	ListNode* next = cur->next;
	//	//ͷ��
	//	cur->next = newhead;
	//	newhead = cur;
	//	//����
	//	cur = next;
	//}
	//return newhead;
}
//������м�ڵ� - ����ָ�뷨
struct ListNode* middleNode(struct ListNode* head)
{
	struct ListNode* fast, *slow;
	slow = fast = head;
	//ÿһ����slow��һ����fast������
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
//�����е�����K���ڵ�
struct ListNode* FindKthToTail1(struct ListNode* head, int k)
{
	struct ListNode* slow, *fast; 
	slow = fast = head;
	//��fast����k��
	//for (int i = 0; i < k; i++)
	//{
	//    if (fast == NULL)
	//    {
	//	      return NULL;
	//    }
	//	fast = fast->next;
	//}
	while (k--)//����k��
	{
		//Ϊ�˷�ֹk>����ĳ���,��K��������ĳ��ȵ�ʱ�򣬼����������������Ҳ�Ҳ���k�Ľڵ�
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
	}
	//Ȼ����fast��slowһ����
	while (fast != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
struct ListNode* FindKthToTail2(struct ListNode* head, int k)
{
	struct ListNode* slow, *fast;
	slow = fast = head;
	//��fast����k-1��
	//for (int i = 0; i < k-1; i++)
	//{
	//    if (fast == NULL)
	//    {
	//	      return NULL;
	//    }
	//	fast = fast->next;
	//}
	while (--k)//��fast����k-1��
	{
		if (fast->next == NULL)
		{
			return NULL;
		}
		fast = fast->next; 
	}
	//Ȼ����fast��slowһ����
	while (fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode* head = NULL, *tail = NULL;
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	//�������һ��if else����Ըտ�ʼhead��tail����NULL��ʱ������������֮����whileѭ����Ϳ��Բ������ж�head�Ƿ�Ϊ��
	//if (l1->data < l2->data)
	//{
	//	head = tail = l1;
	//	l1 = l1->next;
	//}
	//else
	//{
	//	head = tail = l2;
	//	l2 = l2->next;
	//}
	//��Ȼ��������һ�δ�����ȫ�������½�һ���ڱ�λ��������������嶼��һ����
	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
	//����֮���˵��head��tail���ǿ�ָ���ˣ�����һ����ʵ���ڵ��ڱ��ڵ�
	//�ڱ��ڵ�Ĵ��ڣ����������ڲ��ı�ͷָ�������´Ӷ����в���
	//���ǣ������ڱ��ڵ���malloc�����ģ�������������Ҫ����free���������ұ�����һ���µ�ͷָ�������ղ�����
	while (l1 && l2)
	{
		if (l1->data < l2->data)
		{
			tail->next = l1;
			tail = tail->next;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			tail = tail->next;
			l2 = l2->next;
		}
	}
	//���գ���ʣ�²�������û���ϣ���ô�������ҾͿ���ֱ��һ����ȫ������
	if (l1 != NULL)
	{
		tail->next = l1;
	}
	if (l2 != NULL)
	{
		tail->next = l2;
	}
	/*return head;���д����Ƕ�Ӧ��if else��������һ�ε������*/
	struct ListNode* newhead = head->next;
	free(head);
	head = NULL;
	//�����д����Ƕ�Ӧ���ڱ��ڵ����ʱ�����ص�
	return newhead;
}
//����һ������ͷָ��pHead,��һ��ֵx����дһ�δ��뽫����С��x�Ľڵ���������ڵ�֮ǰ���Ҳ��ı�ԭ������˳�򣬷����µ�����
struct ListNode* partition(struct ListNode* pHead, int x)
{
	//�������ڱ�λ�ֱ����С��x�Ľڵ�ʹ���x�Ľڵ�������µ�����
	struct ListNode* lessHead, *lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	lessTail->next = NULL;
	struct ListNode* greaterHead, *greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
	greaterTail->next = NULL;
	struct ListNode* cur = pHead;
	while (cur)
	{
		if (cur->data < x)
		{
			lessTail->next = cur;//��lessTail������cur
			lessTail = lessTail->next;//Ȼ��lessTail�����µ�λ��
		}
		else
		{
			greaterTail->next = cur;//��greaterTail������cur
			greaterTail = greaterTail->next;//Ȼ��greaterTail�����µ�λ��
		}
		cur = cur->next;//�����cur����һ���ڵ��ߣ���������ų���ִ�У�����Ϊ������if����else����Ҷ���Ҫִ��������
		//cur����ԭ�����������߶�����lessTail��greaterTail����������Ӯ���ڱ�λ�쵼���������ƶ���
	}
	//�������һ������ʱ�ҵĵ����ڶ��������ܴ������һ������Ȼ��greaterHead��β���ͻ�����lessHead�����һ����
	//���ǣ���������������ʱ���Ϳ��ܷ����ջ����Ӷ�������ѭ������������Ҫ��greaterHead��β���ÿգ�Ȼ������������������
	greaterHead->next = NULL;
	lessTail->next = greaterHead->next;
	//Ȼ��������Ҫ�����µ�����������µ������ֲ��ܰ����Լ��趨���ڱ�λ����������Ҫ���µ�ָ�����е�����ֵ���������
	//���ң��ҵ��ڱ�λ��malloc�����ģ����ն���Ҫfree�ģ�����ֻ�����µ�ָ��������
	struct ListNode* newhead = lessHead->next;
	free(lessHead);
	free(greaterHead);
	//lessTail��greaterHead�ǲ����ͷŵģ���ΪlessTail�������������ã�����滹������Ч���ݣ�һ���ͷ������������ݾ�û��
	return newhead;
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
	//struct ListNode* head1 = removeElements(n1, 7);
	struct ListNode* head2 = reverseList(n1);
	return 0;
}
