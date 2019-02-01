#include "stu.h"
void HeadInsert(pStu *head, pStu*tail, pStu pn) {
	int i;
	pStu pnew = (pStu)calloc(1, sizeof(Stu));
	pnew->id = pn->id;
	strcpy(pnew->name, pn->name);
	for (i = 0; i < 3; i++)pnew->score[i] = pn->score[i];
	if (NULL == *head&&NULL == *tail) {//若链表为空
		*head = pnew;
		*tail = pnew;
	}
	else {//若链表不为空
		pnew->next = *head;
		*head = pnew;
	}
}
void StuSort(int low, int high, pStu *p) {
	if (low > high)return;
	int i = low, j = high;
	pStu tp;
	tp = p[i];
	int tep = p[i]->score[0]+p[i]->score[1] + p[i]->score[2] ;
	while (i < j) {
		while (i < j&&tep > p[j]->score[0] + p[j]->score[1] + p[j]->score[2])j--;
		p[i] = p[j];
		while (i < j&&tep < p[i]->score[0] + p[i]->score[1] + p[i]->score[2])i++;
		p[j] = p[i];
	}
	p[i] = tp;
	StuSort(low, i - 1, p);
	StuSort(i + 1, high, p);
}