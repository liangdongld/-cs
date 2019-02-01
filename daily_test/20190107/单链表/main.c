#include "Linklist.h"
void HeadInsert(LinkList *head, LinkList *tail, int key ) {
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
void Delete_key(LinkList *head,int key) {//删除节点
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
int main() {
	LinkList head=NULL, tail=NULL;
	int i,key;
	while(1){
		scanf("%d", &key);
		if (key == -1)break;
		TailInsert(&head, &tail, key);
	}
	print(head);
	scanf("%d", &key);
	Delete_key(&head, key);
	print(head);
}