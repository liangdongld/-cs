#include "Stack.h"
void push(pSTACK s, int key) {//ָ����ǰ�ֵ���� s������ӦΪ����ָ��ռ�ĵ�ַ
	pNode pNew = (pNode)calloc(1, sizeof(Node));
	pNew->val = key;
	if (0==s->m_size) {
		s->m_head = pNew;//s->m_head   ��ͬ�� ��*s).m_head
	}
	else {//ͷ�巨
		pNew->next = s->m_head;
		s->m_head = pNew;
	}
	s->m_size++;
}
void pop(pSTACK s) {//ջ��Ԫ�ص���
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
int isEmpty(pSTACK s) {//Ϊ�շ���1�����򷵻�0
	if (0 == s->m_size)return 1;
	else return 0;
}
int size(pSTACK s) {
	return s->m_size;
}