//二进制->十进制
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int solution(char a[],int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum+=((a[i]-48) << i);
	}
	return sum;
}
int main() {
	char c[32];
	int n = 0;
	char a;
	memset(c, '3', 32);
	while (1) {
		n = 0;
		while (scanf("%c", &a) != EOF) {
			if (a == '\n')break;
			c[n] = a;
			n++;
		}
		for (int i = 0; i < n / 2; i++) {
			a = c[n - i - 1];
			c[n - i - 1] = c[i];
			c[i] = a;
		}
		int ret = solution(c, n);

		printf("%d\n", ret);
	}
}