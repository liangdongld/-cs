// strcat strcmp strcpy strlen strncat strncmp strncpy  memcmp memcpy memset
/*
	char *strcat(char *str1, const char *str2);���ܣ��������ַ���str2 ���ӵ�str1��ĩ�ˣ�������ָ��str1.
	int strcmp( const char *str1, const char *str2 );�Ƚ��ַ���str1 and str2,
	char *strcpy( char *to, const char *from );�����ַ���from �е��ַ����ַ���to��������ֵ������������ֵΪָ��to��
	size_t strlen( char *str );���������ַ���str �ĳ���( ����ֵ������֮ǰ�ַ���Ŀ)��
	int strncmp( const char *str1, const char *str2, size_t count );�Ƚ��ַ���str1 �� str2������count���ַ�
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