#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char FindMax(char *a) {
	int i = strlen(a);
	char max;
	max = a[0];
	int j;
	for (j = 1; j < i; j++) {
		if (a[j] > max)max = a[j];
	}
	return max;
}
void Max(char *a) {
	int i = strlen(a);
	int count = 0;
	int p = 0;
	char max = FindMax(a);
	int j;
	for (j = 0; j < i; j++)if (max == a[j])count++;
	for (j = i; j >=0; j--) {
		if (a[j] != max) {
			a[j+5*count-5*p] = a[j];
		}
		else {
			a[j + 5 * count - 5 * p] = ')';
			a[j + 5 * count - 5 * p -1] = 'x';
			a[j + 5 * count - 5 * p - 2] = 'a';
			a[j + 5 * count - 5 * p - 3] = 'm';
			a[j + 5 * count - 5 * p - 4] = '(';
			a[j + 5 * count - 5 * p - 5] = max;
			p++;
		}
	}
	printf("%s\n", a);
}

int main() {
	char a[100];
	while (scanf("%s",a)!=EOF) {
		rewind(stdin);
		Max(a);
	}
	return 0;
}
