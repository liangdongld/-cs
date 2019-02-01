/*给出日期判断该日期周几 给出一个基址 计算输入的日期与基址相差多少天 用相差天数来计算星期几
1919-01-01 周三*/
#include <stdio.h>
#include<stdlib.h>
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
int conclude(int iYear_s, int iMonth_s, int iDay_s, int iYear_e, int iMonth_e, int iDay_e) {
	int s_day, e_day;
	s_day = day(iYear_s, iMonth_s, iDay_s);
	e_day = day(iYear_e, iMonth_e, iDay_e);
	int ret = year_conclusion(iYear_s, iYear_e) - s_day + e_day;
	return ret;
}

int main() {
	int year, mon, day;
	while (printf("Please input the date:"), scanf("%d%d%d", &year, &mon, &day)!=EOF) {
		int sum = conclude(1919, 1, 1,year, mon, day);
		int ret = (sum % 7 + 3) % 7;
		if (ret == 0)ret = 7;
		switch (ret)
		{
		case 1:printf("Monday\n"); break;
		case 2:printf("Tuesday\n"); break;
		case 3:printf("Wednesday\n"); break;
		case 4:printf("Thursday\n"); break;
		case 5:printf("Friday\n"); break;
		case 6:printf("Saturday\n"); break;
		case 7:printf("Sunday\n"); break;
		default:
			printf("error\n");
			break;
		}
	}
	system("pause");
	return 0;
}