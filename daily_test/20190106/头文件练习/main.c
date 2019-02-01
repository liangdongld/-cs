#include <stdio.h>
#include <stdlib.h>
//定义单链表结构体
typedef struct a {
	int val;	
	struct a *next;
}LNode, *Linklist; 
typedef LNode(*Lfunc) (Linklist, int); //定义函数指针
void AddNode(Linklist list,int key) {
	if (key == -1)return;
	Linklist i = (Linklist)malloc(sizeof(LNode));
	i->val = key;
	i->next = list->next;
	list->next = i;
}
void DeletNode(Linklist list, int key) {
	while (list->next->val != key)list = list->next;
	Linklist d = list->next;
	list->next = d->next;
	free(d);
}
void PrintList(Linklist list) {
	while (list) {
		printf("%d   ", list->val);
		list = list->next;
	}
	printf("\n");
}
int main() {
	Linklist a;
	int i = 0;
	Lfunc fun;
	a = (Linklist)malloc(sizeof(LNode));
	a->val = 0;
	a->next = NULL;
	while (i != -1) {
		scanf("%d", &i);
		AddNode(a, i);
	}
	PrintList(a);
	printf("1.头插入节点\n2.删除节点\n");
	scanf("%d", &i);
	if (i == 1)fun = AddNode;
	else if(i == 2)fun = DeletNode;
	printf("请输入key值：");
	scanf("%d", &i);
	fun(a, i);
	PrintList(a);
	system("pause");
}