#include "stu.h"

int main() {
	int i,j;
	FILE *configure = fopen("configure.txt", "r");
	char ac[20], inf[20];
	fscanf(configure, "%s", ac);
	fscanf(configure, "%s", inf);
	FILE *faccount = fopen(ac, "r+");
	if (faccount ==NULL) {
		perror("fopen");
	}
	pUSR_ACCOUNT ahead = NULL;
	pUSR_ACCOUNT atail = NULL;
	pUSR_ACCOUNT anew = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
	while (fscanf(faccount,"%s %d %s", anew->usr_name, &anew->usr_role, anew->usr_pwd) != EOF) {
		init_User_account(&ahead, &atail, anew);
		anew = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
	}

	FILE *finform = fopen(inf, "r+");
	if (finform == NULL) {
		perror("fopen");
	}
	pUSR_INFOR fhead = NULL;
	pUSR_INFOR ftail = NULL;
	pUSR_INFOR fnew = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
	while (fscanf(finform, "%d %s %lf %lf %lf", &fnew->usr_id, fnew->usr_name, &fnew->usr_course_score[0], &fnew->usr_course_score[1], &fnew->usr_course_score[2])!=EOF) {
		init_Student_Information(&fhead, &ftail, fnew);
		fnew = (pUSR_INFOR)calloc(1, sizeof(USR_INFOR));
	}
	int choice, id;
	char name[20];
	pUSR_INFOR temp = NULL;
	pUSR_ACCOUNT pnew;
signin:
	pnew = (pUSR_ACCOUNT)calloc(1, sizeof(USR_ACCOUNT));
	system("cls");
	printf("Please input username:");
	scanf("%s", pnew->usr_name);
	rewind(stdin);
	printf("Please input password:");
	i = 0; 
	j = 0;
	while(1){
		int ch = getch();
		if (ch == '#')ch = '\r';
		if (ch == '\r')break;
		if (ch == '\b') {
			if (i <= 0)continue;
			printf("\b \b");
			pnew->usr_pwd[--i] = '\0';
			if (i < 0)i = 0;
			continue;
		}
		pnew->usr_pwd[i] = ch;
		printf("*");
		i++;
		j = 0;
	}
	printf("\n");
	rewind(stdin);
	int rola = Signin(ahead, pnew);
	if (rola == -1)goto signin;
	free(pnew);
action:
	system("cls");
	choice = print(rola);
	switch (choice)
	{
	case 1:
		printf("Please in put the id of the student :");
		scanf("%d", &id);
		Search_Student_Information(fhead, id);
		rewind(stdin);
		printf("请按任意键继续. . .");
		getchar();
		goto action;
		break;
	case 2://需要改文件
		Add_Student_Information(&fhead,&ftail);
		fseek(finform, 0, SEEK_END);
		fprintf(finform, "%d  %s  %.2lf  %.2lf  %.2lf\n", ftail->usr_id, ftail->usr_name, ftail->usr_course_score[0], ftail->usr_course_score[1], ftail->usr_course_score[2]);
		rewind(stdin);
		printf("请按任意键继续. . .");
		getchar();
		goto action;
		break;
	case 3://需要改文件
		printf("Which student's information do you want to update? Please input his/her id：");
		scanf("%d", &id);
		Updata_Student_information(fhead,id);
		temp = fhead;
		fseek(finform, 0, SEEK_SET);
		while (temp!=NULL) {
			fprintf(finform,"%d  %s  %.2lf  %.2lf  %.2lf\n", temp->usr_id, temp->usr_name, temp->usr_course_score[0], temp->usr_course_score[1], temp->usr_course_score[2]);
			temp = temp->pNext_Usr_Infor;
		}
		rewind(stdin);
		printf("请按任意键继续. . .");
		getchar();
		goto action;
		break;
	case 4://删除学生信息
		scanf("%d", &id);
		Delete_Student_Information(&fhead, id);
		temp = fhead;
		fclose(finform);
		finform = fopen("information.txt", "w+");
		while (temp != NULL) {
			fprintf(finform, "%d  %s  %.2lf  %.2lf  %.2lf\n", temp->usr_id, temp->usr_name, temp->usr_course_score[0], temp->usr_course_score[1], temp->usr_course_score[2]);
			temp = temp->pNext_Usr_Infor;
		}
		rewind(stdin);
		printf("请按任意键继续. . .");
		getchar();
		goto action;
		break;
	case 5://增加用户账户
		Add_User_account(&ahead, &atail);
		fseek(faccount, 0, SEEK_END);
		fprintf(faccount, "%s %d %s\n", atail->usr_name, atail->usr_role, atail->usr_pwd);
		rewind(stdin);
		printf("请按任意键继续. . .");
		getchar();
		goto action;
		break;
	case 6://更新信息
		printf("Please input old user name : ");
		scanf("%s", name);
		if (-1 == Update_user_account(ahead, name)) {
			rewind(stdin);
			printf("请按任意键继续. . .");
			getchar();
			goto action;
		}
		rewind(stdin);
		printf("请按任意键继续. . .");
		getchar();
		fclose(faccount);
		faccount = fopen("account.txt", "w+");
		pnew = ahead;
		while (pnew != NULL) {
			fprintf(faccount, "%s %d %s\n", pnew->usr_name, pnew->usr_role, pnew->usr_pwd);
			pnew = pnew->pNext_Usr_Account;
		}
		goto action;
		break;
	case 7:
		printf("Which user do you want to delete？  ");
		scanf("%s", name);
		Delete_user_account(&ahead, name);
		fclose(faccount);
		fopen("account.txt", "w+");
		anew = ahead;
		while (NULL != anew) {
			fprintf(faccount,"%s %d %s\n", anew->usr_name, anew->usr_role, anew->usr_pwd);
			anew = anew->pNext_Usr_Account;
		}
		rewind(stdin);
		printf("请按任意键继续. . .");
		getchar();
		goto action;
		break;
	case 8:
		printf("Please input user name : ");
		scanf("%s", name);
		Search_user_account(ahead, name);
		rewind(stdin);
		printf("请按任意键继续. . .");
		getchar();
		goto action;
		break;
	case 9:
		printAllInform(fhead);
		rewind(stdin);
		printf("请按任意键继续. . .");
		getchar();
		goto action;
	case 10:
		goto end;
	case 11:
		goto signin;
	default:
		goto action;
		break;
	}
end:
	fclose(faccount);
	fclose(finform);
	return 0;
}