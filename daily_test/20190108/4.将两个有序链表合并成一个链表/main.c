#include "Linklist.h"
int main() {
	LinkList head_1 = NULL, head_2 = NULL, tail_1 = NULL, tail_2 = NULL;
	int key;
	printf("Please input list_1's elements:\n");
	while (scanf("%d", &key) != EOF) {
		if (-1 == key) {
			break;
		}
		SortInsert(&head_1, &tail_1, key);
	}
	printf("Print list_1 : \n");
	print(head_1);
	printf("Please input list_2's elements:\n");
	while (scanf("%d", &key) != EOF) {
		if (-1 == key) {
			printf("Complete!\n");
			break;
		}
		SortInsert(&head_2, &tail_2, key);
	}
	printf("Print list_1\n");
	print(head_2);
	printf(" merging...\n");
	LinkList l3 = combine(head_1, head_2);
	print(l3);
}