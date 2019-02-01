#include "Linklist.h"
void HeadInsert(LinkList *head, LinkList *tail, int key) {
	LNode *New = (LNode*)malloc(sizeof(LNode));
	New->key = key;
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
void print(LinkList head) {
	while (head) {
		printf("%d  ", head->key);
		head = head->next;
	}
	printf("\n");
}
void Delete_key(LinkList *head, int key) {//删除节点
	LinkList p, h = *head;
	if ((*head)->key == key) {//若为头结点
		h = *head;
		*head = (*head)->next;
		free(h);
	}
	else {
		while (h->next->key != key) {
			h = h->next;
		}
		p = h->next;
		h->next = p->next;
		free(p);
	}
}
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