#include "stu.h"
int main() {
	pStu plist, head = NULL, tail = NULL;
	FILE *fp = fopen("student.txt", "r+");
	FILE *out = fopen("liangdong.txt", "r+");
	int i;
	if (NULL == fp) {
		perror("fopen");
		goto end;
	}

	plist = (pStu)calloc(1, sizeof(Stu));
	while (fscanf(fp, "%d  %s  %c  %d  %d  %d", &plist->id, plist->name, &plist->sex, &plist->score[0], &plist->score[1], &plist->score[2])!=EOF){
		HeadInsert(&head, &tail, plist);
		memset(plist, 0, sizeof(Stu));
	}
	free(plist);
	
	pStu p[6],pn=head;
	for (i = 0; i < 6; i++)
	{
		p[i] = pn;
		pn = pn->next;
	}
	StuSort(0, 5, p);
	fseek(fp, 0, SEEK_SET);
	for (i = 0; i < 6; i++) {
		fprintf(out, "%d%s  %c  %d %d %d\n", p[i]->id, p[i]->name, p[i]->sex, p[i]->score[0], p[i]->score[1], p[i]->score[2]);
	}
	fclose(fp);
	fclose(out);
end:
	system("pause");
	return 0;
}