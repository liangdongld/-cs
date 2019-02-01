#include "Stack.h"
void push(pSTACK s, int key) {//指针均是按值传递 s的内容应为其所指向空间的地址
	pNode pNew = (pNode)calloc(1, sizeof(Node));
	pNew->val = key;
	if (0==s->m_size) {
		s->m_head = pNew;//s->m_head   等同于 （*s).m_head
	}
	else {//头插法
		pNew->next = s->m_head;
		s->m_head = pNew;
	}
	s->m_size++;
}
void pop(pSTACK s) {//栈顶元素弹出
	if (0 == s->m_size) {
		printf("The stack is empty!\n");
		return;
	}
	else {
		pNode pNew= s->m_head;
		s->m_head = pNew->next;
		free(pNew);
		s->m_size--;
		pNew = NULL;
	}
}
int getTop(pSTACK s) {
	if (0 == s->m_size) {
		printf("The stack is empty!\n");
		return;
	}
	else return s->m_head->val;
}
int isEmpty(pSTACK s) {//为空返回1，否则返回0
	if (0 == s->m_size)return 1;
	else return 0;
}
int size(pSTACK s) {
	return s->m_size;
}