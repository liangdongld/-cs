#include "Stack.h"
int main() {
	pSTACK s;
	s = (pSTACK)calloc(1, sizeof(STACK));
	int i, n;
	while (scanf("%d", &n) != EOF) {//Ԫ����ջ -1��ʾ����
		if (-1 == n)break;
		else push(s, n);
	}
	//����ջ��Ԫ��
	printf("Top value of this stack : %d\n", getTop(s));
	//��ջ 
	pop(s);
	pop(s);
	pop(s);
	printf("Is this stack empty?  %d\n", isEmpty(s));
	printf("The size of this stack is %d\n", size(s));
}