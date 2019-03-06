
#include "Reverse.h"

void SeqListPushFront(SeqList *sl, int val) {
	for (int i = sl->size - 1; i >= 0 ; i--)
	{
		sl->array[i + 1] = sl->array[i];
	}
	sl->array[0] = val;
	sl->size++;
}

void SeqListInsert(SeqList *sl, int val, int pos) {
	for (int i = sl->size - 1; i >= pos ; i--)
	{
		sl->array[i + 1] = sl->array[i];
	}
	sl->array[pos] = val;
	sl->size++;
}

void SeqListErase(SeqList *sl, int pos) {
	for (int i = pos; i < sl->size; i++)
	{
		sl->array[i] = sl->array[i + 1];
	}
	sl->size--;
}

// 三指针遍历法
Node* DListReverse_1(List *list) {
	if (list->head == NULL)
	{
		return NULL;
	}
	Node *p1 = NULL;
	Node *p2 = list->head;
	Node *p3 = list->head->next;
	while (p2 != NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		if (p3 != NULL)
		{
			p3 = p3->next;
		}
	}
	return p1;
}
// 头删+头插
Node* DListReverse_2(List *list) {
	Node *c = list->head;
	Node *next;
	Node *newHead = NULL;

	while (c != NULL)
	{
		next = c->next;
		c->next = newHead;
		newHead = c;
		c = next;
	}
	return newHead;
}
// 前序遍历
void PreOderTraval(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	printf("%d ", root->val);
	PreOderTraval(root->left);
	PreOderTraval(root->right);
	return;
}
// 求树的高度
int GetHeight(TreeNode *root) {
	if (root == NULL)
	{
		return 0;
	}
	int left = GetHeight(root->left);
	int right = GetHeight(root->right);
	return left > right ? left + 1 : right + 1;
}
// 二叉树的查找
TreeNode *Find(TreeNode *root, int val) {
	if (root == NULL)
	{
		return NULL;
	}
	if (root->val == val)
	{
		return root;
	}
	TreeNode *Back = Find(root->left, val);
	if (Back == NULL)
	{
		return Find(root->right, val);
	}
	return Back;
}