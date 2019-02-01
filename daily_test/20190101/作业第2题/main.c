#include <stdio.h>
void print(int n) {
	printf("  %d  \n", n);
	for (int i = 0; i < n; i++) printf("*****\n\n");
	printf("\n");
}
int main(){
	int a, b, c, ch;
	a = b = c = 0;
	while ((ch = getchar()) != '\n'){
		if (ch >= '0' && ch <= '9')
			a++;
		else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			b++;
		else
			c++;
	}
	printf("数字个数为：%d\t字母个数为：%d\t其他字符个数为：%d\t\n", a, b, c);
	int s[3];
	s[0] = a;
	s[1] = b;
	s[2] = c;
	int temp;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			if (s[j] > s[j + 1]) {
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	print(s[2]); print(s[1]); print(s[0]);
	return 0;
}