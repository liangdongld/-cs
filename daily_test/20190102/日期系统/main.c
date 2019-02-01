#include <stdio.h>
#include "conclude.h"
#include <stdio.h>
#include <stdbool.h>
bool judge_year(int a) {
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)return true;
	return false;
}
int day_c(int year, int month, int day) {//判断日期是今年第几天
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
int conclude(int iYear_s, int iMonth_s, int iDay_s, int iYear_e, int iMonth_e, int iDay_e) {//判断两日期相差天数
	int s_day, e_day;
	s_day = day_c(iYear_s, iMonth_s, iDay_s);
	e_day = day_c(iYear_e, iMonth_e, iDay_e);
	int ret = year_conclusion(iYear_s, iYear_e) - s_day + e_day;
	return ret;
}

int judge_date(int year, int mon, int day) {//判断周几
	int sum = conclude(1919, 1, 1, year, mon, day);
	int ret = (sum % 7 + 3) % 7;
	if (ret == 0)ret = 7;
	return ret;
}

void conclude_date(int year, int mon, int day, int n) {//判断某日期后的第n天日期
	int a[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int b[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int *p;
	int r_y = year, r_m = mon, r_d = day;
	if (judge_year(r_y))p = b;
	else p = a;
	for (int i = 0; i < n; i++) {
		if (r_d + 1 <= *(p + r_m - 1)) {
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
	printf("\n%d年%d月%d日 之后的 %d 天是 %d年%d月%d日 \n\n", year, mon, day, n, r_y, r_m, r_d);
	return;
}

void printMenu() {//打印菜单
	int n;
	printf("\n\n|-----------------------------------日期系统-----------------------------\n");
	printf("|我们会提供如下功能：\n");
	printf("|\t1.判断某个时期是周几\n");
	printf("|\t2.计算两个日期之间相差的时间\n");
	printf("|\t3.某个日期第n天之后的日期\n");
	printf("|\t4.计算某个日期是那年的第几天\n");
	printf("|\t5.输出某年某月的日历\n");
	printf("|\t6.退出\n");
	printf("|---------------------------------------------------------------------------\n");
	printf("\n");
}
void one(int year, int mon, int day) {//判断周几
	int a = judge_date(year, mon, day);
	printf("\n%d 年 %d 月 %d 日 是 星期 %d \n\n", year, mon, day, a);
}
void two(int iYear_s, int iMonth_s, int iDay_s, int iYear_e, int iMonth_e, int iDay_e) {
	int a = conclude(iYear_s, iMonth_s, iDay_s, iYear_e, iMonth_e, iDay_e);
	printf("\n%d 年 %d 月 %d 日 到 %d 年 %d 月 %d 日 一共 %d 天\n\n", iYear_s, iMonth_s, iDay_s, iYear_e, iMonth_e, iDay_e, a);
}
void three(int year, int mon, int day, int n) {
	conclude_date(year, mon, day, n);
}
void four(int year, int mon, int day) {
	int a = day_c(year, mon, day);
	printf("\n%d 年 %d 月 %d 日 是 %d 年的第 %d 天\n\n", year, mon, day, year, a);
}

int judge_month_num(int year, int mon) {
	int a[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (judge_year(year) == true && mon == 2)return 29;
	else return a[mon - 1];
}
int print_month(int iYear, int iMon) {
	printf("\n%d 年 %d 月的日历为：\n\n",iYear,iMon);
	int count = 0;
	int ret = judge_date(iYear, iMon, 1);
	printf("\n\t一\t二\t三\t四\t五\t六\t日\n\n");
	for (int i = 0; i < ret - 1; i++) {
		printf("\t");
		count++;
	}
	for (int i = 0; i < judge_month_num(iYear, iMon); i++, count++) {
		if (count % 7 == 0 && i != 0)printf("\n\n");
		printf("\t%d", i + 1);
	}
	printf("\n\n\n");
}
int main() {
	int n;
	int iYear_s, iMonth_s, iDay_s;
	int iYear_e, iMonth_e, iDay_e;
	int a;
	printMenu();
	while (1) {
		printf("请输入你想使用的功能：");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("\n请输入年月日：");
			scanf("%d%d%d", &iYear_s, &iMonth_s, &iDay_s);
			one(iYear_s, iMonth_s, iDay_s);
			break;
		case 2:
			printf("\n请分别输入第一个年月日：");
			scanf("%d %d %d", &iYear_s, &iMonth_s, &iDay_s);
			printf("请分别输入第二个年月日：");
			scanf("%d %d %d", &iYear_e, &iMonth_e, &iDay_e);
			two(iYear_s, iMonth_s, iDay_s, iYear_e, iMonth_e, iDay_e);
			break;
		case 3:
			printf("\n请输入年月日：");
			scanf("%d %d %d", &iYear_s, &iMonth_s, &iDay_s);
			printf("请输入在 %d 年 %d 月 %d 日之后的天数：", iYear_s,iMonth_s,iDay_s);
			scanf("%d", &a);
			three(iYear_s, iMonth_s, iDay_s, a);
			break;
		case 4:
			printf("\n请输入年月日：");
			scanf("%d%d%d", &iYear_s, &iMonth_s, &iDay_s);
			four(iYear_s, iMonth_s, iDay_s);
			break;
		case 5:
			printf("请输入目标日历的年月：");
			scanf("%d %d", &iYear_s, &iMonth_s);
			print_month(iYear_s, iMonth_s);
			break;
		case 6:
			printf("\n感谢您的使用!\n\n");
			return 0;
		default:
			printf("请输入合法数字！\n\n");
			break;
		}
	}
}