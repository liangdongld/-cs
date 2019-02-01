#include "Sort.h"
int main() {
	int i;
	int start, end;
	int *a = (int *)calloc(N, sizeof(int));
	srand(time(NULL));
	for (i = 0; i < N; i++) {
		a[i] = rand()%100;
	}
	//Qsort(a, 0, N-1);
	start = time(NULL);
	arrHeap(a, N);
	end = time(NULL);
	printf("¶ÑÅÅÐò£º%d\n", end - start);
	start = time(NULL);
	CountSort(a);
	end = time(NULL);
	printf("¼ÆÊýÅÅÐò£º%d\n", end - start);
	system("pause");
}