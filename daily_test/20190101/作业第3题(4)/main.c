#include<stdio.h>
int main() {
	int a;
	while (printf("请输入一个十六进制数(字母大写)："), scanf("%X", &a) != EOF)printf("对应十进制数为：%d\n", a);
	system("pause");
	return 0;
}