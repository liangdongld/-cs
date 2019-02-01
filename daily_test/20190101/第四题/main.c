#include <stdio.h>
void solution(int key) {
	int n = 0;
	int i = 1;
	int count = 0;
	int temp = key;
	while (key - i >= 0) {
		i *= 2;
		count++;
	}
	for (int q = count - 1; q >= 0; q--) {
		if (temp - (1 << q) >= 0) {
			temp -= 1 << q;
			n++;
		}
	}
	printf(" 1 的个数为%d\n", n);
}
int main() {
	int a;
	while (printf("请输入数字："), scanf("%d", &a) != EOF)	solution(a);
	system("pause");
}