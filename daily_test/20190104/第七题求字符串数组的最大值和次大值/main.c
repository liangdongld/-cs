#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�ַ�����������ֵ�ʹδ�ֵ
void big(char *arr[], int size, char** big1, char** big2) {//�൱��ָ������  **p����ָ�� ָ������
	char **p = arr;
	big1 = p;
	char *ch[] = { "zzzzzzzz" };
	big2 = ch;//��big2��ʼ����Сֵ
	for (int i = 1; i < size; i++){
		*p++;// *p �����׵�ַ
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
	int *a[3];// ָ������   �����Ǹ����� ����ÿ��λ�ô����ָ��
	int(*b)[3]; //����ָ�� ��������ָ�� ������ָ��һ��ֻ��3��Ԫ�ص����� ��ʱb������������ָ���һά���鳤��Ϊ��λ��
	char *arr[] = { "abcde","qscdez","bertws","dfasdfgg","vugsdfgd" };
	printf("�������ݣ�\n");
	for (int i = 0; i < 5; i++) {
		puts(arr[i]);
	}
	printf("----------------------------------------\n");
	char **big1=NULL, **big2=NULL;
	char **p = arr;
	big(p, 5, big1, big2);


	return 0;
}