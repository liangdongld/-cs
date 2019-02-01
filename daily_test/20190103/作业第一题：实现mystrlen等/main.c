// strcat strcmp strcpy strlen strncat strncmp strncpy  memcmp memcpy memset
/*
char *strcat(char *str1, const char *str2);功能：函数将字符串str2 连接到str1的末端，并返回指针str1.
int strcmp( const char *str1, const char *str2 );比较字符串str1 and str2,
char *strcpy( char *to, const char *from );复制字符串from 中的字符到字符串to，包括空值结束符。返回值为指针to。
size_t strlen( char *str );函数返回字符串str 的长度( 即空值结束符之前字符数目)。
int strncmp( const char *str1, const char *str2, size_t count );比较字符串str1 和 str2中至多count个字符
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *mystrcpy(char *to, const char *from) {
	int i = strlen(from);
	for (int j = 0; j < i+1; j++) {
		*(to + j) = *(from + j);
	}
	return to;
}
int mystrcmp(const char *str1, const char *str2) {
	int str1_len = strlen(str1);
	int str2_len = strlen(str2);
	int i = str1_len > str2_len ? str2_len : str1_len;
	for (int j = 0; j < i; j++) {
		if (*(str1 + j) == *(str2 + j))continue;
		else if (*(str1 + j) > *(str2 + j))return 1;
		else return -1;
	}
	if (str1_len == str2_len)return 0;
	else if (str1_len > str2_len)return 1;
	else return -1;
}

char *mystrcat(char *str1, const char *str2) {//函数将字符串str2 连接到str1的末端，并返回指针str1.
	int i = strlen(str1);
	for (int j = 0; j < i+1; j++) {
		*(str1 + i + j) = *(str2 + j);
	}
	return str1;
}

size_t mystrlen(char *str) {
	int i = 0;
	for (; *(str + i) != NULL; i++);
	return i;
}

int main() {
	char a[100] = "helloworld_a";
	char b[100] = "helloworld_b";
	mystrcpy(b, a);
	int a_l = mystrlen(a);
	int b_l = mystrlen(b);
	printf("字符串a：%s\n字符串b：%s\n", a, b);
	strcpy(b, a);
	printf("1.mystrcpy(b,a)：%s\n", b);
	mystrcpy(a, "helloworld_a");
	mystrcpy(b, "helloworld_b");
	printf("2.mystrcmp：%d\n", mystrcmp(a, b));
	mystrcpy(a, "helloworld_a");
	mystrcpy(b, "helloworld_b");
	printf("3.mystrcat：%s\n", mystrcat(a, b));
	mystrcpy(a, "helloworld_a");
	mystrcpy(b, "helloworld_b");
	printf("4.mystrlen(a)：%d\n", mystrlen(a));
	system("pause");
	return 0;
}