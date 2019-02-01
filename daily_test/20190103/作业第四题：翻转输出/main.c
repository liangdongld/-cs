#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char *str) {
	int i = strlen(str);
	char temp;
	int count = 0, flag1 = 0, flag2 = 0;
	for (int j = 0; j < i/2; j++) {//ÕûÌåÄæÖÃ
		temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
	}

	int start, end;
	for (int j = 0; j < i; j++) {
		if (*(str + j) == ' '){
			flag2 = flag1;
			flag1 = 0; 
		}
		else {
			flag2 = flag1;
			flag1 = 1;
		}
		if (str[j - 1] == ' ')printf(" ");
		if (j == i - 1) {
			flag1 = 0;
			flag2 = 1;
			printf("%c", str[j]);
		}
		if (flag1 - flag2 > 0)start = j;
		else if (flag1 - flag2 < 0) {
			end = j-1;
			for (; end >= start; end--)printf("%c", *(str + end));
		}
	}
	printf("\n\n");
}
int main() {
	char a[100];
	printf("Please input a string:\n\t");
	while (gets(a)!=EOF) {
		printf("Reverse it:\n\t");
		reverse(a);
		printf("Please input a string:\n\t");
	}
}