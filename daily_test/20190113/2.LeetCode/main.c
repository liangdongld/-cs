#include <stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int mid, flag, i = 0;
	double ret1, ret2;
	mid = (nums1Size + nums2Size) / 2;
	if ((nums1Size + nums2Size) % 2 == 0)flag = 0;
	else flag = 1;
	int *p1 = nums1, *p2 = nums2;
	int *p3 = (int *)malloc(sizeof(mid + 1));
	if (flag == 0)return (ret1 + ret2) / 2.0;
	else return ret2;
}
int main() {
	int a[4] = { 1,2 };
	int b[4] = { 3,4 };
	double i = findMedianSortedArrays(a, 2, b, 2);
	return 0;
}