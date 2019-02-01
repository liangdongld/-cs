#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int solution(char *str) {//统计单词数
	int count = 0, flag1=0, flag2=0;
	int i = strlen(str);
	for (int j = 0; j < i; j++) {
		if (*(str + j) == ' ')flag1 = 0;
		else {
			flag2 = flag1;
			flag1 = 1;
		}
		if (flag1 - flag2 > 0)count++;
	}
	return count;
}
int main() {
	char a[100];
	printf("Please input a string:\n");
	while (gets(a) != NULL) {
		printf("The number of word in this string is: %d\n\n", solution(a));
		printf("Please input a string:\n");
	}
}