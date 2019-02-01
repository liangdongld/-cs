//十进制转二进制
#include <stdio.h>
void solution(int key) {
	int i = 1;
	int count = 0;
	int temp = key;
	if (key == 0) {
		printf("0\n");
		return;
	}
	while (key-i>=0) {
		i *= 2;
		count++;
	}
	for (int q = count-1 ; q >= 0; q--) {
		if (temp - (1 << q) >= 0) {
			temp -= 1<< q;
			printf("1");
		}
		else printf("0");
	}
	printf("\n");
}
int main() {
	int a;
	while (printf("请输入需要转换的数字："), scanf("%d", &a) != EOF)	solution(a);
	system("pause");
}