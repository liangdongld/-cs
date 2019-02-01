#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//“h1ell2o3” ->”123hello”
void Mychange(char *a, char *b) {//a在前b在后   执行结束后 b在a前 其余顺序不变
	int i = 0;
	char temp = *b;
	while (a != b) {
		*b = *(b - 1);
		b--;
		i++;
	}
	*a = temp;
}
void solution(char *a) {
	char *num = a;
	char *alpha = a;
	while (*num != 0&& *alpha != 0) {
		while (*alpha != 0) {
			if ((*alpha >= 'a'&&*alpha <= 'z' || *alpha >= 'A'&&*alpha <= 'z')) break;
			else alpha++;
		}
		while (*num != 0) {
			if (*num >= '0'&&*num <= '9')break;
			else num++;
		}
		if (num > alpha&&*num != 0&&*alpha != 0) {
			char *temp = num - 1;
			Mychange(alpha, num);
			num = temp;
		}
		num++;
	}
}
int main() {
	char a[100];
	while (gets(a) != NULL) {
		solution(a);
		puts(a);
	}
	system("pause");
	return 0;
}
