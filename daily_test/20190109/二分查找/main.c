#include "Search.h"
int main() {
	srand(time(NULL));
	int a[N], i;
	for (i = 0; i < N; i++) {
		a[i] = rand()%100;
	}
	//print(a);
	Qsort(a, 0, N - 1);
	print(a);
	printf("��������Ҫ���ҵ�����");
	scanf("%d", &i);
	printf("%d��λ��Ϊ��%d\n",i,search(a, i)+1);
}