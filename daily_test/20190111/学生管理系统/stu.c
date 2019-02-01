#include "stu.h"
int Signin(pUSR_ACCOUNT a, pUSR_ACCOUNT test) {//登陆界面
	while (a != NULL) {
		if (strcmp(test->usr_name, a->usr_name) == 0) {
			if (strcmp(test->usr_pwd, a->usr_pwd) == 0)
				return a->usr_role;
			else {
				printf("The password is error\n");
				printf("请按任意键继续. . .");
				getchar();
				return -1;
			}
		}
		else {
					a = a->pNext_Usr_Account;
		}
	}
	printf("Can't find this user name!\n");
	printf("请按任意键继续. . .");
	getchar();
	return -1;
}
int print(int a) {
	int n;
	if (a == 1) {
		printf("\t/*************************************************************************************************/\n\
\t *******************************Student Information Management System*****************************\n\
\t/*************************************************************************************************/\n\
\t1.Search Student Information\n\
\t2.Add Student Information\n\
\t3.Updata Student Information\n\
\t4.Delete Student Information\n\
\t5.Add User account\n\
\t6.Update user account\n\
\t7.Delete user account\n\
\t8.Search user account\n\
\t9.Print all student information\n\
\t10.exit\n\
\t11.back to sign in\n");
		printf("\t-----------------------------------------------------------------------------------------------\n");
		scanf("%d", &n);
		return n;
	}
	else if (a == 0) {
		printf("\t/*************************************************************************************************/\n\
\t*************************************Student Information Management System**********************\n\
\t/*************************************************************************************************/\n\
\t1.Search Student Information\n\
\t10.exit\n\
\t11.back to sign in\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
	again:
		scanf("%d", &n);
		if(n==10||n==1||n==11)return n;
		else {
			printf("Wrong number , please input again!\n");
			goto again;
		}
	}
}

pUSR_INFOR Search_Student_Information(pUSR_INFOR p, int id) {//搜索学生信息
	pUSR_INFOR ppre = NULL;
	while (p != NULL) {
		if (p->usr_id == id) {
			printf("%d %s %.2lf %.2lf %.2lf\n", p->usr_id, p->usr_name, p->usr_course_score[0], p->usr_course_score[1], p->usr_course_score[2]);
			return ppre;
		}
		ppre = p;
		p = p->pNext_Usr_Infor;
	}
	printf("error\n");
}

void init_Student_Information(pUSR_INFOR *p, pUSR_INFOR *t, pUSR_INFOR pnew) {
	if (*p == NULL&&*t == NULL) {
		*p = pnew;
		*t = pnew;
	}
	else {
		(*t)->pNext_Usr_Infor = pnew;
		*t = pnew;
	}
}
void init_User_account(pUSR_ACCOUNT *p, pUSR_ACCOUNT *t, pUSR_ACCOUNT pnew) {
	if (*p == NULL&&*t == NULL) {
		*p = pnew;
		*t = pnew;
	}
	else {
		(*t)->pNext_Usr_Account = pnew;
		*t = pnew;
	}
}
void Add_Student_Information(pUSR_INFOR *p,pUSR_INFOR *t) {//增加用户信息
	pUSR_INFOR pnew = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
	printf("Please input user id: ");
	scanf("%d", &pnew->usr_id);
	printf("Please input user name: ");
	scanf("%s", pnew->usr_name);
	printf("Please input first course score: ");
	scanf("%lf", &pnew->usr_course_score[0]);
	printf("Please input second course score: ");
	scanf("%lf", &pnew->usr_course_score[1]);
	printf("Please input three course score: ");
	scanf("%lf", &pnew->usr_course_score[2]);
	if (*p == NULL&&*t==NULL) {
		*p = pnew;
		*t = pnew;
	}
	else {
		(*t)->pNext_Usr_Infor= pnew;
		*t = pnew;
	}
}

void Updata_Student_information(pUSR_INFOR p, int id) {//修改学生信息
	pUSR_INFOR pre = Search_Student_Information(p, id);
	if (pre != NULL)p = pre->pNext_Usr_Infor;
	pUSR_INFOR pnew = (pUSR_INFOR)calloc(1,sizeof(USR_INFOR));
	printf("Please input user id: ");
	scanf("%d", &p->usr_id);
	printf("Please input user name: ");
	scanf("%s", p->usr_name);
	printf("Please input first course score: ");
	scanf("%lf", &p->usr_course_score[0]);
	printf("Please input second course score: ");
	scanf("%lf", &p->usr_course_score[1]);
	printf("Please input three course score: ");
	scanf("%lf", &p->usr_course_score[2]);

	printf("%d %s %lf %lf %lf\n", p->usr_id, p->usr_name, p->usr_course_score[0], p->usr_course_score[1], p->usr_course_score[2]);
}

void Delete_Student_Information(pUSR_INFOR *p, int id) {//删除
	pUSR_INFOR pre = Search_Student_Information(*p, id);
	if (NULL == pre) {
		pre = *p;
		*p = (*p)->pNext_Usr_Infor;
		free(p);
	}
	else {
		pUSR_INFOR tmp = pre->pNext_Usr_Infor;
		pre->pNext_Usr_Infor = tmp->pNext_Usr_Infor;
		free(tmp);
	}
}

void Add_User_account(pUSR_ACCOUNT *p, pUSR_ACCOUNT *t) {//增加用户账户
	pUSR_ACCOUNT pnew = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
	printf("Please input user name:");
	scanf("%s", pnew->usr_name);
	printf("Please input password:");
	int i = 0;
	while (1) {
		int ch = getch();
		if (ch == '#')ch = '\r';
		if (ch == '\r')break;
		if (ch == '\b') {
			if (i <= 0)continue;
			printf("\b \b");
			pnew->usr_pwd[--i] = '\0';
			continue;
		}
		pnew->usr_pwd[i] = ch;
		printf("*");
		i++;
	}
	printf("\nPlease input user role.\n1.Common student \n2.Management\n");
	scanf("%d", &i);
	pnew->usr_role = i - 1;
	if (*p == NULL) {
		*p = pnew;
		*t = pnew;
	}
	else {
		(*t)->pNext_Usr_Account = pnew;
		*t = pnew;
	}
}
int Update_user_account(pUSR_ACCOUNT p, char *name) {//更新学生账户
	int i = 0;
	char password[20] = { 0 };
	while (p != NULL) {
		if (strcmp(p->usr_name, name) == 0) {
		input_password:
			memset(password, 0, sizeof(password));
			printf("Please input password : ");
			while (1) {
				int ch = getch();
				if (ch == '#')ch = '\r';
				if (ch == '\r')break;
				if (ch == '\b') {
					if (i <= 0)continue;
					printf("\b \b");
					password[--i] = '\0';
					continue;
				}
				password[i] = ch;
				printf("*");
				i++;
			}
			printf("\n");
			if (0 == strcmp(p->usr_pwd, password))break;
			else {
				printf("Error : the password is wrong ! \n");
				goto input_password;
			}
		}
		p = p->pNext_Usr_Account;
	}
	if (p == NULL) {
		printf("Error : can't found this user name!\n");
		return -1;
	}
	printf("Please input new user name:");
	scanf("%s", p->usr_name);
	printf("Please input new password:");
	i = 0;
	while (1) {
		int ch = getch();
		if (ch == '#')ch = '\r';
		if (ch == '\r')break;
		if (ch == '\b') {
			if (i <= 0)continue;
			printf("\b \b");
			p->usr_pwd[--i] = '\0';
			continue;
		}
		p->usr_pwd[i] = ch;
		printf("*");
		i++;
	}
	printf("\n");
	printf("Please input user role.\n\t1.Common student \n\t2.Management\n");
	scanf("%d", &i);
	p->usr_role = i - 1;
	return 1;
}
void Delete_user_account(pUSR_ACCOUNT *p, char *name) {//删除学生账户
	pUSR_ACCOUNT ppre = NULL;
	pUSR_ACCOUNT tmp = *p;
	while (NULL != tmp) {
		if (strcmp(tmp->usr_name, name) != NULL) {
			ppre = tmp;
			tmp = tmp->pNext_Usr_Account;
		}
		else {
			if (NULL == ppre) {
				ppre = *p;
				*p = (*p)->pNext_Usr_Account;
				free(ppre);
			}
			else {
				ppre->pNext_Usr_Account = tmp->pNext_Usr_Account;
				free(tmp);
				return;
			}
		}
	}
	printf("Error\n");
	return;
}

pUSR_ACCOUNT Search_user_account(pUSR_ACCOUNT p,char *name){//查找账户
	while (p) {
		if (strcmp(p->usr_name, name) != 0) {
			p = p->pNext_Usr_Account;
		}
		else {
			printf("Name: %s   role:%d\n", p->usr_name, p->usr_role);
			return p;
		}
	}
	printf("Error\n");
}

void printAllInform(pUSR_INFOR p) {
	while (p) {
		printf("%d %s %.2lf %.2lf %.2lf\n", p->usr_id, p->usr_name, p->usr_course_score[0], p->usr_course_score[1], p->usr_course_score[2]);
		p = p->pNext_Usr_Infor;
	}
}