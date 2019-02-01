//#include <stdio.h>
//typedef struct Link {
//	int val;
//	struct  Link *next;
//} ListNode;
//
// ListNode* swapPairs(ListNode* head) {
//	 ListNode* ppre = NULL, *pcur = NULL, *nex = NULL;
//	 pcur = head->next;
//	 nex = pcur->next;
//	 while (nex != NULL) {
//
//	 }
//}
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
	bool *a = (bool*)calloc(numsSize, sizeof(bool));
	int i, count = 0;
	for (i = 0; i < numsSize; i++) {
		a[nums[i]-1] = true;
	}
	memset(nums, '\0', numsSize*sizeof(int));
	returnSize = nums;
	for (i = 0; i < numsSize; i++) {
		if (!a[i]) {
			returnSize[count] = i + 1;
			count++;
		}
	}
	return returnSize;
}

int main() {
	int a[] = { 4,3,3,7,8,2,3,1 };
	int *p = NULL;
	int *q = findDisappearedNumbers(a, 8, p);
	printf("%d %d %d\n", q[0], q[1],q[2]);
	return 0;
}