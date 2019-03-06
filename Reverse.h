#pragma once

/*
	数据结构复习
	课堂上需要手写的代码进行复习，能够熟练的进行手写
	对代码的思路和方法熟记于心
*/

#include <stdlib.h>

// 线性表(数组)
typedef struct {
	int array[100];
	int size;
} SeqList;
// 头插
void SeqListPushFront(SeqList *sl, int val);
// 练习
// 中间插入与中间删除
void SeqListInsert(SeqList *sl, int val, int pos);
void SeqListErase(SeqList *sl, int pos);

// 链表（单向+不带头+不循环）
typedef struct Node{
	int val;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
}List;
// 链表逆置（1.三指针遍历 2.头删+头插）
Node* DListReverse_1(List *list);
Node* DListReverse_2(List *list);

// 树（二叉树）
// 二叉树的应用多使用递归实现，需要注意空树情况以及递归的终止条件（及其重要）
typedef struct TreeNode{
	int val;
	struct Node *left;
	struct Node *right;
} TreeNode;
// 遍历方式：前（根 左 右）| 中（左 根 右）| 后（左 右 根）
void PreOderTraval(TreeNode *root);
// 求树的高度
int GetHeight(TreeNode *root);
// 二叉树的查找（默认二叉树中无相同Val结点）；
// 先判断根节点，再左子树，后右子树。找到返回结点地址，找不到返回NULL；
TreeNode *Find(TreeNode *root, int val);

