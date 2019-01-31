#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	int a[50][50] = { 0 };
	while (scanf("%d", &n) != EOF) {
		int i, j;
		for (i = 1; i <= n; i++) {
			a[1][i] = 1;
		}
		for (i = 1; i <= n; i++) {
			a[i][1] = 1;
		}
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= i; j++) {
				if (i == 1 || j == 1||i==j)a[i][j] = 1;
				else a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
				printf(i == 1 || i == j ?"%d":"%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}