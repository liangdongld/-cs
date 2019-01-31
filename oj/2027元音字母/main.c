#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main() {
	int n;
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
	char a[300];
	scanf("%d", &n);
	getchar();
	int i, count;
	for (i = 0; i < n; i++) {
		num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
		fgets(a, sizeof(a), stdin);
		count = strlen(a);
		int j;
		for (j = 0; j < count; j++) {
			if (a[j] == 'a')num1++;
			else if (a[j] == 'e')num2++;
			else if (a[j] == 'i')num3++;
			else if (a[j] == 'o')num4++;
			else if (a[j] == 'u')num5++;
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", num1, num2, num3, num4, num5);
		if (i != n - 1)printf("\n");
	}
}