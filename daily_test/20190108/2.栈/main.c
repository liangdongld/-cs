#include "Stack.h"
int main() {
	pSTACK s;
	s = (pSTACK)calloc(1, sizeof(STACK));
	int i, n;
	while (scanf("%d", &n) != EOF) {//元素入栈 -1表示结束
		if (-1 == n)break;
		else push(s, n);
	}
	//返回栈顶元素
	printf("Top value of this stack : %d\n", getTop(s));
	//出栈 
	pop(s);
	pop(s);
	pop(s);
	printf("Is this stack empty?  %d\n", isEmpty(s));
	printf("The size of this stack is %d\n", size(s));
}