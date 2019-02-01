#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void delete_num(int *a,int n) {
	int *start1, *start2;
	start1 = start2 = a;
	int i = n;
	int count = 0;
	while (i>0) {
		if (*start1 == *start2) {
			start2++; i--;
		}
		else {
			start1++;
			count++;
			*start1 = *start2;
		}
	}
	for (int j = 0; j <= count; j++) {
		printf("%3d", a[j]);
	}
}
int main() {
	int *a;
	int n;
	printf("Please input the lenth of array : ");
	while (scanf("%d", &n) != EOF) {
		a = (int*)malloc(sizeof(int)*n);
		printf("Please input the elements of array:\n");
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		printf("delete....\n");
		delete_num(a, n);
		printf("\n\nPlease input the lenth of array : ");
	}
}