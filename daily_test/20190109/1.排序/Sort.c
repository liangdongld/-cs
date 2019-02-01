#include "Sort.h"
//øÏÀŸ≈≈–Ú
void Qsort(int a[], int low, int high) {
		if (low >= high) return;
		int pivot = a[low];
		int i = low, j = high;
		while (i < j) {
			while (i < j&&pivot <= a[j])j--;
			a[i] = a[j];
			while (i<j&&pivot >= a[i])i++;
			a[j] = a[i];
		}
			a[i] = pivot;
			Qsort(a, low, i - 1);
			Qsort(a, i + 1, high);
}
//∂—≈≈–Ú
void SWAP(int *a, int *b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void arrMaxHeap(int *a, int start, int len) {
	int dad = start;
	int son = dad * 2 + 1;
	while (son < len) {
		if (son + 1 < len&&a[son] < a[son + 1])son++;
		if (a[dad] < a[son]) {
			SWAP(&a[dad], &a[son]);
			dad = son;
			son = dad * 2 + 1;
		}
		else break;
	}
}
void arrHeap(int *a, int len) {
	int i;
	for (i = N / 2 - 1; i >= 0; i--) {
		arrMaxHeap(a, i, N);
	}
	SWAP(&a[0], &a[N-1]);
	for (i = N - 1; i > 1; i--) {
		arrMaxHeap(a, 0, i);
		SWAP(&a[0], &a[i - 1]);
	}
}

void CountSort(int arr[]) {
	int arrVal[100] = { 0 };
	int i, k;
	for (i = 0; i < N; i++) {
		arrVal[arr[i]]++;
	}
	int cur = 0;
	for (k = 0; k < 100; k++) {
		for (i = 0; i < arrVal[k]; i++) {
			arr[cur++] = k;
		}
	}
}