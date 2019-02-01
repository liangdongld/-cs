#include "addBigNum.h"
//数值头插法
void TailInsert(LinkList *head, LinkList *tail, int key) {
	LNode *New = (LNode*)malloc(sizeof(LNode));
	New->key = key;
	New->next = NULL;
	if (*head == NULL) {
		*head = New;
		*tail = New;
	}
	else {
		(*tail)->next = New;
		*tail = New;
	}
}
//字符头插法
void CHeadInsert(CinkList *head, CinkList *tail, char key) {
	CNode *New = (CNode*)malloc(sizeof(CNode));
	New->ch = key;
	New->next = NULL;
	if (*head == NULL) {
		*head = New;
		*tail = New;
	}
	else {
		New->next = *head;
		*head = New;
	}
}
//逆置
void reverse(LinkList *head) {//         1 -> 0
	LinkList pre = NULL, cur = *head;
	while ((*head)->next) {
		cur = *head;
		*head = (*head)->next;
		cur->next = pre;
		pre = cur;
	}
	(*head)->next = cur;
}
//大整数
void addBigNumber(LinkList head1, LinkList head2) {
	int flag = 0;
	LinkList ppre, l3 = head1;
	while (head1&&head2) {
		head1->key = head1->key + head2->key + flag;
		if (head1->key >= 10) {
			head1->key -= 10;
			flag = 1;
			if (head1->next == NULL&&head2->next == NULL) {
				LinkList node = (LinkList)calloc(1, sizeof(LNode));
				node->key = 1;
				head1->next = node;
			}
		}
		else flag = 0;
		ppre = head1;
		head1 = head1->next;
		head2 = head2->next;
	}
	if (head2)ppre->next = head2;
	reverse(&l3);
	print(l3);
}
//打印
void print(LinkList head) {
	printf("Answer:\n");
	while (head) {
		printf("%d", head->key);
		head = head->next;
	}
	printf("\n\n");
}
//释放单链表空间
void freeLinklist(LinkList head) {
	LinkList ppre;
	while (head) {
		ppre = head;
		head = head->next;
		free(ppre);
	}
}