#include "Reverse.h"
//有序插入链表 
void SortInsert(LinkList *head, LinkList *tail, int key) {
	LinkList pcur, ppre, pnew;
	pnew = (LinkList)calloc(1, sizeof(LNode));
	pnew->key = key;
	ppre = *head;
	pcur = *head;
	if (NULL == *head) {
		*head = pnew;
		*tail = pnew;
	}
	else if (key < pcur->key) {
		pnew->next = *head;
		*head = pnew;
	}
	else {
		while (pcur) {
			if (pcur->key>key) {
				ppre->next = pnew;
				pnew->next = pcur;
				return;
			}
			ppre = pcur;
			pcur = pcur->next;
		}
		(*tail)->next = pnew;
		*tail = pnew;
	}
}
//打印链表
void print(LinkList head) {
	while (head) {
		printf("%d  ", head->key);
		head = head->next;
	}
	printf("\n");
}
//逆置链表
void reverse(LinkList *head) {
	LinkList pre = NULL, cur = *head;
	while ((*head)->next) {
		cur = *head;
		*head = (*head)->next;
		cur->next = pre;
		pre = cur;
	}
	(*head)->next = cur;
}
//找到倒数第四个节点
LNode findNode(LinkList head) {
	LinkList p1, p2;
	p1 = head;
	p2 = head;
	p1 = p1->next->next->next->next;
	while (p1) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return *p2;
}
//找到中间节点
LNode findMidNode(LinkList head) {
	LinkList p1, p2;
	p1 = head;
	p2 = head;
	while (p1) {
		p1 = p1->next;
		if (!p1)break;
		else p1 = p1->next;
		p2 = p2->next;
	}
	return *p2;
}
//判断是否有环
int iscirculation(LinkList head) {
	LinkList p1=head, p2=head;
	while (p1) {
		p1 = p1->next;
		if (!p1)break;
		else p1 = p1->next;
		p2 = p2->next;
		if (p1 == p2)return 1;
	}
	return 0;
}
//判断两个链表是否相交，并算出交点
int isIntersect(LinkList l1, LinkList l2) {
	int count1 = 0, count2 = 0;
	LinkList head1 = l1;
	LinkList head2 = l2;
	LinkList p1, p2;
	while (head1)
	{
		count1++;
		head1 = head1->next;
	}
	while (head2)
	{
		count2++;
		head2 = head2->next;
	}
	if (count1 > count2) {
		p1 = l1;
		p2 = l2;
	}
	else {
		p1 = l2;
		p2 = l1;
	}
	int i = abs(count1- count2);
	for (; i > 0; i--) {
		p1 = p1->next;
	}
	for (i = 0; i < count2; i++) {
		p1 = p1->next;
		p2 = p2->next;
		if (p1 == p2)return 1;
	}
	return  0;
}
//将一个链表拆分
void CutLinklist(LinkList head) {
	LinkList head1 = head, head2 = head->next;
	LinkList p1 = head1, p2 = head2;
	int flag1 = 1, flag2 = 1;
	while (1) {
		if (p2->next != NULL&&p1->next != NULL) {
			p1->next = p2->next;
			p1 = p1->next;
		}
		else { 
			p1->next = NULL;
			flag1 = 0; 
		}
		if (p2->next!=NULL&&p1->next!=NULL) {
			p2->next = p1->next;
			p2 = p2->next;
		}
		else {
			p2->next = NULL;
			flag2 = 0;
		}
		if (flag1==0&&flag2==0)break;
	}
	printf("Linklist1 :");
	print(head1);
	printf("Linklist2 :");
	print(head2);
}
//大整数
void addBigNumber(LinkList head1,LinkList head2) {
	int flag = 0;
	LinkList ppre, l3 = head1;
	while (head1&&head2) {
		head1->key = head1->key + head2->key+flag;
		if (head1->key > 10) {
			head1->key -= 10;
			flag = 1;
		}
		else flag = 0;
		ppre = head1;
		head1 = head1->next;
		head2 = head2->next;
	}
	if (head2)ppre->next = head2;
	print(l3);
}
