#include "Linklist.h"
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
//合并有序链表
LinkList combine(LinkList l1, LinkList l2) {
	LinkList l3;
	LinkList p = l1, q = l2, r;
	if (l1->key > l2->key) {
		l3 = l2;
		r = l2;
		q = q->next;
	}
	else {
		l3 = l1;
		r = l1;
		p = p->next;
	}
	while (q&&p) {
		if (p->key > q->key) {
			r->next = q;
			r = r->next;
			q=q->next;
		}
		else {
			r->next = p;
			r = r->next;
			p = p->next;
		}
	}
	r->next = p == NULL ? q : p;
	return l3;
}
