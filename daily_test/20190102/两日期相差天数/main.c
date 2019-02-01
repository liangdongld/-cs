#include <stdio.h>
#include <stdbool.h>
bool judge_year(int a) {
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)return true;
	return false;
}
int day(int year, int month, int day) {
	int a[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int ret = 0;
	for (int i = 0; i < month - 1; i++)ret += a[i];
	ret += day;
	if (judge_year(year) && month > 2)ret += 1;
	return ret;
}
int year_conclusion(int a, int b) {
	int sum = (b - a) * 365;
	for (int i = a; i < b; i++) {
		sum = sum + (i % 4 == 0 && i / 100 != 0 || i % 400 == 0);
	}
	return sum;
}
int main() {
	int iYear_s, iMonth_s, iDay_s;
	int iYear_e, iMonth_e, iDay_e;
	int s_day, e_day;
	while (printf("Please input the start date:"), scanf("%d %d %d", &iYear_s, &iMonth_s, &iDay_s) != EOF) {
		printf("Please input the end date:");
		scanf("%d %d %d", &iYear_e, &iMonth_e, &iDay_e);
		printf("%d-%02d-%02d to %d-%02d-%02d ", iYear_s, iMonth_s, iDay_s, iYear_e, iMonth_e, iDay_e);
		s_day = day(iYear_s, iMonth_s, iDay_s);
		e_day = day(iYear_e, iMonth_e, iDay_e);
		int ret = year_conclusion(iYear_s, iYear_e) - s_day + e_day;
		printf("is %d days\n", ret);
	}
	system("pause");
	return 0;
}