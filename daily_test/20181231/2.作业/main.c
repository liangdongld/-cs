//1 �žų˷���
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

//2.1 ʵ������
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

//2.2 ��������
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

//2.3 ����
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

//4.1 ��������������Ĺ���Ԫ��
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
		if (*a_c == *b_c) { //��a��bĳ��λ�õ�Ԫ����ͬ�����������c����
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
	printf("�������һ������Ԫ�ظ�����");
	scanf("%d", &a_s);
	a = (int*)malloc(sizeof(int)*a_s);
	int *a_ = a;
	printf("�������һ���������飺\n");
	while (a_s>0) {
		scanf("%d", &c);
		*a_ = c;
		a_ += 1;
		a_s--;
	}
	printf("������ڶ�������Ԫ�ظ�����");
	scanf("%d", &b_s);
	b = (int*)malloc(sizeof(int)*b_s);
	int *b_ = b;
	printf("������ڶ����������飺\n");
	while (b_s>0) {
		scanf("%d", &c);
		*b_ = c;
		b_ += 1;
		b_s--;
	}
	int *s = solution(a, b);
	printf("��ͬԪ��Ϊ��\n");
	for (int i = 0; i < count; i++)printf("%d  ", *(s + i));
	printf("\n");
	system("pause");
	return 0;
}*/

//4.2 ��������������Ĺ���Ԫ��
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
	printf("�������һ������ĳ��ȣ�");
	scanf("%d", &a_n);
	a = (int*)malloc(sizeof(int)*a_n);
	a_i = a;
	printf("�������һ������Ԫ�أ�\n");
	for (int i = 0; i < a_n; i++) scanf("%d", (a_i+i));

	printf("������ڶ�������ĳ��ȣ�");
	scanf("%d", &b_n);
	b = (int*)malloc(sizeof(int)*b_n);
	b_i = b;
	printf("������ڶ�������Ԫ�أ�\n");
	for (int i = 0; i < b_n; i++) scanf("%d", (b_i+i));

	printf("���������������ĳ��ȣ�");
	scanf("%d", &c_n);
	c = (int*)malloc(sizeof(int)*c_n);
	c_i = c;
	printf("���������������Ԫ�أ�\n");
	for (int i = 0; i < c_n; i++) scanf("%d", (c_i+i));

	printf("����Ԫ��Ϊ��\n");
	int *ret = solution(a, b, c, a_n, b_n, c_n);
	//int a[] = { 1,2,3,4,5,6 };
	//int b[] = { 2,3,4,5,6,7 };
	//int c[] = { 3,4,5,6,7 };
	//int *ret = solution(a, b, c, 6, 6, 5);
	for (int i = 0; i < count; i++) printf(i==0?"%d":" %d", *(ret + i));
	printf("\n");
	return 0;
}*/

//5 ����������ֵ�ʹδ�ֵ��
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
	printf("�����������С��");
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &*(a + i));
	}
	int *s = solution(a, n);
	printf("���ֵΪ��%d\n�δ�ֵΪ��%d\n", *s, *(s + 1));
	system("pause");
	return 0;
}*/

//6 ����һ��n������Ԫ�ص�����a��������һ��Ԫ�س��ִ�������n / 2�������Ԫ��
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

//7 ����һ������n��Ԫ�ص��������飬�ҳ������е�����Ԫ��x��yʹ��abs(x - y)ֵ��С
/*#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#define MAX 1000
int* solution(int a[], int n) {//ʹ�ñ�����ⷨ
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
	printf("�����������С��");
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &*(a + i));
	}
	int *s = solution(a, n);
	printf("����ֵ�����С��x��y�ֱ�Ϊ%d��%d\n",*s,*(s+1));
	system("pause");
	return 0;
}*/

//8 ��������1001��Ԫ�ص����飬���д����1-1000֮�ڵ�������ֻ��һ���������ظ��ģ�
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
	a[1000] = 957; //�����ظ�Ԫ��Ϊ 957 
	printf("%d\n", solution(a));
	system("pause");
	return 0;
}*/