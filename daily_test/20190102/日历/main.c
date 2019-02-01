#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
bool judge_year(int a) {
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)return true;
	return false;
}
int year_conclusion(int a, int b) {
	int sum = (b - a) * 365;
	for (int i = a; i < b; i++) {
		sum = sum + (i % 4 == 0 && i / 100 != 0 || i % 400 == 0);
	}
	return sum;
}
int conclude(int iYear_s, int iMonth_s, int iDay_s, int iYear_e, int iMonth_e, int iDay_e) {//判断两日期相差天数
	int s_day, e_day;
	s_day = day_c(iYear_s, iMonth_s, iDay_s);
	e_day = day_c(iYear_e, iMonth_e, iDay_e);
	int ret = year_conclusion(iYear_s, iYear_e) - s_day + e_day;
	return ret;
}
int day_c(int year, int month, int day) {//判断日期是今年第几天
	int a[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int ret = 0;
	for (int i = 0; i < month - 1; i++)ret += a[i];
	ret += day;
	if (judge_year(year) && month > 2)ret += 1;
	return ret;
}
int judge_date(int year, int mon, int day) {//判断周几
	int sum = conclude(1919, 1, 1, year, mon, day);
	int ret = (sum % 7 + 3) % 7;
	if (ret == 0)ret = 7;
	return ret;
}
int judge_month_num(int year, int mon) {
	int a[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (judge_year(year) == true && mon == 2)return 29;
	else return a[mon - 1];
}
int main() {
	int iYear, iMon;
	int count = 0;
	printf("请输入目标日历的年：\n");
	scanf("%d", &iYear);
	iMon = 1;
	while (iMon<=12) {
		count = 0;
		int ret = judge_date(iYear, iMon, 1);
		printf("\t\t\t\t%d月日历\n\n",iMon);
		printf("\t一\t二\t三\t四\t五\t六\t日\n\n");
		for (int i = 0; i < ret - 1; i++) {
			printf("\t");
			count++;
		}
		for (int i = 0; i < judge_month_num(iYear, iMon); i++, count++) {
			if (count % 7 == 0 && i != 0)printf("\n\n");
			printf("\t%d", i + 1);
		}

		printf("\n\n\n");
		iMon++;
	}
	system("pause");
	return 0;
}