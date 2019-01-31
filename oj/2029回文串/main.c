#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int n,i;
	char a[100];
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		int flag;
		fgets(a, sizeof(a), stdin);
		a[strlen(a) - 1] = '\0';
		int len = strlen(a);
		int j;
		for (j = 0; j < len / 2; j++) {
			if (a[j] == a[len - 1-j]) {
				flag = 1;
				continue;
			}
			else {
				flag = 0;
				break;
			}
		}
		if (flag)printf("yes\n");
		else printf("no\n");
	}
}