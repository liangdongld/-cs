#include "addBigNum.h"
int main() {
	CinkList head = NULL, tail = NULL;
	LinkList head1 = NULL, tail1 = NULL, head2 = NULL, tail2 = NULL;
	char ch;
	int n;
	int count = 0;
	printf("\n��үҪ�漸�ΰ�~~~~       ");
	scanf("%d", &n);
	getchar();
	while (n--) {
		printf("\n�͹ٻ���%d��\n", n + 1);
		count = 0;
		head1 = NULL, tail1 = NULL, head2 = NULL, tail2 = NULL;
		head = NULL, tail = NULL;

		printf("�������һ����:\n");
		while (scanf("%c", &ch) != EOF) {
			if (ch == '\n')break;
			CHeadInsert(&head, &tail, ch);
			count++;
		}
		CinkList p = head, ppre = head;
		while (p) {
			p->ch -= 48;
			TailInsert(&head1, &tail1, p->ch);
			ppre = p;
			p = p->next;
			free(ppre);
		}
		head = NULL, tail = NULL;
		printf("������ڶ�����:\n");
		while (scanf("%c", &ch) != EOF) {
			if (ch == '\n')break;
			CHeadInsert(&head, &tail, ch);
			count--;
		}
		p = head, ppre = head;
		while (p) {
			p->ch -= 48;
			TailInsert(&head2, &tail2, p->ch);
			ppre = p;
			p = p->next;
			free(ppre);
		}
		if(count>0)while(count--)TailInsert(&head2, &tail2, 0);
		else while (count++<0)TailInsert(&head1, &tail1, 0);
		addBigNumber(head1, head2);
		freeLinklist(head1);
		freeLinklist(head2);
	}
}
