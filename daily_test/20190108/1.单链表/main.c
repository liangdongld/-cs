#include"Linklist.h"
int main() {
	LinkList head=NULL, tail=NULL;
	int i,key;
	int n = 0;
	printf("------------------------------------------------------\n");
	printf("1.ʹ��ͷ�巨��������(-1 ��ʾ����)\n\
2.ʹ��β�巨��������(-1 ��ʾ����)\n\
3.ʹ��������뽨������(-1 ��ʾ����)\n\
4.ɾ��ָ����ĳ���ڵ�\n\
5.��ӡ����\n\
6.�˳�\n");
	printf("------------------------------------------------------\n");
	printf("Please choice operation:   ");
	while (scanf("%d", &n) != EOF) {
		if (6 == n)return 0;
		switch (n)
		{
		case 1:
			printf("Please input number:\n");
			while (scanf("%d", &key) != EOF) {
			if (-1 == key) { 
				printf("Complete!\n");
				break; 
			}
			HeadInsert(&head, &tail, key);
		}
			   break;
		case 2:
			printf("Please input number:\n");
			while (scanf("%d", &key) != EOF) {
			if (-1 == key) {
				printf("Complete!\n");
				break;
			}
			TailInsert(&head, &tail, key);
		}
			   break;
		case 3:
			printf("Please input number:\n");
			while (scanf("%d", &key) != EOF) {
			if (-1 == key) {
				printf("Complete!\n");
				break;
			}
			SortInsert(&head, &tail, key);
		}
			   break;
		case 4:
			printf("Please input number:\n");
			scanf("%d", &key);
			Delete_key(&head, key);
			printf("Complete!\n");
			break;
		case 5:
			print(head);
			break;
		default:
			printf("Please input right number!\n");
			break;
		}
		printf("Please choice operation:   ");
	}
}