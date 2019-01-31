#include <stdio.h>
#include <stdlib.h>
void transform(int a, int b) {
	int c, i = 0;
	char ret[100];
	int flag = 0;
	if (a < 0) { 
		a = -a; 
		flag = 1;
	}
	while (a != 0) {
		c = a%b;
		a /= b;
		if(c>9)ret[i] = c + 55;
		else ret[i] = c + 48;
		i++;
	}
	if (flag)printf("-");
	for (c = i - 1; c >= 0; c--)printf("%c", ret[c]);
	printf("\n");
}
int main() {
	int n, a;
	while (scanf("%d%d", &a, &n) != EOF) {
		transform(a, n);
	}
	return 0;
}