#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void q(int a[], int lenth) {
	a[0] = 10;
	return;
}
int main() {
	int a[] = { 1,2,3,4,5 };
	int len=5;
	q(a, 5);
	printf("%d\n", a[0]);
	system("pause");
	return 0;
}