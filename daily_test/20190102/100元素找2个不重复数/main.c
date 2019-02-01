#include <stdio.h>
void solution(int a[],int n) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret = ret^a[i];
	}
	int flag = ret&(~ret + 1);//取1最小位
	int iNumb1 = 0, iNumb2 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] & flag)iNumb1 = iNumb1^a[i];
		else iNumb2 = iNumb2^a[i];
	}
	printf("%d  %d\n", iNumb1, iNumb2);
}
int main() {
	int a[102];
	for (int i = 0; i < 100; i++) {
		a[i] = i/2;
	}
	a[100] = 321;
	a[101] = 234;
	solution(a, 102);
	system("pause");
	return 0;
}