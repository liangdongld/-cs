#include <stdio.h>
#include <stdlib.h>
int main() {
	int a[101];
	for (int i = 0; i < 100; i++) {
		a[i] = i / 2;
	}
	a[100] = 12;
	int ret=0;
	for (int i = 0; i < 101; i++)ret = ret ^ a[i];
	printf("%d\n", ret);
	system("pause");
	return 0;
}