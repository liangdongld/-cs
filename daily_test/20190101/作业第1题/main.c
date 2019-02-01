#include <stdio.h>
#include  <stdlib.h>
int main() {
	char ch;
	while (scanf("%c", &ch) != EOF) {
		if (ch == '\n') {
			printf("\n");
			continue;
		}
		ch -= 32;
		printf("%c", ch);
	}
	system("pause");
	return 0;
}