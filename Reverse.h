#pragma once

/*
	���ݽṹ��ϰ
	��������Ҫ��д�Ĵ�����и�ϰ���ܹ������Ľ�����д
	�Դ����˼·�ͷ����������
*/

#include <stdlib.h>

// ���Ա�(����)
typedef struct {
	int array[100];
	int size;
} SeqList;
// ͷ��
void SeqListPushFront(SeqList *sl, int val);
// ��ϰ
// �м�������м�ɾ��
void SeqListInsert(SeqList *sl, int val, int pos);
void SeqListErase(SeqList *sl, int pos);

// ��������+����ͷ+��ѭ����
typedef struct Node{
	int val;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
}List;
// �������ã�1.��ָ����� 2.ͷɾ+ͷ�壩
Node* DListReverse_1(List *list);
Node* DListReverse_2(List *list);

// ������������
// ��������Ӧ�ö�ʹ�õݹ�ʵ�֣���Ҫע���������Լ��ݹ����ֹ������������Ҫ��
typedef struct TreeNode{
	int val;
	struct Node *left;
	struct Node *right;
} TreeNode;
// ������ʽ��ǰ���� �� �ң�| �У��� �� �ң�| ���� �� ����
void PreOderTraval(TreeNode *root);
// �����ĸ߶�
int GetHeight(TreeNode *root);
// �������Ĳ��ң�Ĭ�϶�����������ͬVal��㣩��
// ���жϸ��ڵ㣬���������������������ҵ����ؽ���ַ���Ҳ�������NULL��
TreeNode *Find(TreeNode *root, int val);

