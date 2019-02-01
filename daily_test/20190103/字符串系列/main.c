// strcat strcmp strcpy strlen strncat strncmp strncpy  memcmp memcpy memset
/*
	char *strcat(char *str1, const char *str2);功能：函数将字符串str2 连接到str1的末端，并返回指针str1.
	int strcmp( const char *str1, const char *str2 );比较字符串str1 and str2,
	char *strcpy( char *to, const char *from );复制字符串from 中的字符到字符串to，包括空值结束符。返回值为指针to。
	size_t strlen( char *str );函数返回字符串str 的长度( 即空值结束符之前字符数目)。
	int strncmp( const char *str1, const char *str2, size_t count );比较字符串str1 和 str2中至多count个字符
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() 
{
	char a[1000], b[1000];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	while (gets(a)) {
		strcpy(b, a); 
		puts(b);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}
	system("pause");
	return 0;
}