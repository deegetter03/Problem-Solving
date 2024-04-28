#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.,lc543
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int result = 0;
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);

        result = max(result, 1 + lh + rh);
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int data = height(root);
        return result - 1;
    }
};