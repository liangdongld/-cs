#include "BTree.h"
void preOrder(pNode t) {
	if (t) {
		printf("%d ", t->val);
		preOrder(t->left);
		preOrder(t->right);
	}
}
void midOrder(pNode t) {
	if (t) {
		midOrder(t->left);
		printf("%d ", t->val);
		midOrder(t->right);
	}
}
void latOrder(pNode t) {
	if (t) {
		latOrder(t->left);
		latOrder(t->right);
		printf("%d ", t->val);
	}
}