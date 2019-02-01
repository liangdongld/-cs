//寻找三个非重复数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 103
void findTwonum(int arr[],int len,int result) {

}
int main() {
	int question[MAX];
	int arr_1[MAX], arr_2[MAX];
	int iHeap1, iHeap2, iHeapCount1, iHeapCount2, flag = 1;
	for (int i = 0; i < 100; i++)question[i] = i / 2;
	question[100] = 654;
	question[101] = 423;
	question[102] = 862;
	for (int i = 0; i < 16; i++) {
		flag = 1 << i;
		iHeapCount1 = iHeapCount2 = 0;
		iHeap1 = iHeap2 = 0;
		for (int j = 0; j < MAX; j++) {
			if (j <= i) {
				arr_1[iHeapCount1] = question[j];
				iHeap1 ^= question[j];
				iHeapCount1++;
			}
			else {
				arr_1[iHeapCount1] = question[j];
				iHeap2 ^= question[j];
				iHeapCount2++;
			}
		}
		if (iHeapCount1 % 2 == 0 && iHeap1 != 0) {
			printf("Find one : %d", iHeap2);
			findTwonum()
		}
	}
}