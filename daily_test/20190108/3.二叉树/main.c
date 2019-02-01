/*创建二叉树步骤：
	1.创建二叉树节点来保存输入的值
	2.创建队列节点将新的二叉树节点压入队列
	3.将队列头指针指向节点的左右子树指针新创建的节点
	4.若队列头指针指向节点的右子树指针以指向新节点，则出队
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
	printf("先序遍历\n");
	preOrder(Tree);
	printf("\n中序遍历\n");
	midOrder(Tree);
	printf("\n后序遍历\n");
	latOrder(Tree);
	printf("\n");
	system("pause");

}