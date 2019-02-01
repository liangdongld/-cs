//1 九九乘法表
/*#include<stdio.h>
int main() {
	for (int i = 1; i <= 9; i++) {
		if (i != 1)printf("\n");
		for (int j = 1; j <= 9; j++) {
			if(i>=j)printf("%d * %d = %d  ", i, j, i*j);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}*/

//2.1 实心菱形
/*#include<stdio.h>
int main() {
	int a = 0, b = 0;
	for (int i = 1; i <= 5; i++) {
		a = (9 - (i * 2 - 1)) / 2;
		for (int j = 0; j < a; j++)printf(" ");
		for (int j = 0; j < i * 2 - 1; j++) {
			if (j % 2 == 0)printf("*");
			else printf(" ");
		}
		for (int j = 0; j < a; j++)printf(" ");
		printf("\n");
	}
	for (int i = 5; i >= 2; i--) {
		a = (9 - (i * 2 - 1)) / 2;
		for (int j = 0; j < a; j++)printf(" ");
		for (int j = i * 2 - 1; j >0; j--) {
			if (j % 2 == 0)printf("*");
			else printf(" ");
		}
		for (int j = 0; j < a; j++)printf(" ");
		printf("\n");
	}
	system("pause");
	return 0;
}*/

//2.2 空心菱形
/*#include<stdio.h>
int main() {
	int a = 0, b = 0;
	for (int i = 1; i <= 5; i++) {
		a = (9 - (i*2-1)) / 2;
		for (int j = 0; j < a; j++)printf(" ");
		for (int j = 0; j < i * 2 - 1; j++) { 
			if(j==0||j==i*2-2)printf("*"); 
			else printf(" ");
		}
		for (int j = 0; j < a; j++)printf(" ");
		printf("\n");
	}
	for (int i = 4; i >= 1; i--) {
		a = (9 - (i * 2 - 1)) / 2;
		for (int j = 0; j < a; j++)printf(" ");
		for (int j = i * 2 - 1; j >0; j--) {
			if (j == 1 || j == i * 2 - 1)printf("*");
			else printf(" ");
		}
		for (int j = 0; j < a; j++)printf(" ");
		printf("\n");
	}
	system("pause");
	return 0;
}*/

//2.3 心形
#include<stdio.h>
int main() {
	int a = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = 4 - i; j > 0; j--)printf(" ");
		for (int j = 0; j < 2 * i + 1; j++) {
			if (j % 2 == 0)printf("*");
			else printf(" ");
		}
		for (int j = 4 - i; j > 0; j--)printf(" ");
		printf(" ");
		for (int j = 4 - i; j > 0; j--)printf(" ");
		for (int j = 0; j < 2 * i + 1; j++) {
			if (j % 2 == 0)printf("*");
			else printf(" ");
		}
		for (int j = 4 - i; j > 0; j--)printf(" ");
		printf("\n");
	}
	for (int i = 10; i >= 1; i--) {
		a = (19- (i * 2 - 1)) / 2;
		for (int j = 0; j < a; j++)printf(" ");
		for (int j = i * 2 - 1; j >0; j--) {
			if (j % 2 != 0)printf("*");
			else printf(" ");
		}
		for (int j = 0; j < a; j++)printf(" ");
		printf("\n");
	}
	system("pause");
	return 0;
}

//4.1 求两个有序数组的公共元素
/*#include<stdio.h>
#include <stdlib.h>
int count = 0;
int* solution(int *a, int *b) {
	int t_a = _msize(a)/4;
	int t_b = _msize(b)/4;
	count = 0;
	int *c, *a_c, *b_c,*c_c;
	c = (int*)malloc(sizeof(int)*t_a);
	a_c = a;
	b_c = b;
	c_c = c;
	while (1) {
		if (t_a == 0 || t_b == 0)break;
		if (*a_c == *b_c) { //若a与b某个位置的元素相同，则将其添加入c数组
			*c_c = *a_c;
			c_c += 1;
			a_c += 1;
			b_c += 1;
			count++;
			t_a--;
			t_b--;
		}
		if (*a_c < *b_c) {
			a_c += 1;
			t_a--;
		}
		if (*a_c > *b_c) {
			b_c += 1;
			t_b--;
		}
	}
	return c;
}
int main() {
	int *a = (int*)malloc(sizeof(int));
	*a = 0;
	int *b = (int*)malloc(sizeof(int));
	*b = 0;
	int c,a_s,b_s;
	printf("请输入第一个数组元素个数：");
	scanf("%d", &a_s);
	a = (int*)malloc(sizeof(int)*a_s);
	int *a_ = a;
	printf("请输入第一个有序数组：\n");
	while (a_s>0) {
		scanf("%d", &c);
		*a_ = c;
		a_ += 1;
		a_s--;
	}
	printf("请输入第二个数组元素个数：");
	scanf("%d", &b_s);
	b = (int*)malloc(sizeof(int)*b_s);
	int *b_ = b;
	printf("请输入第二个有序数组：\n");
	while (b_s>0) {
		scanf("%d", &c);
		*b_ = c;
		b_ += 1;
		b_s--;
	}
	int *s = solution(a, b);
	printf("相同元素为：\n");
	for (int i = 0; i < count; i++)printf("%d  ", *(s + i));
	printf("\n");
	system("pause");
	return 0;
}*/

//4.2 求三个有序数组的公共元素
/*#include <stdio.h>
#include <stdlib.h>
int count = 0;
int *solution(int a[], int b[], int c[], int a_s, int b_s, int c_s) {
	count = 0;
	int a_t = 0, b_t = 0, c_t = 0;
	int *ret_1 = (int*)malloc(sizeof(int)*a_s);
	int *ret = ret_1;
	while (1) {
		if (a_t == a_s + 1 || b_t == b_s + 1 || c_t == c_s + 1)return ret;
		if (a[a_t] == b[b_t] && c[c_t] == a[a_t]) {
			*ret_1 = a[a_t];
			ret_1 += 1;
			a_t++; b_t++; c_t++;
			count++;
		}
		else if(a[a_t]<b[b_t]||a[a_t]<c[c_t]){
			a_t++;
		}
		else if (b[b_t] < a[a_t] || b[b_t] < c[c_t]) {
			b_t++;
		}
		else if (c[c_t] < b[b_t] || c[c_t] < a[a_t]) {
			c_t++;
		}	
	}
	return 0;
}
int main() {
	int *a, *b, *c;
	int  a_n, b_n, c_n;
	int *a_i, *b_i, *c_i;
	printf("请输入第一个数组的长度：");
	scanf("%d", &a_n);
	a = (int*)malloc(sizeof(int)*a_n);
	a_i = a;
	printf("请输入第一个数组元素：\n");
	for (int i = 0; i < a_n; i++) scanf("%d", (a_i+i));

	printf("请输入第二个数组的长度：");
	scanf("%d", &b_n);
	b = (int*)malloc(sizeof(int)*b_n);
	b_i = b;
	printf("请输入第二个数组元素：\n");
	for (int i = 0; i < b_n; i++) scanf("%d", (b_i+i));

	printf("请输入第三个数组的长度：");
	scanf("%d", &c_n);
	c = (int*)malloc(sizeof(int)*c_n);
	c_i = c;
	printf("请输入第三个数组元素：\n");
	for (int i = 0; i < c_n; i++) scanf("%d", (c_i+i));

	printf("公共元素为：\n");
	int *ret = solution(a, b, c, a_n, b_n, c_n);
	//int a[] = { 1,2,3,4,5,6 };
	//int b[] = { 2,3,4,5,6,7 };
	//int c[] = { 3,4,5,6,7 };
	//int *ret = solution(a, b, c, 6, 6, 5);
	for (int i = 0; i < count; i++) printf(i==0?"%d":" %d", *(ret + i));
	printf("\n");
	return 0;
}*/

//5 求数组的最大值和次大值。
/*#include <stdio.h>
#include <stdlib.h>
int* solution(int a[], int n) {
	int max_1, max_2;
	max_1 = a[0];
	max_2 = a[0];
	for (int i = 0; i < n; i++) {
		if (max_1 < a[i]) {
			max_2 = max_1;
			max_1 = a[i];
		}
	}
	int *s = (int*)malloc(sizeof(int) * 2);
	*s = max_1;
	*(s + 1) = max_2;
	return s;
}
int main() {
	int *a, n;
	printf("请输入数组大小：");
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &*(a + i));
	}
	int *s = solution(a, n);
	printf("最大值为：%d\n次大值为：%d\n", *s, *(s + 1));
	system("pause");
	return 0;
}*/

//6 给定一个n个整型元素的数组a，其中有一个元素出现次数超过n / 2，求这个元素
//#include <stdio.h>
//#include <stdlib.h>
//#include<memory>
//int solution(int a[],int n) {
//	int count = 0;
//	int temp = 0;
//	for (int i = 0; i < n; i++) {
//		count = 0;
//		temp = a[i];
//		for (int j = 0; j < n; j++) {
//			b[j] = a[j] - temp;
//			if (b[j] == 0) count++;
//		}
//		if (count > n / 2)return temp;
//	}
//	return -1;
//}
//int main() {
//	int a[] = { 1,2,3,3,3,3,3,3,3};
//	printf("%d", solution(a, 9));
//	return 0;
//}

//7 给定一个含有n个元素的整型数组，找出数组中的两个元素x和y使得abs(x - y)值最小
/*#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#define MAX 1000
int* solution(int a[], int n) {//使用暴力拆解法
	int min = MAX;
	int *s = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (abs(a[i] - a[j]) < min) {
				min = abs(a[i] - a[j]) < min;
				*s = a[i];
				*(s + 1) = a[j];
			}
		}
	}
	return s;
}
int main() {
	int *a, n;
	printf("请输入数组大小：");
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &*(a + i));
	}
	int *s = solution(a, n);
	printf("绝对值相减最小的x，y分别为%d，%d\n",*s,*(s+1));
	system("pause");
	return 0;
}*/

//8 给定含有1001个元素的数组，其中存放了1-1000之内的整数，只有一个整数是重复的，
/*#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int solution(int a[]) {
	bool c[1000];
	memset(c, false, sizeof(c));
	for (int i = 0; i < 1001; i++) {
		c[a[i]] = !c[a[i]];
	}
	for (int i = 0; i < 1000; i++)if (c[i] == false)return i;
	return -1;
}
int main() {
	int a[1001];
	for (int i = 0; i < 1000; i++)a[i] = i;
	a[1000] = 957; //假设重复元素为 957 
	printf("%d\n", solution(a));
	system("pause");
	return 0;
}*/