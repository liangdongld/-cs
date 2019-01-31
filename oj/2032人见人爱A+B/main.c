#include <stdio.h>
#include <stdlib.h>
int main() {
	int a[6];
	int n;
	while (scanf("%d", &n) != EOF) {
		for (; n > 0; n--) {
			int i;
			int ret[3];
			int flag = 0;
			for (i = 0; i < 6; i++) {
				scanf("%d", &a[i]);
			}
			for (i = 2; i >= 1; i--) {
				ret[i] = a[i] + a[i + 3] + flag;
				if (ret[i] >= 60) {
					flag = 1;
					ret[i] -= 60;
				}
				else flag = 0;
			}
			ret[0] = a[0] + a[3] + flag;
			for (i = 0; i < 3; i++)printf(i == 0 ? "%d" : " %d", ret[i]);
			printf("\n");
		}
	}
}