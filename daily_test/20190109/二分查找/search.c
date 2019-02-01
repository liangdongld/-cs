#include "Search.h"
int search(int a[], int key) {
	int low, high, mid;
	low = 0;
	high = N-1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (a[mid] == key)return mid;
		else if (a[mid] > key)high = mid - 1;
		else if (a[mid] < key)low = mid + 1;
	}
	return -1;
}
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
void print(int a[]) {
	int i;
	for (i = 0; i < N; i++)printf("%d ", a[i]);
	printf("\n");
}