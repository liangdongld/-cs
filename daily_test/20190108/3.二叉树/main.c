/*�������������裺
	1.�����������ڵ������������ֵ
	2.�������нڵ㽫�µĶ������ڵ�ѹ�����
	3.������ͷָ��ָ��ڵ����������ָ���´����Ľڵ�
	4.������ͷָ��ָ��ڵ��������ָ����ָ���½ڵ㣬�����
*/
#include "BTree.h"
int main() {
	pNode Tree=NULL, pNew;
	pQue front = NULL, rear = NULL, pQueNew, pcur;
	int i, j;
	int key;
	while (scanf("%d", &key) != EOF) {
		if (key == -1)break;
		pNew = (pNode)calloc(1, sizeof(Node));
		pNew->val = key;
		pQueNew = (pQue)calloc(1, sizeof(Que));
		pQueNew->InsertPos = pNew;
		if (NULL == Tree) {
			Tree = pNew;
			front = pQueNew;
			rear = pQueNew;
		}
		else {
			rear->next = pQueNew;
			rear = pQueNew;
			if (NULL == front->InsertPos->left) {
				front->InsertPos->left = pNew;
			}
			else if (NULL == front->InsertPos->right) {
				front->InsertPos->right = pNew;
				pcur = front;
				front = front->next;
				free(pcur);
				pcur = NULL;
			}
		}
	}
	printf("�������\n");
	preOrder(Tree);
	printf("\n�������\n");
	midOrder(Tree);
	printf("\n�������\n");
	latOrder(Tree);
	printf("\n");
	system("pause");

}