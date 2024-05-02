#include <bits/stdc++.h>
using namespace std;

// Definition for binary tree
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode treenode;

treenode *treenode_new(int val)
{
    treenode *node = (treenode *)malloc(sizeof(treenode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(treenode *A, int B, int *arr, int *count)
{
    if (A == NULL) return 0;
    if (A->val == B)
    {
        arr[(*count)++] = A->val;
        return 1;
    }
    if (search(A->left, B, arr, count) == 1)
    {
        arr[(*count)++] = A->val;
        return 1;
    }
    if (search(A->right, B, arr, count) == 1)
    {
        arr[(*count)++] = A->val;
        return 1;
    }
    return 0;
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

/**
 * @input A : Root pointer of the tree
 * @input B : Integer
 *
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int *solve(treenode *A, int B, int *len1)
{
    int *arr = (int *)malloc(sizeof(int) * 100);
    int cnt = 0;
    search(A, B, arr, &cnt);
    int i;
    for (i = 0; i < (cnt / 2); i++)
        swap(&arr[i], &arr[cnt - 1 - i]);
    *len1 = cnt;
    return arr;
}