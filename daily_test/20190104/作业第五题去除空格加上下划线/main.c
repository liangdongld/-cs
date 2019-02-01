#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Word_print(char str[], char a[][30]) {
	int count = -1, flag1 = 0, flag2 = 0;
	int i = strlen(str);
	int n = 0;
	for (int j = 0; j < i; j++) {
		if (*(str + j) == ' ')flag1 = 0;
		else {
			flag2 = flag1;
			flag1 = 1;
		}
		if (flag1 - flag2 > 0) {
			count++;
			n = 0;
			a[count][n] = str[j];
			n++;
		}
		else if (flag1 == flag2&&flag1 == 1) {
			a[count][n] = str[j];
			n++;
		}
	}
	return count;
}
int main() {
	char str[100];
	char a[50][30] = { 0 };
	while (gets(str) != NULL) {
		int count = Word_print(str, a);
		for (int i = 0; i < count + 1; i++) {
			printf(i==0?"%s":"_%s", a[i]);
		}
		memset(str, 0, 100);
		memset(a, 0, 1500);
		rewind(stdin);
	}
	system("pause");
	return 0;
}
