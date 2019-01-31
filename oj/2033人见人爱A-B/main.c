//AC
#include <stdio.h>
#include <stdlib.h>
#define CPT -9999
int main() {
	int m, n;
	int *p1, *p2;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (m == 0 && n == 0) break; 
		p1 = (int*)malloc(sizeof(int) * n);
		p2 = (int*)malloc(sizeof(int) * m);
		int i, j;
		for (i = 0; i < n; i++)scanf("%d", &p1[i]);
		for (j = 0; j < m; j++)scanf("%d", &p2[j]);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (p1[i] == p2[j]) {
					p1[i] = CPT;
					continue;
				}
			}
		}
		int flag = 0;
		int *ret = (int*)malloc(sizeof(int) * n);
		int count = 0;
		for (i = 0; i < n; i++) {
			if (p1[i] == CPT)continue;
			else {
				flag = 1;
				ret[count] = p1[i];
				count++;
			}
		}
		if (flag == 0) {
			printf("NULL\n");
		}
		for (i = 0; i < count - 1; i++)
			for (j = 0; j < count - 1; j++)
			{
				if (ret[j] > ret[j + 1]) {
					int tmp = ret[j];
					ret[j] = ret[j + 1];
					ret[j + 1] = tmp;
				}
			}
		for (i = 0; i < count; i++)printf("%d ", ret[i]);
		if (flag != 0)printf("\n");
	}
	return 0;
}