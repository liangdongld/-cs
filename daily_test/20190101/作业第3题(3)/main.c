#include <stdio.h>
#include <stdlib.h>
int main() {
	int a;
	while (printf("请输入一个10进制数："),scanf("%d", &a) != EOF) printf("对应十六进制为：%X\n", a);
}