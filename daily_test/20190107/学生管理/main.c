#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int id;
	char name[20];
	int score[3];
}Student;
void print(Student test[]) {
	int i;
	printf("---------------------------------------------------------------\n");
	printf("ѧ��\t����\t\t��Ŀһ\t��Ŀ��\t��Ŀ��\t�ܷ�\n");
	for (i = 0; i < 5; i++) {
		printf("%d  %s     \t%3d\t%3d\t%3d\t%3d\n", test[i].id, test[i].name, test[i].score[0], test[i].score[1], test[i].score[2], test[i].score[0] + test[i].score[1] + test[i].score[2]);
	}
	printf("---------------------------------------------------------------\n");
}
void print_Onestudent(Student test[], int i) {
	printf("%d  %s     \t%3d\t%3d\t%3d\t%3d\n", test[i].id, test[i].name, test[i].score[0], test[i].score[1], test[i].score[2], test[i].score[0] + test[i].score[1] + test[i].score[2]);
}
int Sum(Student *test) {
	return test->score[0] + test->score[1] + test->score[2];
}
void print_Max(Student test[]) {
	int i, j, max = 0;
	int flag;
	for (i = 0; i < 3; i++) {
		max = 0;
		for (j = 0; j < 5; j++) {
			if (test[j].score[i]>max) {
				max = test[j].score[i];
				flag = j;
			}
		}

		printf("��Ŀ %d ��߷֣�\n", i + 1);
		print_Onestudent(test, flag);
	}
}
void print_avergae(Student test[]) {
	int i, j;
	float sum;
	for (i = 0; i < 3; i++) {
		sum = 0;
		for (j = 0; j < 5; j++) {
			sum += test[j].score[i];
		}
		sum /= 5.0;
		printf("��Ŀ %d ƽ����Ϊ��%.2f\n", i + 1, sum);
	}
}
void print_rank(Student test[]) {
	Student *p[5], *p1;
	int i, j;
	for (i = 0; i < 5; i++)p[i] = &test[i];
	for (i = 0; i < 5; i++)
		for (j = 0; j < 4; j++) {
			if (Sum(p[j])<Sum(p[j + 1])) {
				p1 = p[j];
				p[j] = p[j + 1];
				p[j + 1] = p1;
			}
		}
	for (i = 0; i < 5; i++) {
		printf("%d  %s     \t%3d\t%3d\t%3d\t%3d\n", p[i]->id, p[i]->name, p[i]->score[0], p[i]->score[1], p[i]->score[2], p[i]->score[0] + p[i]->score[1] + p[i]->score[2]);
	}
}
int main() {
	/*Student test[5] = { 1001, "George Washington",100,99,98 ,1002, "Thomas Jefferson",88,92,94 ,1003, "Abraham Lincoln",94,92,94 ,1004, "Dwight David Eisenhower",96,100,87 ,1005, "Donald John Trump",48,72,84 };*/
	Student test[5];
	int i;
	for (i = 0; i < 5; i++) {
		scanf("%d%s%d%d%d", &test[i].id, test[i].name, &test[i].score[0], &test[i].score[1], &test[i].score[2]);
	}
	system("cls");
	print(test); //��ӡ��Ϣ
	print_Max(test);
	printf("---------------------------------------------------------------\n");
	print_avergae(test);
	printf("---------------------------------------------------------------\n");
	printf("�ܷ�����:\n\n");
	print_rank(test);
	printf("\n\n");
	return 0;
}
