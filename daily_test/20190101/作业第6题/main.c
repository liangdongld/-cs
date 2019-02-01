#include <stdio.h>
#include <stdbool.h>
bool judge_year(int a) {
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)return true;
	return false;
}
int main() {
	int a[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int year, month, day;
	while (scanf("%d %d %d", &year, &month, &day) != EOF) {
		int ret = 0;
		for (int i = 0; i < month - 1; i++)ret += a[i];
		ret += day;
		if (judge_year(year) && month > 2)ret += 1;
		printf("%d\n", ret);
	}
	system("pause");
	return 0;
}