#include<stdio.h>
#include <stdbool.h>
bool judge_year(int a) {
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)return true;
	return false;
}
void conclude(int year, int mon, int day, int n) {
	int a[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int b[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int *p;
	int r_y = year, r_m = mon, r_d = day;
	if (judge_year(r_y))p = b;
	else p = a;
	for (int i = 0; i < n; i++) {
		if (r_d + 1 <= *(p+r_m-1)) {// 天+1 <= 对应 月的天数
			r_d++;
		}
		else if (r_m + 1 <= 12) {
			r_m++;
			r_d = 1;
		}
		else {
			r_y++;
			if (judge_year(r_y))p = b;
			else p = a;
			r_d = 1;
			r_m = 1;
		}
	}
	printf("The date is %d-%d-%d \n\n",r_y,r_m,r_d);
}
int main() {
	int iYear, iMon, iDay, n;
	while (printf("Please input date:"), scanf("%d %d %d", &iYear, &iMon, &iDay)) {
		printf("Please input n:");
		scanf("%d", &n);
		conclude(iYear, iMon, iDay, n);
	}
	system("pause");
	return 0;
}