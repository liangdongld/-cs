#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
bool isLegal(char *a) {
	int flag = 0;
	int i = strlen(a);
	if (a[0] >= 'a'&&a[0] <= 'z' || a[0] >= 'A'&&a[0] <= 'Z' || a[0] == '_')flag++;
	else return false;
	int count = 1;
	for (count = 1; count < i; count++) {
		if (a[count] >= 'a'&&a[count] <= 'z' || a[count] >= 'A'&&a[count] <= 'Z' || a[count] == '_' || a[count] >= '0'&&a[count] <= '9') {
			flag++;
			continue;
		}
		else return false;
	}
	if (flag == i)return true;
	else return false;
}
int main() {
	char a[100];
	int n;
	int i;
	scanf("%d\n", &n);
	for (i = 0; i < n; i++) {
		fflush(stdin);
		fgets(a, sizeof(a), stdin);
		a[strlen(a) - 1] = '\0';
		if (isLegal(a))printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
