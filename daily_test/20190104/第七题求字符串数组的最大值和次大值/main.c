#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//字符串数组的最大值和次大值
void big(char *arr[], int size, char** big1, char** big2) {//相当于指针数组  **p可以指向 指针数组
	char **p = arr;
	big1 = p;
	char *ch[] = { "zzzzzzzz" };
	big2 = ch;//给big2初始化最小值
	for (int i = 1; i < size; i++){
		*p++;// *p 数组首地址
		if ( **p  < **big1) {
			big2 = big1;
			big1 = p;
		}
		else if (**p < **big2) {
			big2 = p;
		}
	}
	printf("First Max:\t\t");
	puts(*big1);
	printf("Second Max:\t\t");
	puts(*big2);
}
int main() {
	int *a[3];// 指针数组   本质是个数组 不过每个位置存的是指针
	int(*b)[3]; //数组指针 本质上是指针 本例中指向一个只有3个元素的数组 此时b的增量以它所指向的一维数组长度为单位；
	char *arr[] = { "abcde","qscdez","bertws","dfasdfgg","vugsdfgd" };
	printf("数组内容：\n");
	for (int i = 0; i < 5; i++) {
		puts(arr[i]);
	}
	printf("----------------------------------------\n");
	char **big1=NULL, **big2=NULL;
	char **p = arr;
	big(p, 5, big1, big2);


	return 0;
}