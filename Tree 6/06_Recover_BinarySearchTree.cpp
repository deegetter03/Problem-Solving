#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.lc99
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *first = NULL, *second = NULL, *prev = new TreeNode(INT_MIN);
    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        if (prev->val > root->val) {
            if (first == NULL){
                first = prev;
            }
            second = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};